#include "dumping.h"

void dump(int *counter, int n_hits, vector<int> *good_hits_id, raw *raw_tree, vector<vector<int>> *r_clusters_hit_id, int *connector_of_apv)
{
    bool active_phi=0;
    for(int i = 0 ; i < n_hits ; i++)
    {
        if(connector_of_apv[raw_tree->apv_id->at(i) % 2 == 0])
        {
            active_phi=1;    
            break;
        }
    }
    if(active_phi)
        counter[3]++;

    bool active_r=0;
    for(int i = 0 ; i < n_hits ; i++)
    {
        if(connector_of_apv[raw_tree->apv_id->at(i) % 2 == 1])
        {
            active_r=1;    
            break;
        }
    }
    if(active_r)
         counter[4]++;

    if(active_phi && active_r)
        counter[5]++;

    bool good_active_phi = 0;
    for(int i = 0 ; i < good_hits_id->size() ; i++)
    {
        if(connector_of_apv[raw_tree->apv_id->at(good_hits_id->at(i))] % 2 == 0)
        {
            good_active_phi=1;    
            break;
        }
    }
    if(good_active_phi)
        counter[6]++;

    bool good_active_r = 0;
    for(int i = 0 ; i < good_hits_id->size() ; i++)
    {
        if(connector_of_apv[raw_tree->apv_id->at(good_hits_id->at(i))] % 2 == 1)
        {
            good_active_r=1;    
            break;
        }
    }
    if(good_active_r)
        counter[7]++;

    if(good_active_phi && good_active_r)
        counter[8]++;

    if(r_clusters_hit_id->size()>0)
        counter[9]++;

    bool biggerthan20=0;
    if(r_clusters_hit_id->size() > 0 && r_clusters_hit_id->size() < 20)
    {
        counter[10]++;
        for(int i = 0 ; i < r_clusters_hit_id->size() ; i++)
        {
            if(r_clusters_hit_id->at(i).size() > 20)
            {
                biggerthan20=1;
                break;           
            }
        }
    }
    if(!biggerthan20)
        counter[11]++;

}
