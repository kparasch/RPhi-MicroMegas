#ifndef __dumping_h__
#define __dumping_h__

#include <vector>

#include "raw.h"


void dump(int *counter, int n_hits, vector<int> *good_hits_id, raw *raw_tree, vector<vector<int>> *r_clusters_hit_id, int *connector_of_apv);

#endif //__dumping_h__
