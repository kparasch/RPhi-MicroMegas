//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Oct 22 11:53:49 2016 by ROOT version 6.07/05
// from TTree raw/rawapvdata
// found on file: run94.root
//////////////////////////////////////////////////////////

#ifndef raw_h
#define raw_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
using namespace std;
class raw {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          apv_evt;
   Int_t           time_s;
   Int_t           time_us;
   vector<unsigned int> *apv_fecNo;
   vector<unsigned int> *apv_id;
   vector<unsigned int> *apv_ch;
   vector<string>  *mm_id;
   vector<unsigned int> *mm_readout;
   vector<unsigned int> *mm_strip;
   vector<vector<short> > *apv_q;
   UInt_t          apv_presamples;

   // List of branches
   TBranch        *b_apv_evt;   //!
   TBranch        *b_time_s;   //!
   TBranch        *b_time_us;   //!
   TBranch        *b_apv_fecNo;   //!
   TBranch        *b_apv_id;   //!
   TBranch        *b_apv_ch;   //!
   TBranch        *b_mm_id;   //!
   TBranch        *b_mm_readout;   //!
   TBranch        *b_mm_strip;   //!
   TBranch        *b_apv_q;   //!
   TBranch        *b_apv_presamples;   //!

   raw(TTree *tree);
   virtual ~raw();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef raw_cxx
raw::raw(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("run94.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("run94.root");
      }
      f->GetObject("raw",tree);

   }
   Init(tree);
}

raw::~raw()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t raw::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t raw::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void raw::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   apv_fecNo = 0;
   apv_id = 0;
   apv_ch = 0;
   mm_id = 0;
   mm_readout = 0;
   mm_strip = 0;
   apv_q = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("apv_evt", &apv_evt, &b_apv_evt);
   fChain->SetBranchAddress("time_s", &time_s, &b_time_s);
   fChain->SetBranchAddress("time_us", &time_us, &b_time_us);
   fChain->SetBranchAddress("apv_fecNo", &apv_fecNo, &b_apv_fecNo);
   fChain->SetBranchAddress("apv_id", &apv_id, &b_apv_id);
   fChain->SetBranchAddress("apv_ch", &apv_ch, &b_apv_ch);
   fChain->SetBranchAddress("mm_id", &mm_id, &b_mm_id);
   fChain->SetBranchAddress("mm_readout", &mm_readout, &b_mm_readout);
   fChain->SetBranchAddress("mm_strip", &mm_strip, &b_mm_strip);
   fChain->SetBranchAddress("apv_q", &apv_q, &b_apv_q);
   fChain->SetBranchAddress("apv_presamples", &apv_presamples, &b_apv_presamples);
   Notify();
}

Bool_t raw::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void raw::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t raw::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef raw_cxx
