#include "RPhi_analysis.h"

int main(int argc, char* argv[])
{
    //argv[1] = rootfile input
    //argv[2] = second chamber present
    //argv[3] = config of apv to physics connector chamber 1
    //argv[4] = config of apv to physics connector chamber 2
    //

    int second_chamber_present = atoi(argv[2]);
    int n_chambers = 1 + second_chamber_present;
    int no_of_apvs = 5 + 5*second_chamber_present;
    int v0 = 1; //v for verbosity (level 0)
    int v1 = 0; //v for verbosity (level 1)

    TH1D *hist_vpeak[no_of_apvs];
    Generate_Hists_Vpeak(hist_vpeak, 0);
  
    TH1D *hist_qpeak[no_of_apvs];
    Generate_Hists_Qpeak(hist_qpeak, 0);
  
    cout << "Number of chambers detected: " << n_chambers << endl;
    
    int apv_config[n_chambers];
    for(int k = 0; k < n_chambers ; k++)
    {
        apv_config[k]=atoi(argv[3+k]);
    }
    int strip_of_channel[128*no_of_apvs];
    map_channels(strip_of_channel, apv_config, second_chamber_present);

    TFile *root_file = new TFile(argv[1],"READ");
    raw *raw_tree = new raw((TTree*)root_file->Get("raw"));
    data *data_tree = new data((TTree*)root_file->Get("data"));

    int nentries = (raw_tree->fChain)->GetEntries(); 
    cout <<"Number of entries detected: " <<  nentries << endl;
         
    for(int i = 0; i < nentries; i++)
    {
        raw_tree->GetEntry(i);
        data_tree->GetEntry(i);
        if(v0) cout << "Number of hits detected: " << raw_tree->apv_q->size() << endl;
        for( int hit = 0; hit < (int)raw_tree->apv_q->size() ; hit++ )        
        {
            if(v0) cout << "Proccessing hit: " << hit << endl;
            double charge[27];
            for( int j = 0 ; j < 27 ; j++ )
            {
                charge[j]=raw_tree->apv_q->at(hit).at(j);
                if(v1) cout << "\t" << j << "\t" << charge[j] << endl;
            }
            if(v0) cout << "max is " << data_tree->apv_qmax->at(hit) << " at " << data_tree->apv_tbqmax->at(hit) << endl;
        }
        cin.get();
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


