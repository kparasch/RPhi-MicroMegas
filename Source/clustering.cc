#include "clustering.h"

void r_clustering(vector<vector<int>> *r_clusters_hit_id, vector<vector<int>> *r_clusters_strip_id, vector<int> *good_hits_id, raw *raw_tree, int *connector_of_apv, int *strip_of_channel)
{
    vector<int> *r_hit_id = new vector<int>();
    vector<int> *r_hit_strip_id = new vector<int>();

    for(int i = 0 ; i < good_hits_id->size() ; i++)
    {
        int hit_id = good_hits_id->at(i);
        int APV_id = raw_tree->apv_id->at(hit_id);
        int APV_ch = raw_tree->apv_ch->at(hit_id);
        int strip_id = strip_of_channel[APV_ch+128*APV_id];
 
        if ( (connector_of_apv[APV_id] % 2 ) == 1 ) //if strip is r
        {
            r_hit_id->push_back(hit_id);
            r_hit_strip_id->push_back(strip_id);
        }
    }

    sort_for_strip(r_hit_id, r_hit_strip_id);
    
    vector<int> cluster;
    vector<int> strip_ids;
    for(int i = 0 ; i < r_hit_id->size() ; i++)
    {
        if( cluster.empty() )
        {
            cluster.push_back( r_hit_id->at(i) );
            strip_ids.push_back( r_hit_strip_id->at(i) );
            continue;
        }
        
        if( r_hit_strip_id->at(i) == ( r_hit_strip_id->at(i-1) + 1 ) )
        {
            cluster.push_back( r_hit_id->at(i) );
            strip_ids.push_back( r_hit_strip_id->at(i) );
        }
        else
        {
            r_clusters_hit_id->push_back(cluster);
            r_clusters_strip_id->push_back(strip_ids);
            cluster.clear();
            strip_ids.clear();
        }

    }
    r_clusters_hit_id->push_back(cluster);
    r_clusters_strip_id->push_back(strip_ids);

    delete r_hit_id;
    delete r_hit_strip_id;

    return;    


}

void sort_for_strip(vector<int> *r_hit_id, vector<int> *r_hit_strip_id)
{
    bool swapped;
    int n = r_hit_id->size();
    do
    {
        swapped = 0;
        for( int i = 1; i < n ; i++)
        {
            if( r_hit_strip_id->at(i-1) > r_hit_strip_id->at(i) )
            {
                std::iter_swap(r_hit_strip_id->begin() + i - 1, r_hit_strip_id->begin() + i); //in <algorithm>
                std::iter_swap(r_hit_id->begin() + i - 1, r_hit_id->begin() + i); //in <algorithm>
                swapped = 1;
            }
        }
        n-=1;
    } while(swapped);
}
