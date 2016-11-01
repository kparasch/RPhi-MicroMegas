#ifndef __hist_generator_h__
#define __hist_generator_h__

#include <iostream>

#include <TH1D.h>


class Histograms
{
    public:
        Histograms(int n_of_chambers);
        ~Histograms();
        TH1D* GetQmax(int i);
        TH1D* GetTotalCharge(int i);
        TH1D* GetHits(int i);
        TH1D* GetChannels(int i);
        TH1D* GetWChannels(int i);
        TH1D* GetStrips(int i);
        TH1D* GetWStrips(int i);
        TH1D* GetAllQmax(int i);
        TH1D* GetEmptyQmax(int i);
        TH1D* GetAllTbins(int i);
        TH1D* GetHitMean(int i);
        TH1D* GetHitRms(int i);
        TH1D* GetApvMean(int i);
        TH1D* GetApvRms(int i);
        TH1D* GetEmptyChannels(int i);
        TH1D* GetEmptyWChannels(int i);

    private:
        int second_chamber_present;
        int n_hists;        
        TH1D **hist_qmax;
        TH1D **hist_total_charge;
        TH1D **hist_hits;
        TH1D **hist_channels;
        TH1D **hist_w_channels;
        TH1D **hist_strips;
        TH1D **hist_w_strips;
        TH1D **hist_all_qmax;
        TH1D **hist_empty_qmax;
        TH1D **hist_all_tbins;
        TH1D **hist_hit_mean;
        TH1D **hist_hit_rms;
        TH1D **hist_apv_mean;
        TH1D **hist_apv_rms;
        TH1D **hist_empty_channels;
        TH1D **hist_empty_w_channels;
        void Generate_Hists_Qmax(TH1D **hist_qmax, int second_chamber_present);
        void Generate_Hists_Total_Charge(TH1D **hist_total, int second_chamber_present);
        void Generate_Hists_Hits(TH1D **hist_hits, int second_chamber_present);
        void Generate_Hists_Channels(TH1D **hist_channels, int second_chamber_present);
        void Generate_Hists_W_Channels(TH1D **hist_w_channels, int second_chamber_present);
        void Generate_Hists_Strips(TH1D **hist_strips, int second_chamber_present);
        void Generate_Hists_W_Strips(TH1D **hist_w_strips, int second_chamber_present);
        void Generate_Hists_All_Qmax(TH1D **hist_all_qmax, int second_chamber_present);
        void Generate_Hists_Empty_Qmax(TH1D **hist_empty_qmax, int second_chamber_present);
        void Generate_Hists_All_Tbins(TH1D **hist_all_tbins, int second_chamber_present);
        void Generate_Hists_Hit_Mean(TH1D **hist_hit_mean, int second_chamber_present);
        void Generate_Hists_Hit_Rms(TH1D **hist_hit_rms, int second_chamber_present);
        void Generate_Hists_Apv_Mean(TH1D **hist_apv_mean, int second_chamber_present);
        void Generate_Hists_Apv_Rms(TH1D **hist_apv_rms, int second_chamber_present);
        void Generate_Hists_Empty_Channels(TH1D **hist_empty_channels, int second_chamber_present);
        void Generate_Hists_Empty_W_Channels(TH1D **hist_empty_w_channel, int second_chamber_present);

};


#endif // __hist_generator_h__
