#include "fitting_functions.h"

void group_fit_pars(vector<vector<vector<double>>> *r_cluster_hit_fit_pars, vector<vector<vector<double>>> *r_cluster_hit_fit_par_errs, vector<vector<double>> *big_r_cluster_fit_pars, vector<vector<double>> *big_r_cluster_fit_par_errs, int r_clusters, vector<int> *r_big_cluster_id,vector<vector<double>> *r_cluster_pars, vector<vector<double>> *r_cluster_par_errs)
{
    int big_counter = 0;
    for(int i = 0; i < r_clusters ; i++)
    {
        if(r_big_cluster_id->at(big_counter)==i)
        {
            r_cluster_pars->push_back(big_r_cluster_fit_pars->at(big_counter));
            r_cluster_par_errs->push_back(big_r_cluster_fit_par_errs->at(big_counter));
            big_counter+=1;
        }
        else
        {
            r_cluster_pars->push_back(r_cluster_hit_fit_pars->at(i).at(0));
            r_cluster_par_errs->push_back(r_cluster_hit_fit_pars->at(i).at(0));
        }
    }
}



void fit_big_clusters(vector<int> *r_big_cluster_id, vector<vector<int>> *r_clusters_hit_id, raw *raw_tree, data *data_tree, vector<int> *big_cluster_peak_hit_id, vector<vector<double>> *big_r_cluster_fit_pars, vector<vector<double>> *big_r_cluster_fit_par_errs, vector<vector<vector<double>>> *r_cluster_hit_fit_pars, vector<vector<vector<double>>> *r_cluster_hit_fit_par_errs)
{
    for(int i = 0; i < r_big_cluster_id->size(); i++)
    {
        int big_cluster_id=r_big_cluster_id->at(i);
        double charge[27], charge_err[27];
        double time[27], time_err[27];

        int max_hit_id = get_big_cluster_charge(charge, big_cluster_id, r_clusters_hit_id, raw_tree, data_tree);
        big_cluster_peak_hit_id->push_back(max_hit_id);

        for( int j = 0 ; j < 27 ; j++)
        {
            charge_err[j]=12.*TMath::Sqrt(r_clusters_hit_id->at(big_cluster_id).size());
            time[j] = j*25+12.5;
            time_err[j]=12.5;
        }

        int max_index = find_max(charge);
        int min_index = find_min(charge, max_index);
        double max_charge = charge[max_index];
        double min_charge = charge[min_index];
        double fit_start = min_index*25+12.5;
        double params[4];
        params[0] = max_charge-min_charge;
        params[1] = ( (max_index+min_index)/2.) * 25. + 12.5;
        params[2] = 5./( (max_index-min_index)*25 );
        params[3] = min_charge;

        if(min_index>1)
            fit_start+=50;

        TGraphErrors *charge_vs_time = new TGraphErrors( 27, time, charge, time_err, charge_err );
        TF1 *fd_fit = new TF1("fd_fit", fermi_dirac, fit_start, max_index*25+12.5, 4);
        fd_fit->SetParameters(params[0],params[1],params[2],params[3]); 

        //charge_vs_time->SetMarkerStyle(20);
        //charge_vs_time->Draw("AP");
        charge_vs_time->Fit("fd_fit","qR");
        //charge_vs_time->Draw("same");

        vector<double> pars;
        vector<double> parerrs;

        for( int k = 0 ; k < 4 ;k++)
        {
            pars.push_back(fd_fit->GetParameter(k));
            parerrs.push_back(fd_fit->GetParError(k));
        }
        pars.push_back(fd_fit->GetParameter(1)-TMath::Log((fd_fit->GetParameter(0)+fd_fit->GetParameter(3))/(fd_fit->GetParameter(0)-fd_fit->GetParameter(3)))/fd_fit->GetParameter(2));
        parerrs.push_back(fd_fit->GetParError(1));


        //weighted arrival times
        double alpha = 0;
        double beta = 0;
        double gamma = 0;
        for(int j =0 ; j < r_clusters_hit_id->at(big_cluster_id).size() ; j++)
        {
            double weight = data_tree->apv_qmax->at(j)/max_charge;
            double pare_sq = r_cluster_hit_fit_par_errs->at(big_cluster_id).at(j).at(4)*r_cluster_hit_fit_par_errs->at(big_cluster_id).at(j).at(4);
            alpha+=weight * r_cluster_hit_fit_pars->at(big_cluster_id).at(j).at(4)/pare_sq;
            beta+=weight / pare_sq;
            gamma+= weight*weight /pare_sq;
        }
        pars.push_back(alpha/beta);
        parerrs.push_back(TMath::Sqrt(gamma)/beta);

        //==========

        big_r_cluster_fit_pars->push_back(pars);
        big_r_cluster_fit_par_errs->push_back(parerrs);
        pars.clear();
        parerrs.clear();

        delete charge_vs_time;
        delete fd_fit;
    }


}

int get_big_cluster_charge(double *charge, int big_cluster_id, vector<vector<int>> *r_clusters_hit_id, raw *raw_tree, data *data_tree) 
{
    for(int i = 0; i < 27 ; i++)
    {
        charge[i]=0;
    }
    int max_hit_id=r_clusters_hit_id->at(big_cluster_id).at(0);   
    for(int i = 0; i < r_clusters_hit_id->at(big_cluster_id).size(); i++)
    {
        int hit_id = r_clusters_hit_id->at(big_cluster_id).at(i);
        for(int j = 0 ; j < 27 ; j++)
        {
            charge[j]+=raw_tree->apv_q->at(hit_id).at(j);
        }
        if( data_tree->apv_qmax->at(hit_id)>data_tree->apv_qmax->at(max_hit_id) )
            max_hit_id = hit_id;
    }
    return max_hit_id;
}

