#include "EmptyChannels.h"

EmptyChannels::EmptyChannels(int second_chamber_present)
{
    n_apvs = 5 + 5 * second_chamber_present;
    n_empty_hits = 0;
    empty_mean_hits = 0;
    empty_rms_hits = 0;

    n_apv_empty_hits = new int[n_apvs];
    empty_mean_apv = new double[n_apvs];
    empty_rms_apv = new double[n_apvs];

    for(int i = 0 ; i < n_apvs ; ++i)
    {
        n_apv_empty_hits[i] = 0;
        empty_mean_apv[i] = 0;
        empty_rms_apv[i] = 0;
    }
}

EmptyChannels::~EmptyChannels()
{
    delete n_apv_empty_hits;
    delete empty_mean_apv;
    delete empty_rms_apv;
}

void EmptyChannels::Iterate(double *charge, int APV_id)
{
    double total_charge = 0;
    double total_charge_squared = 0;

    for(int i = 0 ; i < 27 ; ++i)
    {
        total_charge+=charge[i];
        total_charge_squared+=charge[i]*charge[i];
    }

    n_empty_hits++;
    n_apv_empty_hits[APV_id]++;
    empty_mean_apv[APV_id] += total_charge/27.;
    empty_rms_apv[APV_id] += total_charge_squared/27.;
    empty_mean_hits += total_charge/27.;
    empty_rms_hits += total_charge_squared/27.;
}

void EmptyChannels::Finalize()
{
    for( int i = 0 ; i < n_apvs ; i++ )
    {
        if(n_apv_empty_hits[i] > 0)
        {
            empty_mean_apv[i] = empty_mean_apv[i]/n_apv_empty_hits[i];
            empty_rms_apv[i] = empty_rms_apv[i]/n_apv_empty_hits[i] - empty_mean_apv[i]*empty_mean_apv[i];
            if(empty_rms_apv[i] < 0)
                empty_rms_apv[i] = 0;
            empty_rms_apv[i] = TMath::Sqrt(empty_rms_apv[i]);
        }
    }
    if(n_empty_hits > 0)
    {
        empty_mean_hits = empty_mean_hits/n_empty_hits;
        empty_rms_hits = empty_rms_hits / n_empty_hits - empty_mean_hits * empty_mean_hits;
        if(empty_rms_hits < 0)
            empty_rms_hits = 0;
        empty_rms_hits = TMath::Sqrt(empty_rms_hits);
    }
}

int EmptyChannels::GetNEmptyHits() {return n_empty_hits;}
int EmptyChannels::GetNApvEmptyHits(int i) {return n_apv_empty_hits[i];}
double EmptyChannels::GetEmptyMeanApv(int i) {return empty_mean_apv[i];}
double EmptyChannels::GetEmptyRmsApv(int i) {return empty_rms_apv[i];}
double EmptyChannels::GetEmptyMeanHits() {return empty_mean_hits;}
double EmptyChannels::GetEmptyRmsHits() {return empty_rms_hits;}

