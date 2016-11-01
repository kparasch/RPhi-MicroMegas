#include "Histograms.h"

Histograms::Histograms(int n_of_chambers)
{
    n_hists = 5 * n_of_chambers;
    second_chamber_present = n_of_chambers > 1;
    std::cout << "----Declaring Histograms----" << std::endl;
    hist_qmax = new TH1D*[n_hists]; 

    std::cout << "----Generating Histograms----" << std::endl;
    Generate_Hists_Qmax(hist_qmax, second_chamber_present);
}

Histograms::~Histograms()
{
    std::cout << "----Deleting Histograms----" << std::endl;
    for(int i = 0 ; i < n_hists; i++)
    {
        delete hist_qmax[i];
    }
    delete hist_qmax;
}

TH1D* Histograms::GetQmax(int i) {return hist_qmax[i];}
TH1D* Histograms::GetTotalCharge(int i) {return hist_total_charge[i];}
TH1D* Histograms::GetHits(int i) {return hist_hits[i];}
TH1D* Histograms::GetChannels(int i) {return hist_channels[i];}
TH1D* Histograms::GetWChannels(int i) {return hist_w_channels[i];}
TH1D* Histograms::GetStrips(int i) {return hist_strips[i];}
TH1D* Histograms::GetWStrips(int i) {return hist_w_strips[i];}
TH1D* Histograms::GetAllQmax(int i) {return hist_all_qmax[i];}
TH1D* Histograms::GetEmptyQmax(int i) {return hist_empty_qmax[i];}
TH1D* Histograms::GetAllTbins(int i) {return hist_all_tbins[i];}
TH1D* Histograms::GetHitMean(int i) {return hist_hit_mean[i];}
TH1D* Histograms::GetHitRms(int i) {return hist_hit_rms[i];}
TH1D* Histograms::GetApvMean(int i) {return hist_apv_mean[i];}
TH1D* Histograms::GetApvRms(int i) {return hist_apv_rms[i];}
TH1D* Histograms::GetEmptyChannels(int i) {return hist_empty_channels[i];}
TH1D* Histograms::GetEmptyWChannels(int i) {return hist_empty_w_channels[i];}

void Histograms::Generate_Hists_Qmax(TH1D **hist_qmax, int second_chamber_present)
{
    hist_qmax[0] = new TH1D("hist_qmax_0","hist_qmax_0",400,0,2000);  
    hist_qmax[1] = new TH1D("hist_qmax_1","hist_qmax_1",400,0,2000);  
    hist_qmax[2] = new TH1D("hist_qmax_2","hist_qmax_2",400,0,2000);  
    hist_qmax[3] = new TH1D("hist_qmax_3","hist_qmax_3",400,0,2000);  
    hist_qmax[4] = new TH1D("hist_qmax_4","hist_qmax_4",400,0,2000);  

    if(second_chamber_present)
    {
        hist_qmax[5] = new TH1D("hist_qmax_5","hist_qmax_5",400,0,2000);  
        hist_qmax[6] = new TH1D("hist_qmax_6","hist_qmax_6",400,0,2000);  
        hist_qmax[7] = new TH1D("hist_qmax_7","hist_qmax_7",400,0,2000);  
        hist_qmax[8] = new TH1D("hist_qmax_8","hist_qmax_8",400,0,2000);  
        hist_qmax[9] = new TH1D("hist_qmax_9","hist_qmax_9",400,0,2000);  
    }
}

void Histograms::Generate_Hists_Total_Charge(TH1D **hist_total_charge, int second_chamber_present)
{
    hist_total_charge[0] = new TH1D("hist_total_charge_0","hist_total_charge_0",400,0,2000);  
    hist_total_charge[1] = new TH1D("hist_total_charge_1","hist_total_charge_1",400,0,2000);  
    hist_total_charge[2] = new TH1D("hist_total_charge_2","hist_total_charge_2",400,0,2000);  
    hist_total_charge[3] = new TH1D("hist_total_charge_3","hist_total_charge_3",400,0,2000);  
    hist_total_charge[4] = new TH1D("hist_total_charge_4","hist_total_charge_4",400,0,2000);  

    if(second_chamber_present)
    {
        hist_total_charge[5] = new TH1D("hist_total_charge_5","hist_total_charge_5",400,0,2000);  
        hist_total_charge[6] = new TH1D("hist_total_charge_6","hist_total_charge_6",400,0,2000);  
        hist_total_charge[7] = new TH1D("hist_total_charge_7","hist_total_charge_7",400,0,2000);  
        hist_total_charge[8] = new TH1D("hist_total_charge_8","hist_total_charge_8",400,0,2000);  
        hist_total_charge[9] = new TH1D("hist_total_charge_9","hist_total_charge_9",400,0,2000);  
    }
}

