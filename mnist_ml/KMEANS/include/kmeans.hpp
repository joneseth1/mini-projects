#ifndef __KMEAN_HPP
#define __KMEAN_HP


#include "common.hpp"
#include "data_handler.hpp"
#include <unordered_set>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <map>

typedef struct cluster 
{

    std::vector<double> *centroid; 
    std::vector<data *> *cluster_points;
    std::map<int, int> class_counts;
    int most_frequent_class;

    cluster(data *initail_point)
    {
        centroid = new std::vector<double>;
        cluster_points = new std::vector<data *> ;

        for(auto value : *(initail_point->get_feature_vector()))
        {
            centroid->push_back(value);
        }

        cluster_points->push_back(initail_point);
        class_counts[initail_point->get_label()] = 1;
        most_frequent_class = initail_point->get_label();
    }

    void add_to_cluster(data *point)
    {
        
    }

} cluster_t;


#endif