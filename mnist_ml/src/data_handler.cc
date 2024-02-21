#include "data_handler.hpp";


data_handler::data_handler()
{
    data_array = new std::vector<data *>;
    test_data = new std::vector<data *>;
    training_data = new std::vector<data *>;
    validation_data = new std::vector<data *>;

}

void data_handler::read_feature_vector(std::string path)

void read_feature_vector(std::string path);
void read_feature_labels(std::string path);
void split_data();
void count_classes();

uint32_t convert_to_little_endian(const unsigned char* bytes);


std::vector<data *> * get_training_data();
std::vector<data *> * get_test_data();
std::vector<data *> * get_validation_data();