void Histograms::Generate_Hists_Hits(TH1D **hist_hits, int second_chamber_present)
{
    hist_hits[0] = new TH1D("hist_hits_0","hist_hits_0",51,-0.5,50.5);  
    hist_hits[1] = new TH1D("hist_hits_1","hist_hits_1",51,-0.5,50.5);  
    hist_hits[2] = new TH1D("hist_hits_2","hist_hits_2",51,-0.5,50.5);  
    hist_hits[3] = new TH1D("hist_hits_3","hist_hits_3",51,-0.5,50.5);  
    hist_hits[4] = new TH1D("hist_hits_4","hist_hits_4",51,-0.5,50.5);  

    if(second_chamber_present)
    {
        hist_hits[5] = new TH1D("hist_hits_5","hist_hits_5",51,-0.5,50.5);  
        hist_hits[6] = new TH1D("hist_hits_6","hist_hits_6",51,-0.5,50.5);  
        hist_hits[7] = new TH1D("hist_hits_7","hist_hits_7",51,-0.5,50.5);  
        hist_hits[8] = new TH1D("hist_hits_8","hist_hits_8",51,-0.5,50.5);  
        hist_hits[9] = new TH1D("hist_hits_9","hist_hits_9",51,-0.5,50.5);  
    }
}

void Histograms::Generate_Hists_Channels(TH1D **hist_channels, int second_chamber_present)
{
    hist_channels[0] = new TH1D("hist_channels_0","hist_channels_0",128,-0.5,127.5);  
    hist_channels[1] = new TH1D("hist_channels_1","hist_channels_1",128,-0.5,127.5);  
    hist_channels[2] = new TH1D("hist_channels_2","hist_channels_2",128,-0.5,127.5);  
    hist_channels[3] = new TH1D("hist_channels_3","hist_channels_3",128,-0.5,127.5);  
    hist_channels[4] = new TH1D("hist_channels_4","hist_channels_4",128,-0.5,127.5);  

    if(second_chamber_present)
    {
        hist_channels[5] = new TH1D("hist_channels_5","hist_channels_5",128,-0.5,127.5);  
        hist_channels[6] = new TH1D("hist_channels_6","hist_channels_6",128,-0.5,127.5);  
        hist_channels[7] = new TH1D("hist_channels_7","hist_channels_7",128,-0.5,127.5);  
        hist_channels[8] = new TH1D("hist_channels_8","hist_channels_8",128,-0.5,127.5);  
        hist_channels[9] = new TH1D("hist_channels_9","hist_channels_9",128,-0.5,127.5);  
    }
}

void Histograms::Generate_Hists_W_Channels(TH1D **hist_w_channels, int second_chamber_present)
{
    hist_w_channels[0] = new TH1D("hist_w_channels_0","hist_w_channels_0",128, -0.5, 127.5);  
    hist_w_channels[1] = new TH1D("hist_w_channels_1","hist_w_channels_1",128, -0.5, 127.5);  
    hist_w_channels[2] = new TH1D("hist_w_channels_2","hist_w_channels_2",128, -0.5, 127.5);  
    hist_w_channels[3] = new TH1D("hist_w_channels_3","hist_w_channels_3",128, -0.5, 127.5);  
    hist_w_channels[4] = new TH1D("hist_w_channels_4","hist_w_channels_4",128, -0.5, 127.5);  

    if(second_chamber_present)
    {
        hist_w_channels[5] = new TH1D("hist_w_channels_5","hist_w_channels_5",128, -0.5, 127.5);  
        hist_w_channels[6] = new TH1D("hist_w_channels_6","hist_w_channels_6",128, -0.5, 127.5);  
        hist_w_channels[7] = new TH1D("hist_w_channels_7","hist_w_channels_7",128, -0.5, 127.5);  
        hist_w_channels[8] = new TH1D("hist_w_channels_8","hist_w_channels_8",128, -0.5, 127.5);  
        hist_w_channels[9] = new TH1D("hist_w_channels_9","hist_w_channels_9",128, -0.5, 127.5);  
    }
}

