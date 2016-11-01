#include "RPhi_analysis.h"

int main(int argc, char* argv[])
{
    //argv[1] = rootfile input
    //argv[2] = second chamber present
    //argv[3] = config of apv to physical connector chamber 1
    //argv[4] = config of apv to physical connector chamber 2
    //

    TBenchmark *bench = new TBenchmark();
    bench->Start("full");

    double apv_thresholds[5] = {50,60,60,60,50};
    int connector_of_apv[5];
    for(int i = 0 ; i < 5 ; i++)
    {
        connector_of_apv[i]= ( atoi(argv[3]) / (int)TMath::Power(10, 4-i) ) % 10 ;
        cout << connector_of_apv[i] << endl;
    }
    int second_chamber_present = atoi(argv[2]);
    int n_chambers = 1 + second_chamber_present;
    int no_of_apvs = 5 + 5*second_chamber_present;
    int v0 = 0; //v for verbosity (level 0)
    int v1 = 0; //v for verbosity (level 1)

//    TH1D *hist_vpeak[no_of_apvs];
//    Generate_Hists_Vpeak(hist_vpeak, 0); //hist_generator.h

//    TH1D *hist_qpeak[no_of_apvs];
//    Generate_Hists_Qpeak(hist_qpeak, 0);

    Histograms *hists = new Histograms(1);
//    TCanvas c1;
//    hists->GetQmax(0)->Draw("hist");
//    c1.SaveAs("yohist.png");

    cin.get();
    cout << "Number of chambers detected: " << n_chambers << endl;

    int apv_config[n_chambers];
    for(int k = 0; k < n_chambers ; k++)
    {
        apv_config[k]=atoi(argv[3+k]);
    }
    int strip_of_channel[128*no_of_apvs];
    map_channels(strip_of_channel, apv_config, second_chamber_present); //channels_map.h

    TFile *root_file = new TFile(argv[1],"READ");
    raw *raw_tree = new raw((TTree*)root_file->Get("raw")); //raw.h
    data *data_tree = new data((TTree*)root_file->Get("data")); //data.h

    int nentries = (raw_tree->fChain)->GetEntries(); 
    cout <<"Number of entries detected: " <<  nentries << endl;

    int counters[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < nentries; i++)
    {
        cout << "Event #" << i << endl;
        raw_tree->GetEntry(i);
        data_tree->GetEntry(i);

        int n_empty_hits = 0;
        int n_apv_hits[5] = {0, 0, 0, 0, 0};
        int n_apv_empty_hits[5] = {0, 0, 0, 0, 0};
        int empty_mean_apv[5] = {0, 0, 0, 0, 0};
        int empty_rms_apv[5] = {0, 0, 0, 0, 0};
        int empty_mean_hits = 0;
        int empty_rms_hits = 0;

        vector<vector<int>> *r_clusters_hit_id = new vector<vector<int>>();        
        vector<vector<int>> *r_clusters_strip_id = new vector<vector<int>>();        
        vector<int> *good_hits_id = new vector<int>();

        int n_hits = raw_tree->apv_q->size();
        if(v0) cout << "Number of hits detected: " << n_hits << endl;

        for( int hit = 0; hit < n_hits ; hit++ )        
        {
            if(v1) cout << "Proccessing hit: " << hit << endl;
            double charge[27];
            for( int j = 0 ; j < 27 ; j++ )
            {
                charge[j]=raw_tree->apv_q->at(hit).at(j);
                if(v1) cout << "\t" << j << "\t" << charge[j] << endl;
            }
            double qmax = (double) data_tree->apv_qmax->at(hit);
            int index_max = (int) data_tree->apv_tbqmax->at(hit);

            int APV_channel = raw_tree->apv_ch->at(hit); 
            int APV_id = raw_tree->apv_id->at(hit); 

            if(v0) cout << "max is " << qmax << " at " << index_max << endl;

            int index_LE = find_crossing_index(charge, index_max, -1, 0.);  //event_function.h
            int index_TE = find_crossing_index(charge, index_max, +1, 0.) -1; //event_function.h
            int index_40 = find_crossing_index(charge, index_max, -1, 0.4); //event_function.h
            double total_charge = charge_sum(charge);

            double time_LE = linear_interp(0, 25*index_LE-12.5, charge[index_LE], 25*(index_LE+1)-12.5, charge[index_LE+1]);
            double time_TE = linear_interp(0, 25*index_TE-12.5, charge[index_TE], 25*(index_TE+1)-12.5, charge[index_TE+1]);
            double time_40 = linear_interp(0.4*qmax, 25*index_40-12.5, charge[index_40], 25*(index_40+1)-12.5, charge[index_40+1]);

            n_apv_hits[APV_id]++;
            if( strip_of_channel[APV_channel+128*APV_id] == -1)
            {
                double charge_square = charge_sum_square(charge);
                n_empty_hits++;
                n_apv_empty_hits[APV_id]++;
                empty_mean_apv[APV_id]+= total_charge/27.;
                empty_rms_apv[APV_id] += charge_square/27.;
                empty_mean_hits += total_charge/27.;
                empty_rms_hits += charge_square/27.;
            }

            if(qmax > apv_thresholds[connector_of_apv[APV_id]] && strip_of_channel[APV_channel+128*APV_id] > 0)
                good_hits_id->push_back(hit);

        }
        for( int j = 0 ; j < 5 ; j++)
        {
            if(n_apv_empty_hits[j] >0)
            {
                empty_mean_apv[j] = empty_mean_apv[j]/n_apv_empty_hits[j];
                empty_rms_apv[j] = empty_rms_apv[j]/n_apv_empty_hits[j]-empty_mean_apv[j]*empty_mean_apv[j];
                if(empty_rms_apv[j] < 0)
                    empty_rms_apv[j] = 0;
                empty_rms_apv[j] = TMath::Sqrt(empty_rms_apv[j]);

            }
        }
        if(n_empty_hits > 0)
        {
            empty_mean_hits = empty_mean_hits/n_empty_hits;
            empty_rms_hits = empty_rms_hits/n_empty_hits-empty_mean_hits*empty_mean_hits;
            if(empty_rms_hits < 0) 
                empty_rms_hits = 0;
            empty_rms_hits = TMath::Sqrt(empty_rms_hits);
        }

        cout << "Number of good hits detected: " << good_hits_id->size() << endl;

        r_clustering(r_clusters_hit_id, r_clusters_strip_id, good_hits_id, raw_tree, connector_of_apv, strip_of_channel); 
        cout << "Number of R clusters detected: " << r_clusters_hit_id->size() << endl;

        vector<vector<vector<double>>> *r_cluster_hit_fit_pars = new vector<vector<vector<double>>>();
        vector<vector<vector<double>>> *r_cluster_hit_fit_par_errs = new vector<vector<vector<double>>>();

        fit_good_hits(r_clusters_hit_id, raw_tree, data_tree, r_cluster_hit_fit_pars, r_cluster_hit_fit_par_errs);

        vector<int> *r_big_cluster_id = new vector<int>();
        find_big_clusters(r_clusters_hit_id, r_big_cluster_id);

        vector<int> *big_cluster_peak_hit_id = new vector<int>();
        vector<vector<double>> *big_r_cluster_fit_pars = new vector<vector<double>>();
        vector<vector<double>> *big_r_cluster_fit_par_errs = new vector<vector<double>>();

        fit_big_clusters(r_big_cluster_id, r_clusters_hit_id, raw_tree, data_tree, big_cluster_peak_hit_id, big_r_cluster_fit_pars, big_r_cluster_fit_par_errs, r_cluster_hit_fit_pars, r_cluster_hit_fit_par_errs);

        dump(counters, n_hits, good_hits_id, raw_tree, r_clusters_hit_id, connector_of_apv);

        if(r_clusters_hit_id->size()<2)
        {
            int big_cluster_counter=-1;
            for(int i = 0; i < r_clusters_hit_id->size(); i++)
            {
                int cluster_is_big = 0;
                int cluster_strip;
                if( r_clusters_hit_id->at(i).size() > 1 )
                {
                    big_cluster_counter+=1;
                    cluster_is_big = 1;
                }

                vector<double> fit_params;
                vector<double> fit_param_errs;
                if(cluster_is_big)
                {
                    fit_params = big_r_cluster_fit_pars->at(big_cluster_counter);
                    fit_param_errs = big_r_cluster_fit_par_errs->at(big_cluster_counter);
                    int APV_id = raw_tree->apv_id->at(big_cluster_peak_hit_id->at(big_cluster_counter));
                    int APV_ch = raw_tree->apv_ch->at(big_cluster_peak_hit_id->at(big_cluster_counter));
                    cluster_strip = strip_of_channel[APV_ch + 128*APV_id];
//                    cout << "BIG" << endl;
                }
                else
                {
                    fit_params = r_cluster_hit_fit_pars->at(i).at(0);
                    fit_param_errs = r_cluster_hit_fit_par_errs->at(i).at(0);
                    cluster_strip = r_clusters_strip_id->at(i).at(0);
//                    cout << "SMALL" << endl;
                }
                double inflection_time = fit_params.at(1);
                double inflect_err = fit_param_errs.at(1);
                double arrival_time = fit_params.at(4);
                double arriv_err = fit_param_errs.at(4);
               
                cout << "strip: " << cluster_strip << endl;
                cout << "inflection time: " << inflection_time << " +- " << inflect_err << endl;
                cout << "arrival time: " << arrival_time << " +- " << arriv_err << endl;
            
                cout << endl << r_clusters_hit_id->at(i).size() << " STRIPS HIT IN CLUSTER: " <<i<< endl;
                for(int j = 0; j < r_clusters_hit_id->at(i).size() ; j++ )
                {
                    cout << "hit in cluster: " << j << endl;
                    int strip_hit_apv_id = raw_tree->apv_id->at(r_clusters_hit_id->at(i).at(j));
                    int strip_hit_apv_ch = raw_tree->apv_ch->at(r_clusters_hit_id->at(i).at(j));
                    cout << "strip: " << strip_of_channel[strip_hit_apv_ch+128*strip_hit_apv_id] << endl;
                    double strip_height = data_tree->apv_qmax->at(r_clusters_hit_id->at(i).at(j));
                    double strip_height_pos = data_tree->apv_tbqmax->at(r_clusters_hit_id->at(i).at(j))*25+12.5;
                    cout << "max: " << strip_height << " at time " << strip_height_pos << endl;
                    vector<double> strip_fit_pars = r_cluster_hit_fit_pars->at(i).at(j);
                    vector<double> strip_fit_errs = r_cluster_hit_fit_par_errs->at(i).at(j);
                    cout << "fitted max: " << strip_fit_pars.at(0)+strip_fit_pars.at(3)<<endl;
                    
                    double inflection_point = strip_fit_pars.at(1);
                    double inflection_error = strip_fit_errs.at(1);
                    double strip_arrival = -2./strip_fit_pars.at(2) + strip_fit_pars.at(1);
                    double arrival_err = TMath::Sqrt(strip_fit_errs.at(1)*strip_fit_errs.at(1)+16./strip_fit_pars.at(2)/strip_fit_pars.at(2)*strip_fit_errs.at(2)*strip_fit_errs.at(2));
                    cout << "inflection time: " << inflection_point << " +- " << inflection_error << endl;
                    cout << "arrival time: " << strip_arrival << " +- " << arrival_err<< endl;
                    cout << endl;
                }
            }

            
        }
             
//        cin.get();

        delete good_hits_id;
        delete r_clusters_hit_id;
        delete r_clusters_strip_id;
        delete r_cluster_hit_fit_pars;
        delete r_cluster_hit_fit_par_errs;
        delete r_big_cluster_id;
        delete big_cluster_peak_hit_id;
        delete big_r_cluster_fit_pars;
        delete big_r_cluster_fit_par_errs;
    }
    counters[1] = nentries;
    summary(counters);

    bench->Show("full");
    

    delete root_file;
    delete raw_tree;
    delete data_tree;
    delete bench;
}

void summary(int *counters)
{
    cout << "Number of events: "  << counters[1] << endl;  
    cout << "Phi active: "  << counters[3] << endl;  
    cout << "R active: " << counters[4] << endl;
    cout << "R & Phi active: " << counters[5] << endl;
    cout << "good Phi active: " << counters[6] << endl;
    cout << "good R active: " << counters[7] << endl;
    cout << "good R & Phi active: " << counters[8] << endl;
    cout << "Events with R-clusters: " << counters[9] << endl;
    cout << "Events with less than 20 R-clusters: " << counters[10] << endl;
    cout << "Events with R-clusters only smaller than 20: " << counters[11] << endl;
}
