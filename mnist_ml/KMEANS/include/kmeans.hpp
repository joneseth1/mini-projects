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

    cluster(data *initial_point)
    {
        centroid = new std::vector<double>;
        cluster_points = new std::vector<data *> ;

        for(auto value : *(initial_point->get_feature_vector()))
        {
            centroid->push_back(value);
        }

        cluster_points->push_back(initial_point);
        class_counts[initial_point->get_label()] = 1;
        most_frequent_class = initial_point->get_label();
    }

    void add_to_cluster(data *point)
    {
        int previous_size = cluster_points->size();

        cluster_points->push_back(point);
        for(int i = 0; i < centroid->size() - 1; i++)
        {
            double value = centroid->at(i);
            value *= previous_size;
            value += point->get_feature_vector_size();
            
            //TODO Need to test 
            value /= (double)cluster_points->size();
            centroid->at(i) = value;
        }

        if(class_counts->find(point->get_label()) == class_counts->end())
        {
            class_counts[point->get_label()] = 1;
        } else 
        {
            class_counts[point->get_label()]++;
        }

    }

} cluster_t;


#endif