void HistogramsGenerate_Hists_Strips(TH1D **hist_strips, int second_chamber_present)
{
    hist_strips[0] = new TH1D("hist_strips_0","hist_strips_0", 91, 0.5, 91.5);  
    hist_strips[1] = new TH1D("hist_strips_1","hist_strips_1", 91, 0.5, 91.5);  
    hist_strips[2] = new TH1D("hist_strips_2","hist_strips_2", 91, 0.5, 91.5);  
    hist_strips[3] = new TH1D("hist_strips_3","hist_strips_3", 91, 0.5, 91.5);  
    hist_strips[4] = new TH1D("hist_strips_4","hist_strips_4", 91, 0.5, 91.5);  

    if(second_chamber_present)
    {
        hist_strips[5] = new TH1D("hist_strips_5","hist_strips_5", 91, 0.5, 91.5);  
        hist_strips[6] = new TH1D("hist_strips_6","hist_strips_6", 91, 0.5, 91.5);  
        hist_strips[7] = new TH1D("hist_strips_7","hist_strips_7", 91, 0.5, 91.5);  
        hist_strips[8] = new TH1D("hist_strips_8","hist_strips_8", 91, 0.5, 91.5);  
        hist_strips[9] = new TH1D("hist_strips_9","hist_strips_9", 91, 0.5, 91.5);  
    }
}

void Histograms::Generate_Hists_W_Strips(TH1D **hist_w_strips, int second_chamber_present)
{
    hist_w_strips[0] = new TH1D("hist_w_strips_0","hist_w_strips_0", 91, 0.5, 91.5);  
    hist_w_strips[1] = new TH1D("hist_w_strips_1","hist_w_strips_1", 91, 0.5, 91.5);  
    hist_w_strips[2] = new TH1D("hist_w_strips_2","hist_w_strips_2", 91, 0.5, 91.5);  
    hist_w_strips[3] = new TH1D("hist_w_strips_3","hist_w_strips_3", 91, 0.5, 91.5);  
    hist_w_strips[4] = new TH1D("hist_w_strips_4","hist_w_strips_4", 91, 0.5, 91.5);  

    if(second_chamber_present)
    {
        hist_w_strips[5] = new TH1D("hist_w_strips_5","hist_w_strips_5", 91, 0.5, 91.5);  
        hist_w_strips[6] = new TH1D("hist_w_strips_6","hist_w_strips_6", 91, 0.5, 91.5);  
        hist_w_strips[7] = new TH1D("hist_w_strips_7","hist_w_strips_7", 91, 0.5, 91.5);  
        hist_w_strips[8] = new TH1D("hist_w_strips_8","hist_w_strips_8", 91, 0.5, 91.5);  
        hist_w_strips[9] = new TH1D("hist_w_strips_9","hist_w_strips_9", 91, 0.5, 91.5);  
    }
}

void Histograms::Generate_Hists_All_Qmax(TH1D **hist_all_qmax, int second_chamber_present)
{
    hist_all_qmax[0] = new TH1D("hist_all_qmax_0","hist_all_qmax_0",400,0,2000);  
    hist_all_qmax[1] = new TH1D("hist_all_qmax_1","hist_all_qmax_1",400,0,2000);  
    hist_all_qmax[2] = new TH1D("hist_all_qmax_2","hist_all_qmax_2",400,0,2000);  
    hist_all_qmax[3] = new TH1D("hist_all_qmax_3","hist_all_qmax_3",400,0,2000);  
    hist_all_qmax[4] = new TH1D("hist_all_qmax_4","hist_all_qmax_4",400,0,2000);  

    if(second_chamber_present)
    {
        hist_all_qmax[5] = new TH1D("hist_all_qmax_5","hist_all_qmax_5",400,0,2000);  
        hist_all_qmax[6] = new TH1D("hist_all_qmax_6","hist_all_qmax_6",400,0,2000);  
        hist_all_qmax[7] = new TH1D("hist_all_qmax_7","hist_all_qmax_7",400,0,2000);  
        hist_all_qmax[8] = new TH1D("hist_all_qmax_8","hist_all_qmax_8",400,0,2000);  
        hist_all_qmax[9] = new TH1D("hist_all_qmax_9","hist_all_qmax_9",400,0,2000);  
    }
}

