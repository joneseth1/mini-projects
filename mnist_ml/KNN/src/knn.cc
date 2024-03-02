#include "knn.hpp"
#include "data_handler.hpp"
#include "stdint.h"
#include <cmath>
#include <limits>
#include <map>



knn::knn(int)
{
    k = val;
}

knn::knn()
{
    //just need to be declared 
}

knn::~knn()
{
    //just need to be declared 
}

void knn::find_knearest(data *query_point);
void knn::set_training_data(std::vector<data *> *vect);
void knn::test_data(std::vector<data *> *vect);
void knn::validation_data(std::vector<data *> *vect);
void knn::set_k(int val);

int knn::predict();
double knn::calc_distance(data* query_point, data* input);
double knn::validate_performance();
double knn::test_performance();