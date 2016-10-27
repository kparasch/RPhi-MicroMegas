#include <iostream>

#include <TH1D.h>
#include <TApplication.h>
#include <TCanvas.h>

#include "channels_map.h"

using namespace std;

int main(int argc, char * argv[])
{
    TApplication app("app", &argc, argv);
    
    TH1D* empty_channels = new TH1D("empty_channels", "empty_channels", 642, -1.5, 640.5);

    TH1D* r12_strips = new TH1D("r12_strips", "r12_strips", 642, -1.5, 640.5);
    TH1D* r3_strips = new TH1D("r3_strips", "r3_strips", 642, -1.5, 640.5);
    TH1D* r4_strips = new TH1D("r4_strips", "r4_strips", 642, -1.5, 640.5);
    TH1D* aphi_strips = new TH1D("aphi_strips", "aphi_strips", 642, -1.5, 640.5);
    TH1D* bphi_strips = new TH1D("bphi_strips", "bphi_strips", 642, -1.5, 640.5);
    
    TH1D* all_strips = new TH1D("all_strips", "all_strips", 642, -1.5, 640.5);

    int second_chamber = 0;
    int strip[128*(5+5*second_chamber)];
    int apv_config[1];
    apv_config[0] = 12345;
    
    map_channels(strip, apv_config, 0);
    //strip[channel-1 + 128*(apv+5*chamber)]
    
    for(int k = 0 ; k < second_chamber+1 ; k ++)
    {
        for( int j = 0 ; j < 5; j++)
        {
            for( int i = 0; i < 128; i++)
            {
                if(strip[i+128*(j+5*k)] == -1)
                    empty_channels->Fill(i+1+128*(j+5*k));
                if(j==0)
                    r3_strips->Fill(strip[i+128*(j+5*k)]);
                if(j==1)
                    aphi_strips->Fill(strip[i+128*(j+5*k)]);
                if(j==2)
                    r4_strips->Fill(strip[i+128*(j+5*k)]);
                if(j==3)
                    bphi_strips->Fill(strip[i+128*(j+5*k)]);
                if(j==4)
                    r12_strips->Fill(strip[i+128*(j+5*k)]);
                all_strips->Fill(strip[i+128*(j+5*k)]);
            }
        }
    }

    TCanvas* c1 = new TCanvas();
    empty_channels->Draw("hist");

    TCanvas* c2 = new TCanvas();
    r3_strips->Draw("hist");

    TCanvas* c3 = new TCanvas();
    r12_strips->Draw("hist");

    TCanvas* c4 = new TCanvas();
    r4_strips->Draw("hist");

    TCanvas* c5 = new TCanvas();
    aphi_strips->Draw("hist");

    TCanvas* c6 = new TCanvas();
    bphi_strips->Draw("hist");

    TCanvas* c7 = new TCanvas();
    all_strips->Draw("hist");

    app.Run(kTRUE);
    return 0;

    
}
