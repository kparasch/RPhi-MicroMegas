#include "clustering.h"

/*void characterize_clusters(vector<int> *cluster_is_big, vector<int> *r_big_cluster_id, int r_clusters)
{
    int big_counter = 0;
    for(int i = 0; i < r_clusters ; i++)
    {
        if(big_counter > r_big_cluster_id) big_counter -=1;
        if(r_big_cluster_id->at(big_counter)==i)
        {
            cluster_is_big->push_back(1);
            big_counter+=1;
        }
        else
        {
            cluster_is_big->push_back(0);
        }
    }
    return;
}
*/
void find_big_clusters(vector<vector<int>> *r_clusters_hit_id, vector<int> *big_cluster_id)
{
    for(int i = 0 ; i < r_clusters_hit_id->size() ; i ++)
    {
        if(r_clusters_hit_id->at(i).size() > 1)
            big_cluster_id->push_back(i);
    }
    return;
}

void r_clustering(vector<vector<int>> *r_clusters_hit_id, vector<vector<int>> *r_clusters_strip_id, vector<int> *good_hits_id, raw *raw_tree, int *connector_of_apv, int *strip_of_channel)
{
    bool good_r_cluster_hit = 0;
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
            good_r_cluster_hit = 1;
        }
    }
    if(!good_r_cluster_hit) return;
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
