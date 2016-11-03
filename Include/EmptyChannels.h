#ifndef __emptychannels_h__
#define __emptychannels_h__

#include <TMath.h>

#include "Histograms.h"

class EmptyChannels
{
    public:
        EmptyChannels(int second_chamber_present, int *config);
        ~EmptyChannels();
        void Iterate(double *charge, int APV_id, Histograms *hists);
        void Finalize(Histograms *hists);
        int GetNApvEmptyHits(int i);
        double GetEmptyMeanApv(int i);
        double GetEmptyRmsApv(int i);

    private:
        int *connector_of_apv;
        int n_apvs;
        int *n_apv_empty_hits;
        double *empty_mean_apv;
        double *empty_rms_apv;
};

#endif //__emptychannels_h__
