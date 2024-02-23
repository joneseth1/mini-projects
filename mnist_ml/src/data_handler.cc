#include "data_handler.hpp";


data_handler::data_handler()
{
    data_array = new std::vector<data *>;
    test_data = new std::vector<data *>;
    training_data = new std::vector<data *>;
    validation_data = new std::vector<data *>;

}

data_handler::~data_handler()
{

}

void data_handler::read_feature_vector(std::string path)
{
    uint32_t head[4]; 
    unsigned char bytes[4];
    FILE *f = fopen(path.c_str(), "r");
    if(f)
    {
        for(int i = 0; i < 4; i++)
        {
            if(fread(bytes, sizeof(bytes), 1, f))
            {
                head[i] = convert_to_little_endian(bytes);
            }

        }
        printf("Done grabbing file header. \n");
        int image_size = head[2]*head[3];
        for (int i = 0; i < head[1]; i++)
        {
            data *d = new data();

        }
    }
}

void read_feature_vector(std::string path);
void read_feature_labels(std::string path);
void split_data();
void count_classes();

uint32_t convert_to_little_endian(const unsigned char* bytes);


std::vector<data *> * get_training_data();
std::vector<data *> * get_test_data();
std::vector<data *> * get_validation_data();