#ifndef __hist_generator_h__
#define __hist_generator_h__

#include <TH1D.h>

void Generate_Hists_Vpeak(TH1D **hist_vpeak, int second_chamber_present);
void Generate_Hists_Qpeak(TH1D **hist_qpeak, int second_chamber_present);
void Generate_Hists_Hits(TH1D **hist_hits, int second_chamber_present);
void Generate_Hists_Channels(TH1D **hist_channels, int second_chamber_present);
void Generate_Hists_W_Channels(TH1D **hist_w_channels, int second_chamber_present);
void Generate_Hists_Strips(TH1D **hist_strips, int second_chamber_present);
void Generate_Hists_W_Strips(TH1D **hist_w_strips, int second_chamber_present);
void Generate_Hists_All_Vpeak(TH1D **hist_all_vpeak, int second_chamber_present);
void Generate_Hists_Empty_Vpeak(TH1D **hist_empty_vpeak, int second_chamber_present);
void Generate_Hists_All_Tbins(TH1D **hist_all_tbins, int second_chamber_present);
void Generate_Hists_Hit_Mean(TH1D **hist_hit_mean, int second_chamber_present);
void Generate_Hists_Hit_Rms(TH1D **hist_hit_rms, int second_chamber_present);
void Generate_Hists_Apv_Mean(TH1D **hist_apv_mean, int second_chamber_present);
void Generate_Hists_Apv_Rms(TH1D **hist_apv_rms, int second_chamber_present);
void Generate_Hists_Empty_Channels(TH1D **hist_empty_channels, int second_chamber_present);
void Generate_Hists_Empty_W_Channels(TH1D **hist_empty_w_channel, int second_chamber_present);

#endif // __hist_generator_h__
