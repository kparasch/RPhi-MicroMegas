#ifndef __tree_make_h__
#define __tree_make_h__
#include <iostream>
#include <vector>

#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include <TH1D.h>
#include <TCanvas.h>

#include "raw.h"
#include "hist_generator.h"

void Initialize_array(int* array, int size);
void Initialize_array(double* array, int size);

using namespace std;
#endif
