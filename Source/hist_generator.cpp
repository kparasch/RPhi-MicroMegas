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
