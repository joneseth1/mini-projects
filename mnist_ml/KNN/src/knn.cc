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

void knn::find_knearest(data *query_point);

void knn::set_training_data(std::vector<data *> *vect)
{
    training_data = vect;
}

void knn::test_data(std::vector<data *> *vect)
{
    test_data = vect;
}

void knn::validation_data(std::vector<data *> *vect)
{
    validation_data = vect;
}

void knn::set_k(int val)
{
    k = val;
}

int knn::predict();

double knn::calc_distance(data* query_point, data* input)
{
    double distance = 0.0;
#ifdef EUCLID
    for(unsigned i = 0; i < query_point->get_feature_vector(); i++)
    {
        distance = pow(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i), 2);
    }
    distance = sqrt(distance);
#elif defined MANHATTAN
return distance;
}

double knn::validate_performance();
double knn::test_performance();