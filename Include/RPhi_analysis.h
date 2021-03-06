#ifndef __tree_make_h__
#define __tree_make_h__
#include <iostream>
#include <vector>

#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TApplication.h>
#include <TBenchmark.h>

#include "raw.h"
#include "data.h"
#include "Histograms.h"
#include "channels_map.h"
#include "event_functions.h"
#include "clustering.h"
#include "fitting_functions.h"
#include "dumping.h"
#include "EmptyChannels.h"

void summary(int *counters);

using namespace std;
#endif
