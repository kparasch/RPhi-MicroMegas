#ifndef __hist_generator_h__
#define __hist_generator_h__

#include <TH1D.h>

void Generate_Hists_Vpeak(TH1D **hist_vpeak, int second_chamber_present);
void Generate_Hists_Qpeak(TH1D **hist_qpeak, int second_chamber_present);


#endif // __hist_generator_h__