void fit_good_hits(vector<vector<int>> *clusters_hit_id, raw *raw_tree, data *data_tree, vector<vector<vector<double>>> *cluster_hit_fit_pars, vector<vector<vector<double>>> *cluster_hit_fit_par_errs)
{
    double rms_fit[5] = {9., 16., 13., 14., 8.6};

    for(int i = 0 ; i < clusters_hit_id->size() ; i++)
    {
        vector<vector<double>> cluster_pars;
        vector<vector<double>> cluster_parerrs;

        for(int j = 0 ; j < clusters_hit_id->at(i).size() ; j++)
        {
            int hit_id = clusters_hit_id->at(i).at(j);
            double charge[27], charge_err[27];
            double time[27], time_err[27];
            for( int k = 0 ; k < 27 ; k++)
            {
                charge[k] = raw_tree->apv_q->at(hit_id).at(k);
                time[k] = 25.*k+12.5;
                charge_err[k] = rms_fit[raw_tree->apv_id->at(hit_id)];
                time_err[k] = 12.5;
            }
            TGraphErrors *charge_vs_time = new TGraphErrors( 27, time, charge, time_err, charge_err );

            double max_charge = data_tree->apv_qmax->at(hit_id);
            int max_index = data_tree->apv_tbqmax->at(hit_id);
            int min_index = find_min(charge, max_index);
            double min_charge = charge[min_index];

            double params[4];
            params[0] = max_charge-min_charge;
            params[1] = ( (max_index+min_index)/2.) * 25. + 12.5;
            params[2] = 5./( (max_index-min_index)*25 );
            params[3] = min_charge;
            double fit_start = min_index*25+12.5;
            if(min_index > 1)
                fit_start-=50.;

            TF1 *fd_fit = new TF1("fd_fit", fermi_dirac, fit_start, max_index*25+12.5, 4);
            fd_fit->SetParameters(params[0],params[1],params[2],params[3]); 

            //charge_vs_time->SetMarkerStyle(20);
            //charge_vs_time->Draw("AP");
            charge_vs_time->Fit("fd_fit","qR");
            //charge_vs_time->Draw("same");

            vector<double> pars;
            vector<double> parerrs;

            for( int k = 0 ; k < 4 ;k++)
            {
                pars.push_back(fd_fit->GetParameter(k));
                parerrs.push_back(fd_fit->GetParError(k));
            }
            pars.push_back(fd_fit->GetParameter(1)-TMath::Log((fd_fit->GetParameter(0)+fd_fit->GetParameter(3))/(fd_fit->GetParameter(0)-fd_fit->GetParameter(3)))/fd_fit->GetParameter(2));
            parerrs.push_back(fd_fit->GetParError(1));

            cluster_pars.push_back(pars);
            cluster_parerrs.push_back(parerrs);
            pars.clear();
            parerrs.clear();

            //cin.get();

            delete charge_vs_time;
            delete fd_fit;
        }
        cluster_hit_fit_pars->push_back(cluster_pars);
        cluster_hit_fit_par_errs->push_back(cluster_parerrs);
        cluster_pars.clear();
        cluster_parerrs.clear();
    }
}


double fermi_dirac(double *x, double *par)
{
    double fdreturn = par[0]/(1+TMath::Exp(-(x[0]-par[1])*par[2]))+par[3];
    return fdreturn;
}

double Deriv_fermi_dirac(double x, double *par)  //derivative with respect to x
{
    double expterm = TMath::Exp(-(x-par[1])*par[2]);
    double dfdreturn = par[0]*expterm/(1+expterm)/(1+expterm)*par[2];
    return dfdreturn;
}

double p0_dfd(double x, double *par)   //derivative of derivative with respect to p0
{
    double expterm = TMath::Exp(-(x-par[1])*par[2]);
    double p0return = Deriv_fermi_dirac(x, par)/par[0];
    return p0return; 
}

double p1_dfd(double x, double *par) //derivative of derivative with respect to p1
{
    double expterm = TMath::Exp(-(x-par[1])*par[2]);
    double p1return = Deriv_fermi_dirac(x, par)*par[2]*(1-2*expterm/(1+expterm));
    return p1return;	 
}

double p2_dfd(double x, double *par) //derivative of derivative with respect to p2
{
    double expterm = TMath::Exp(-(x-par[1])*par[2]);
    double p2return = Deriv_fermi_dirac(x, par)*(1./par[2]+par[1]-x+2*(x-par[1])*expterm/(1+expterm));
    return p2return; 
}

double x_dfd(double x, double *par) //derivative of derivative with respect to x
{
    double xreturn = -p1_dfd(x, par);
    return xreturn;
}

int find_min(double *charge, int max_index)
{   
    int min_index = max_index;
    double min = charge[max_index];
    for(int i = max_index ; i>=0 ; i--)
    {
        if(charge[i] < min)
        {
            min_index = i;
            min = charge[min_index];
        }
        if( min_index > 2)
        {
            bool c1 = charge[min_index] < charge[min_index-1];
            bool c2 = charge[min_index] < charge[min_index-2];
            bool c3 = charge[min_index] < charge[min_index-3];
            if(c1 && c2 && c3)
                break;
        }
    }
    return min_index;
}

int find_max(double* charge)
{
    int max_index=-1;
    for(int i = 0 ; i < 27 ; i++)
    {
        if(charge[i]>charge[max_index])
            max_index=i;
    }
    return max_index;
}
