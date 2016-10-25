#include "RPhi_analysis.h"

int main(int argc, char* argv[])
{
    //argv[1] = rootfile input
    //argv[2] = second chamber present

    int second_chamber_present = atoi(argv[2]);
    int n_chambers = 1 + second_chamber_present;
    int no_of_apvs = 5 + 5*second_chamber_present;

    TH1D *hist_vpeak[no_of_apvs];
    Generate_Hists_Vpeak(hist_vpeak, 0);
  
    TH1D *hist_qpeak[no_of_apvs];
    Generate_Hists_Qpeak(hist_qpeak, 0);
  
    cout << "Number of chambers detected: " << n_chambers << endl;
 
    raw *raw_tree;
    TFile *root_file = new TFile(argv[1],"READ");
    raw_tree = new raw((TTree*)root_file->Get("raw"));

    int nentries = (raw_tree->fChain)->GetEntries(); 
    cout <<"Number of entries detected: " <<  nentries << endl;
         
    for(int i = 0; i < nentries; i++)
    {
        


    }

    delete root_file;
    delete raw_tree;
      

}

void Initialize_array(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i]=0;
    }
}  

void Initialize_array(double* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i]=0;
    }
}  


