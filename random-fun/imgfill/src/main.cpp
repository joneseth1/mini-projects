#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>


namespace fs = std::filesystem;

struct Pixel 
{
    unsigned char red; 
    unsigned char green; 
    unsigned char blue; 
};


int process_img(std::string path)
{
    std::ifstream file(path, std::ios::binary);

     if (!file.is_open()) {
        std::cerr << "Error: Cannot open the file." << std::endl;
        return 1; 
    }

    char header[4];
    file.read(header, 4);

    // Check if it's a valid JPG file
    if (header[0] != (char)0xFF || header[1] != (char)0xD8 || header[2] != (char)0xFF || header[3] != (char)0xE0) {
        std::cerr << "Not a valid JPG file" << std::endl;
        return 1;
    } else {
        // Skip JPEG header
        file.seekg(2);

        // Read the file until the end to get pixel values
        std::vector<Pixel> pixels;
        char byte;
        int pixel_count = 0; 

        while (file.get(byte)) {
            Pixel pixel;
            pixel.red = static_cast<unsigned char>(byte);
            file.get(byte);
            pixel.green = static_cast<unsigned char>(byte);
            file.get(byte);
            pixel.blue = static_cast<unsigned char>(byte);
            pixels.push_back(pixel);

            pixel_count += 1;
        }

        // keep track of the pixel_count for neruons later
        std::cout << pixel_count << std::endl;
        file.close();
    }

    return 0;
    
}


int process_data(std::string DATA_DIR)
{

    for(const auto& entry : fs::recursive_directory_iterator(DATA_DIR)) 
    {
        if(std::filesystem::is_regular_file(entry.path())) 
        {
            process_img(entry.path().string());
        }
    }
    return 0;
}




int main() 
{
    std::string DATA_DIR = "C:/programs/random-fun/mini-projects/imgfill/images/";

    process_data(DATA_DIR);
    return 0;
}