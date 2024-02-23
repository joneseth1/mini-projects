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
        printf("Done grabbing input file header. \n");
        int image_size = head[2]*head[3];
        for (int i = 0; i < head[1]; i++)
        {
            data *d = new data();
            uint8_t element[1];
            for (int j = 0; j < image_size; j++)
            {
                if(fread(element, sizeof(element), 1, f))
                {
                    d->appended_to_feature_vector(element[0]);
                }
                printf("Error Reading from File . \n");
                exit(1);
            }
            data_array->push_back(d);
        }
        printf("Read and stored %lu reafcture vectors.\n", data_array->size());
    } else
    {
        printf("Could not find file.\n");
        exit(1);
    }
}

void data_handler::read_feature_labels(std::string path)
{
    uint32_t head[2]; 
    unsigned char bytes[2];
    FILE *f = fopen(path.c_str(), "r");
    if(f)
    {
        for(int i = 0; i < 2; i++)
        {
            if(fread(bytes, sizeof(bytes), 1, f))
            {
                head[i] = convert_to_little_endian(bytes);
            }

        }
        printf("Done grabbing label file header. \n");
       for(int i = 0; i < head[1]; i++)
       {
        uint8_t element[1];
        if(fread(element, sizeof(element), 1, f))
        {
            data_array->at(i)->set_label(element[0]);
        } else 
        {
            printf("Error reading from file. \n");
            exit(1);
        }  
        printf("Read and sotred label.\n");
    }
    } else 
            {
                printf("Could not find file.\n");
                exit(1);
            }
}

void data_handler::split_data()
{
    std::unordered_set<int> used_indexes;
    int train_size = data_array->size() * TRAIN_SET_PERCENT;
    int test_size =  data_array->size() * TEST_SET_PERCENT;
    int validation_size = data_array->size() * VALIDATION_PERCENT;

    int count = 0; 
    while(count < train_size)
    {
        int rand_index = rand() % data_array->size();
        if(used_indexes.find(rand_index) == used_indexes.end())
        {
            training_data->push_back(data_array->at(rand_index));
            used_indexes.insert(rand_index);
            count++;
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