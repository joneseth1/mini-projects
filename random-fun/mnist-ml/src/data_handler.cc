#include "data_handler.hpp"


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
    FILE *f = fopen(path.c_str(), "rb");
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
                    d->append_to_feature_vector(element[0]);
                } else 
                {
                    printf("Error Reading from File for vectors. \n");
                    exit(1);
                }
            }
            data_array->push_back(d);
        }
        printf("Read and stored %lu feature vectors.\n", data_array->size());
    } else
    {
        printf("Could not find file.\n");
        exit(1);
    }
}

void data_handler::read_feature_labels(std::string path)
{
    uint32_t head[2]; 
    unsigned char bytes[4];
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
                printf("Error reading from file for labels. \n");
                exit(1);
            }
        }  
        printf("Correctly read and stored label\n", data_array->size());
    } else 
    {
        printf("Could not find file.\n");
        exit(1);
    }
}

void data_handler::split_data()
{

    printf("splitting train\n");
    printf("data size is %d\n", data_array->size());
    
    int half_size = data_array->size() / 2;
    printf("We are halfing the size for times sake so the acutal size before splitting is: %d\n", half_size);

    std::unordered_set<int> used_indexes;
    int train_size = half_size * TRAIN_SET_PERCENT;
    int test_size =  half_size * TEST_SET_PERCENT;
    int validation_size = half_size * VALIDATION_PERCENT;

    size_t count = 0; 
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

    count = 0;
    while(count < test_size)
    {
        int rand_index = rand() % data_array->size();
        if(used_indexes.find(rand_index) == used_indexes.end())
        {
            test_data->push_back(data_array->at(rand_index));
            used_indexes.insert(rand_index);
            count++;
        }
    }

    count = 0;
    while(count < validation_size)
    {
        int rand_index = rand() % data_array->size();
        if(used_indexes.find(rand_index) == used_indexes.end())
        {
            validation_data->push_back(data_array->at(rand_index));
            used_indexes.insert(rand_index);
            count++;
        }
    }
    printf("Training data_size: %lu. \n", training_data->size());
    printf("Test data_size: %lu. \n", test_data->size());
    printf("Validation data_size: %lu. \n", validation_data->size());
}

void data_handler::count_classes()
{
    int count = 0;
     
    for (unsigned i = 0; i < data_array->size(); i++)
    {
        if (class_map.find(data_array->at(i)->get_label()) == class_map.end())
        {
            class_map[data_array->at(i)->get_label()] = count;
            data_array->at(i)->set_enumerated_label(count);
            count++;
        }
    }
    num_classes = count; 
    printf("Number of classes is: %d\n", num_classes);
}

uint32_t data_handler::convert_to_little_endian(const unsigned char* bytes)
{
    return (uint32_t) ((bytes[0] << 24) |
                       (bytes[1] << 16) | 
                       (bytes[2] << 8)  | 
                       (bytes[3]));
}

std::vector<data *> * data_handler::get_training_data()
{
    return training_data;
}
std::vector<data *> * data_handler::get_test_data()
{
    return test_data;
}
std::vector<data *> * data_handler::get_validation_data()
{
    return validation_data;
}




/*
int main() 
{
    data_handler *dh = new data_handler();
    dh->read_feature_vector("./train-images-idx3-ubyte");
    dh->read_feature_labels("./train-labels-idx1-ubyte");
    dh->split_data();
    dh->count_classes();

    return 0;
}

*/