void Histograms::Generate_Hists_Empty_Qmax(TH1D **hist_empty_qmax, int second_chamber_present)
{
    hist_empty_qmax[0] = new TH1D("hist_empty_qmax_0","hist_empty_qmax_0", 100,0,200);  
    hist_empty_qmax[1] = new TH1D("hist_empty_qmax_1","hist_empty_qmax_1", 100,0,200);  
    hist_empty_qmax[2] = new TH1D("hist_empty_qmax_2","hist_empty_qmax_2", 100,0,200);  
    hist_empty_qmax[3] = new TH1D("hist_empty_qmax_3","hist_empty_qmax_3", 100,0,200);  
    hist_empty_qmax[4] = new TH1D("hist_empty_qmax_4","hist_empty_qmax_4", 100,0,200);  

    if(second_chamber_present)
    {
        hist_empty_qmax[5] = new TH1D("hist_empty_qmax_5","hist_empty_qmax_5", 100,0,200);  
        hist_empty_qmax[6] = new TH1D("hist_empty_qmax_6","hist_empty_qmax_6", 100,0,200);  
        hist_empty_qmax[7] = new TH1D("hist_empty_qmax_7","hist_empty_qmax_7", 100,0,200);  
        hist_empty_qmax[8] = new TH1D("hist_empty_qmax_8","hist_empty_qmax_8", 100,0,200);  
        hist_empty_qmax[9] = new TH1D("hist_empty_qmax_9","hist_empty_qmax_9", 100,0,200);  
    }
}

void Histograms::Generate_Hists_All_Tbins(TH1D **hist_all_tbins, int second_chamber_present)
{
    hist_all_tbins[0] = new TH1D("hist_all_tbins_0","hist_all_tbins_0", 100, -100, 100);  
    hist_all_tbins[1] = new TH1D("hist_all_tbins_1","hist_all_tbins_1", 100, -100, 100);  
    hist_all_tbins[2] = new TH1D("hist_all_tbins_2","hist_all_tbins_2", 100, -100, 100);  
    hist_all_tbins[3] = new TH1D("hist_all_tbins_3","hist_all_tbins_3", 100, -100, 100);  
    hist_all_tbins[4] = new TH1D("hist_all_tbins_4","hist_all_tbins_4", 100, -100, 100);  

    if(second_chamber_present)
    {
        hist_all_tbins[5] = new TH1D("hist_all_tbins_5","hist_all_tbins_5", 100, -100, 100);  
        hist_all_tbins[6] = new TH1D("hist_all_tbins_6","hist_all_tbins_6", 100, -100, 100);  
        hist_all_tbins[7] = new TH1D("hist_all_tbins_7","hist_all_tbins_7", 100, -100, 100);  
        hist_all_tbins[8] = new TH1D("hist_all_tbins_8","hist_all_tbins_8", 100, -100, 100);  
        hist_all_tbins[9] = new TH1D("hist_all_tbins_9","hist_all_tbins_9", 100, -100, 100);  
    }
}

void Histograms::Generate_Hists_Hit_Mean(TH1D **hist_hit_mean, int second_chamber_present)
{
    hist_hit_mean[0] = new TH1D("hist_hit_mean_0","hist_hit_mean_0", 100, -40, 40);  
    hist_hit_mean[1] = new TH1D("hist_hit_mean_1","hist_hit_mean_1", 100, -40, 40);  
    hist_hit_mean[2] = new TH1D("hist_hit_mean_2","hist_hit_mean_2", 100, -40, 40);  
    hist_hit_mean[3] = new TH1D("hist_hit_mean_3","hist_hit_mean_3", 100, -40, 40);  
    hist_hit_mean[4] = new TH1D("hist_hit_mean_4","hist_hit_mean_4", 100, -40, 40);  

    if(second_chamber_present)
    {
        hist_hit_mean[5] = new TH1D("hist_hit_mean_5","hist_hit_mean_5", 100, -40, 40);  
        hist_hit_mean[6] = new TH1D("hist_hit_mean_6","hist_hit_mean_6", 100, -40, 40);  
        hist_hit_mean[7] = new TH1D("hist_hit_mean_7","hist_hit_mean_7", 100, -40, 40);  
        hist_hit_mean[8] = new TH1D("hist_hit_mean_8","hist_hit_mean_8", 100, -40, 40);  
        hist_hit_mean[9] = new TH1D("hist_hit_mean_9","hist_hit_mean_9", 100, -40, 40);  
    }
}

