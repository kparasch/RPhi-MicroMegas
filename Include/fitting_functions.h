#ifndef __fitting_functions_h__
#define __fitting_functions_h__

#include <iostream>
#include <vector>

#include <TMath.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TGraphErrors.h>
#include <TTimer.h>
#include <TSystem.h>
#include <TApplication.h>

#include "raw.h"
#include "data.h"

void group_fit_pars(vector<vector<vector<double>>> *r_cluster_hit_fit_pars, vector<vector<vector<double>>> *r_cluster_hit_fit_par_errs, vector<vector<double>> *big_r_cluster_fit_pars, vector<vector<double>> *big_r_cluster_fit_par_errs, int r_clusters, vector<int> *r_big_cluster_id,vector<vector<double>> *r_cluster_pars, vector<vector<double>> *r_cluster_par_errs);
void fit_big_clusters(vector<int> *r_big_cluster_id, vector<vector<int>> *r_clusters_hit_id, raw *raw_tree, data *data_tree, vector<int> *big_cluster_peak_hit_id, vector<vector<double>> *big_r_cluster_fit_pars, vector<vector<double>> *big_r_cluster_fit_par_errs, vector<vector<vector<double>>> *r_cluster_hit_fit_pars, vector<vector<vector<double>>> *r_cluster_hit_fit_par_errs);
int get_big_cluster_charge(double *charge, int big_cluster_id, vector<vector<int>> *r_clusters_hit_id, raw *raw_tree, data *data_tree); 
void fit_good_hits(vector<vector<int>> *clusters_hit_id, raw *raw_tree, data *data_tree, vector<vector<vector<double>>> *cluster_hit_fit_pars, vector<vector<vector<double>>> *cluster_hit_fit_par_errs);
double fermi_dirac(double *x, double *par);
double Deriv_fermi_dirac(double x, double *par);
double p0_dfd(double x, double *par);
double p1_dfd(double x, double *par);
double p2_dfd(double x, double *par);
double x_dfd(double x, double *par);
int find_min(double *charge, int max_index);
int find_max(double *charge);

#endif //__fitting_functions_h__
