#ifndef __emptychannels_h__
#define __emptychannels_h__

#include <TMath.h>

class EmptyChannels
{
    public:
        EmptyChannels(int second_chamber_present);
        ~EmptyChannels();
        void Iterate(double *charge, int APV_id);
        void Finalize();
        int GetNEmptyHits();
        int GetNApvEmptyHits(int i);
        double GetEmptyMeanApv(int i);
        double GetEmptyRmsApv(int i);
        double GetEmptyMeanHits();
        double GetEmptyRmsHits();

    private:
        int n_apvs;
        int n_empty_hits;
        int *n_apv_empty_hits;
        double *empty_mean_apv;
        double *empty_rms_apv;
        double empty_mean_hits;
        double empty_rms_hits;
};

#endif //__emptychannels_h__