void Histograms::Generate_Hists_Hit_Rms(TH1D **hist_hit_rms, int second_chamber_present)
{
    hist_hit_rms[0] = new TH1D("hist_hit_rms_0","hist_hit_rms_0", 100, 0, 40);  
    hist_hit_rms[1] = new TH1D("hist_hit_rms_1","hist_hit_rms_1", 100, 0, 40);  
    hist_hit_rms[2] = new TH1D("hist_hit_rms_2","hist_hit_rms_2", 100, 0, 40);  
    hist_hit_rms[3] = new TH1D("hist_hit_rms_3","hist_hit_rms_3", 100, 0, 40);  
    hist_hit_rms[4] = new TH1D("hist_hit_rms_4","hist_hit_rms_4", 100, 0, 40);  

    if(second_chamber_present)
    {
        hist_hit_rms[5] = new TH1D("hist_hit_rms_5","hist_hit_rms_5", 100, 0, 40);  
        hist_hit_rms[6] = new TH1D("hist_hit_rms_6","hist_hit_rms_6", 100, 0, 40);  
        hist_hit_rms[7] = new TH1D("hist_hit_rms_7","hist_hit_rms_7", 100, 0, 40);  
        hist_hit_rms[8] = new TH1D("hist_hit_rms_8","hist_hit_rms_8", 100, 0, 40);  
        hist_hit_rms[9] = new TH1D("hist_hit_rms_9","hist_hit_rms_9", 100, 0, 40);  
    }
}

void Histograms::Generate_Hists_Apv_Mean(TH1D **hist_apv_mean, int second_chamber_present)
{
    hist_apv_mean[0] = new TH1D("hist_apv_mean_0","hist_apv_mean_0", 100, -40, 40);  
    hist_apv_mean[1] = new TH1D("hist_apv_mean_1","hist_apv_mean_1", 100, -40, 40);  
    hist_apv_mean[2] = new TH1D("hist_apv_mean_2","hist_apv_mean_2", 100, -40, 40);  
    hist_apv_mean[3] = new TH1D("hist_apv_mean_3","hist_apv_mean_3", 100, -40, 40);  
    hist_apv_mean[4] = new TH1D("hist_apv_mean_4","hist_apv_mean_4", 100, -40, 40);  

    if(second_chamber_present)
    {
        hist_apv_mean[5] = new TH1D("hist_apv_mean_5","hist_apv_mean_5", 100, -40, 40);  
        hist_apv_mean[6] = new TH1D("hist_apv_mean_6","hist_apv_mean_6", 100, -40, 40);  
        hist_apv_mean[7] = new TH1D("hist_apv_mean_7","hist_apv_mean_7", 100, -40, 40);  
        hist_apv_mean[8] = new TH1D("hist_apv_mean_8","hist_apv_mean_8", 100, -40, 40);  
        hist_apv_mean[9] = new TH1D("hist_apv_mean_9","hist_apv_mean_9", 100, -40, 40);  
    }
}

