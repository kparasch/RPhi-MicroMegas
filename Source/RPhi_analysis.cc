#include "RPhi_analysis.h"

int main(int argc, char* argv[])
{
    //argv[1] = rootfile input
    //argv[2] = second chamber present
    //argv[3] = config of apv to physical connector chamber 1
    //argv[4] = config of apv to physical connector chamber 2
    //

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
    int v0 = 1; //v for verbosity (level 0)
    int v1 = 0; //v for verbosity (level 1)

    TH1D *hist_vpeak[no_of_apvs];
    Generate_Hists_Vpeak(hist_vpeak, 0); //hist_generator.h

    TH1D *hist_qpeak[no_of_apvs];
    Generate_Hists_Qpeak(hist_qpeak, 0);

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

    for(int i = 0; i < nentries; i++)
    {
        raw_tree->GetEntry(i);
        data_tree->GetEntry(i);

        int n_empty_hits = 0;
        int n_apv_hits[5] = {0, 0, 0, 0, 0};
        int n_apv_empty_hits[5] = {0, 0, 0, 0, 0};
        int empty_mean_apv[5] = {0, 0, 0, 0, 0};
        int empty_rms_apv[5] = {0, 0, 0, 0, 0};
        int empty_mean_hits = 0;
        int empty_rms_hits = 0;

        vector<vector<double>> *r_clusters_hit_id = new vector<vector<double>>();        
        vector<int> *good_hits_id = new vector<int>();

        int n_hits = raw_tree->apv_q->size();
        if(v0) cout << "Number of hits detected: " << n_hits << endl;

        for( int hit = 0; hit < n_hits ; hit++ )        
        {
            if(v0) cout << "Proccessing hit: " << hit << endl;
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

            if(qmax > apv_thresholds[connector_of_apv[APV_id]])
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

        
        cin.get();
        delete good_hits_id;
        delete r_clusters_hit_id;
    }

    delete root_file;
    delete raw_tree;
    delete data_tree;

}


