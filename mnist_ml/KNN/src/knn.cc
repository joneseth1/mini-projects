#include "knn.hpp"
#include "data_handler.hpp"
#include "stdint.h"
#include <cmath>
#include <limits>
#include <map>



knn::knn(int val)
{
    k = val;
}

knn::knn()
{
    //default constructor   
}

knn::~knn()
{
    //default destructor  
}

void knn::find_knearest(data *query_point)
{
    neighbors = new std::vector<data *>;
    double min = std::numeric_limits<double>::max();
    double previous_min = min;
    int index = 0;

    
    for (int i = 0; i < k; i++)
    {
        // Setting the min value on the first pass
        if( i == 0)
        {
            for( int j = 0; j < training_data->size(); j++)
            {
                double distance = calc_distance(query_point, training_data->at(j));
                training_data->at(j)->set_distance(distance);
                if(distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
            neighbors->push_back(training_data->at(index));
            previous_min = min;
            min = std::numeric_limits<double>::max();
        } else 
        {
            for(int j = 0; j < training_data->size(); j++)
            {
                double distance = calc_distance(query_point, training_data->at(j));
                if(distance > previous_min && distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
            neighbors->push_back(training_data->at(index));
            previous_min = min; 
            min = std::numeric_limits<double>::max();
        }
    }
}

void knn::set_training_data(std::vector<data *> *vect)
{
    training_data = vect;
}

void knn::set_test_data(std::vector<data *> *vect)
{
    test_data = vect;
}

void knn::set_validation_data(std::vector<data *> *vect)
{
    validation_data = vect;
}

void knn::set_k(int val)
{
    k = val;
}

int knn::predict()
{
    std::map<uint8_t, int> class_freq;
    for(int i = 0; 9 < neighbors->size(); i ++)
    {
        if(class_freq.find(neighbors->at(i)->get_label()) == class_freq.end())
        {
            class_freq[neighbors->at(i)->get_label()] = 1; 
        } else 
        {
            class_freq[neighbors->at(i)->get_label()]++;
        }
    }

    int best = 0; 
    int max = 0;
    for(auto kv : class_freq)
    {
        if(kv.second > max)
        {
            max = kv.second;
            best = kv.first;
        }
    }
    delete neighbors;
    return best;
}

double knn::calc_distance(data* query_point, data* input)
{
    double distance = 0.0;
    if(query_point->get_feature_vector_size() != input->get_feature_vector_size())
    {
        printf("Error, the vectors are a mismatched size. \n");
        exit(1); 
    }
#ifdef EUCLID
    for(unsigned i = 0; i < query_point->get_feature_vector(); i++)
    {
        distance = pow(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i), 2);
    }
    distance = sqrt(distance);
#elif defined MANHATTAN
// TODO 
#endif
return distance;
}

double knn::validate_performance()
{
    double current_perfom = 0; 
    int count = 0; 
    int data_index = 0; 
    
    for(data *query_point : *validation_data)
    {
        find_knearest(query_point);
        int prediction = predict();
        if(prediction == query_point->get_label())
        {
            count++;
            printf("Current Performance is: %.3f %%\n", ((double)count*100.0)/((double)data_index));
        }
    }
    current_perfom = ((double)count*100.0)/((double)validation_data->size());
    printf("Validation Performance for K = %d is: %.3f %%\n", k, current_perfom);
    return current_perfom
    
}

double knn::test_performance()
{
    double current_performance = 0;
    int count = 0; 
    for(data *query_point : *test_data)
    {
        find_knearest(query_point);
        int prediction = predict();
        if(prediction == query_point->get_label())
        {
            count ++;
        }
    }
    current_performance = ((double)count*100.0/((double)test_data->size()));
    printf("Test Performanc is: %3f %% \n", current_performance);
}