void Histograms::Generate_Hists_Apv_Rms(TH1D **hist_apv_rms, int second_chamber_present)
{
    hist_apv_rms[0] = new TH1D("hist_apv_rms_0","hist_apv_rms_0", 100, 0, 40);  
    hist_apv_rms[1] = new TH1D("hist_apv_rms_1","hist_apv_rms_1", 100, 0, 40);  
    hist_apv_rms[2] = new TH1D("hist_apv_rms_2","hist_apv_rms_2", 100, 0, 40);  
    hist_apv_rms[3] = new TH1D("hist_apv_rms_3","hist_apv_rms_3", 100, 0, 40);  
    hist_apv_rms[4] = new TH1D("hist_apv_rms_4","hist_apv_rms_4", 100, 0, 40);  

    if(second_chamber_present)
    {
        hist_apv_rms[5] = new TH1D("hist_apv_rms_5","hist_apv_rms_5", 100, 0, 40);  
        hist_apv_rms[6] = new TH1D("hist_apv_rms_6","hist_apv_rms_6", 100, 0, 40);  
        hist_apv_rms[7] = new TH1D("hist_apv_rms_7","hist_apv_rms_7", 100, 0, 40);  
        hist_apv_rms[8] = new TH1D("hist_apv_rms_8","hist_apv_rms_8", 100, 0, 40);  
        hist_apv_rms[9] = new TH1D("hist_apv_rms_9","hist_apv_rms_9", 100, 0, 40);  
    }
}

void Histograms::Generate_Hists_Empty_Channels(TH1D **hist_empty_channels, int second_chamber_present)
{
    hist_empty_channels[0] = new TH1D("hist_empty_channels_0","hist_empty_channels_0", 128, -0.5, 127.5);  
    hist_empty_channels[1] = new TH1D("hist_empty_channels_1","hist_empty_channels_1", 128, -0.5, 127.5);  
    hist_empty_channels[2] = new TH1D("hist_empty_channels_2","hist_empty_channels_2", 128, -0.5, 127.5);  
    hist_empty_channels[3] = new TH1D("hist_empty_channels_3","hist_empty_channels_3", 128, -0.5, 127.5);  
    hist_empty_channels[4] = new TH1D("hist_empty_channels_4","hist_empty_channels_4", 128, -0.5, 127.5);  

    if(second_chamber_present)
    {
        hist_empty_channels[5] = new TH1D("hist_empty_channels_5","hist_empty_channels_5", 128, -0.5, 127.5);  
        hist_empty_channels[6] = new TH1D("hist_empty_channels_6","hist_empty_channels_6", 128, -0.5, 127.5);  
        hist_empty_channels[7] = new TH1D("hist_empty_channels_7","hist_empty_channels_7", 128, -0.5, 127.5);  
        hist_empty_channels[8] = new TH1D("hist_empty_channels_8","hist_empty_channels_8", 128, -0.5, 127.5);  
        hist_empty_channels[9] = new TH1D("hist_empty_channels_9","hist_empty_channels_9", 128, -0.5, 127.5);  
    }
}

void Histograms::Generate_Hists_Empty_W_Channels(TH1D **hist_empty_w_channels, int second_chamber_present)
{
    hist_empty_w_channels[0] = new TH1D("hist_empty_w_channels_0","hist_empty_w_channels_0", 128, -0.5, 127.5);  
    hist_empty_w_channels[1] = new TH1D("hist_empty_w_channels_1","hist_empty_w_channels_1", 128, -0.5, 127.5);  
    hist_empty_w_channels[2] = new TH1D("hist_empty_w_channels_2","hist_empty_w_channels_2", 128, -0.5, 127.5);  
    hist_empty_w_channels[3] = new TH1D("hist_empty_w_channels_3","hist_empty_w_channels_3", 128, -0.5, 127.5);  
    hist_empty_w_channels[4] = new TH1D("hist_empty_w_channels_4","hist_empty_w_channels_4", 128, -0.5, 127.5);  

    if(second_chamber_present)
    {
        hist_empty_w_channels[5] = new TH1D("hist_empty_w_channels_5","hist_empty_w_channels_5", 128, -0.5, 127.5);  
        hist_empty_w_channels[6] = new TH1D("hist_empty_w_channels_6","hist_empty_w_channels_6", 128, -0.5, 127.5);  
        hist_empty_w_channels[7] = new TH1D("hist_empty_w_channels_7","hist_empty_w_channels_7", 128, -0.5, 127.5);  
        hist_empty_w_channels[8] = new TH1D("hist_empty_w_channels_8","hist_empty_w_channels_8", 128, -0.5, 127.5);  
        hist_empty_w_channels[9] = new TH1D("hist_empty_w_channels_9","hist_empty_w_channels_9", 128, -0.5, 127.5);  
    }
}

