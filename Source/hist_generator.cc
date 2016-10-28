#include "hist_generator.h"

void Generate_Hists_Vpeak(TH1D **hist_vpeak, int second_chamber_present)
{
    hist_vpeak[0] = new TH1D("hist_vpeak_0","hist_vpeak_0",400,0,2000);  
    hist_vpeak[1] = new TH1D("hist_vpeak_1","hist_vpeak_1",400,0,2000);  
    hist_vpeak[2] = new TH1D("hist_vpeak_2","hist_vpeak_2",400,0,2000);  
    hist_vpeak[3] = new TH1D("hist_vpeak_3","hist_vpeak_3",400,0,2000);  
    hist_vpeak[4] = new TH1D("hist_vpeak_4","hist_vpeak_4",400,0,2000);  

    if(second_chamber_present)
    {
        hist_vpeak[5] = new TH1D("hist_vpeak_5","hist_vpeak_5",400,0,2000);  
        hist_vpeak[6] = new TH1D("hist_vpeak_6","hist_vpeak_6",400,0,2000);  
        hist_vpeak[7] = new TH1D("hist_vpeak_7","hist_vpeak_7",400,0,2000);  
        hist_vpeak[8] = new TH1D("hist_vpeak_8","hist_vpeak_8",400,0,2000);  
        hist_vpeak[9] = new TH1D("hist_vpeak_9","hist_vpeak_9",400,0,2000);  
    }
}

void Generate_Hists_Qpeak(TH1D **hist_qpeak, int second_chamber_present)
{
    hist_qpeak[0] = new TH1D("hist_qpeak_0","hist_qpeak_0",400,0,2000);  
    hist_qpeak[1] = new TH1D("hist_qpeak_1","hist_qpeak_1",400,0,2000);  
    hist_qpeak[2] = new TH1D("hist_qpeak_2","hist_qpeak_2",400,0,2000);  
    hist_qpeak[3] = new TH1D("hist_qpeak_3","hist_qpeak_3",400,0,2000);  
    hist_qpeak[4] = new TH1D("hist_qpeak_4","hist_qpeak_4",400,0,2000);  

    if(second_chamber_present)
    {
        hist_qpeak[5] = new TH1D("hist_qpeak_5","hist_qpeak_5",400,0,2000);  
        hist_qpeak[6] = new TH1D("hist_qpeak_6","hist_qpeak_6",400,0,2000);  
        hist_qpeak[7] = new TH1D("hist_qpeak_7","hist_qpeak_7",400,0,2000);  
        hist_qpeak[8] = new TH1D("hist_qpeak_8","hist_qpeak_8",400,0,2000);  
        hist_qpeak[9] = new TH1D("hist_qpeak_9","hist_qpeak_9",400,0,2000);  
    }
}

void Generate_Hists_Hits(TH1D **hist_hits, int second_chamber_present)
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

void Generate_Hists_Channels(TH1D **hist_channels, int second_chamber_present)
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

void Generate_Hists_W_Channels(TH1D **hist_w_channels, int second_chamber_present)
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

void Generate_Hists_Strips(TH1D **hist_strips, int second_chamber_present)
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

void Generate_Hists_W_Strips(TH1D **hist_w_strips, int second_chamber_present)
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

void Generate_Hists_All_Vpeak(TH1D **hist_all_vpeak, int second_chamber_present)
{
    hist_all_vpeak[0] = new TH1D("hist_all_vpeak_0","hist_all_vpeak_0",400,0,2000);  
    hist_all_vpeak[1] = new TH1D("hist_all_vpeak_1","hist_all_vpeak_1",400,0,2000);  
    hist_all_vpeak[2] = new TH1D("hist_all_vpeak_2","hist_all_vpeak_2",400,0,2000);  
    hist_all_vpeak[3] = new TH1D("hist_all_vpeak_3","hist_all_vpeak_3",400,0,2000);  
    hist_all_vpeak[4] = new TH1D("hist_all_vpeak_4","hist_all_vpeak_4",400,0,2000);  

    if(second_chamber_present)
    {
        hist_all_vpeak[5] = new TH1D("hist_all_vpeak_5","hist_all_vpeak_5",400,0,2000);  
        hist_all_vpeak[6] = new TH1D("hist_all_vpeak_6","hist_all_vpeak_6",400,0,2000);  
        hist_all_vpeak[7] = new TH1D("hist_all_vpeak_7","hist_all_vpeak_7",400,0,2000);  
        hist_all_vpeak[8] = new TH1D("hist_all_vpeak_8","hist_all_vpeak_8",400,0,2000);  
        hist_all_vpeak[9] = new TH1D("hist_all_vpeak_9","hist_all_vpeak_9",400,0,2000);  
    }
}

void Generate_Hists_Empty_Vpeak(TH1D **hist_empty_vpeak, int second_chamber_present)
{
    hist_empty_vpeak[0] = new TH1D("hist_empty_vpeak_0","hist_empty_vpeak_0", 100,0,200);  
    hist_empty_vpeak[1] = new TH1D("hist_empty_vpeak_1","hist_empty_vpeak_1", 100,0,200);  
    hist_empty_vpeak[2] = new TH1D("hist_empty_vpeak_2","hist_empty_vpeak_2", 100,0,200);  
    hist_empty_vpeak[3] = new TH1D("hist_empty_vpeak_3","hist_empty_vpeak_3", 100,0,200);  
    hist_empty_vpeak[4] = new TH1D("hist_empty_vpeak_4","hist_empty_vpeak_4", 100,0,200);  

    if(second_chamber_present)
    {
        hist_empty_vpeak[5] = new TH1D("hist_empty_vpeak_5","hist_empty_vpeak_5", 100,0,200);  
        hist_empty_vpeak[6] = new TH1D("hist_empty_vpeak_6","hist_empty_vpeak_6", 100,0,200);  
        hist_empty_vpeak[7] = new TH1D("hist_empty_vpeak_7","hist_empty_vpeak_7", 100,0,200);  
        hist_empty_vpeak[8] = new TH1D("hist_empty_vpeak_8","hist_empty_vpeak_8", 100,0,200);  
        hist_empty_vpeak[9] = new TH1D("hist_empty_vpeak_9","hist_empty_vpeak_9", 100,0,200);  
    }
}

void Generate_Hists_All_Tbins(TH1D **hist_all_tbins, int second_chamber_present)
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

void Generate_Hists_Hit_Mean(TH1D **hist_hit_mean, int second_chamber_present)
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

void Generate_Hists_Hit_Rms(TH1D **hist_hit_rms, int second_chamber_present)
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

void Generate_Hists_Apv_Mean(TH1D **hist_apv_mean, int second_chamber_present)
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

void Generate_Hists_Apv_Rms(TH1D **hist_apv_rms, int second_chamber_present)
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

void Generate_Hists_Empty_Channels(TH1D **hist_empty_channels, int second_chamber_present)
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

void Generate_Hists_Empty_W_Channels(TH1D **hist_empty_w_channels, int second_chamber_present)
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

