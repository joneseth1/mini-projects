#include "../include/kmeans.hpp"


kmeans::kmeans(int k)
{
    int num_clusters = k; 
    clusters = new std::vector<cluster_t *>;
    used_indexes = new std::unordered_set<int>;
}

void kmeans::init_clusters()
{
    for(int i = 0; i < num_clusters; i++)
    {
        int index = (rand() % training_data->size());
        while(used_indexes->find(index) != used_indexes->end())
        {
            index = (rand() % training_data->size());
        }
        clusters->push_back(new cluster(training_data->at(index)));
        used_indexes->insert(index);
    }
}
void kmeans::init_clusters_for_each_class();
void kmeans::train();
double kmeans::euclidean_distance(std::vector<double> *, data *);
double kmeans::validate();
double kmeans::test();