#ifndef __channels_map_h__
#define __channels_map_h__

#include <iostream>

#include <TMath.h>

void map_channels(int *strip, int *apv_Config, int second_chamber_present);
int channel_To_Strip_R12(int channel);
int channel_To_Strip_R3(int channel);
int channel_To_Strip_R4(int channel);
int channel_To_Strip_APHI(int channel);
int channel_To_Strip_BPHI(int channel);

#endif //__channels_map_h__
