#ifndef __clustering_h__
#define __clustering_h__

#include <vector>
#include <algorithm>

#include "raw.h"

void characterize_clusters(vector<int> *cluster_is_big, vector<int> *r_big_cluster_id, int r_clusters);
void find_big_clusters(vector<vector<int>> *r_clusters_hit_id, vector<int> *big_cluster_id);
void r_clustering(vector<vector<int>> *r_clusters_hit_id, vector<vector<int>> *r_clusters_strip_id, vector<int> *good_hits_id, raw *raw_tree, int *connector_of_apv, int *strip_of_channel);
void sort_for_strip(vector<int> *r_hit_id, vector<int> *r_hit_strip_id);

#endif // __clustering_h__
