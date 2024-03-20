#include <iostream>
#include <fstream>
#include <vector>


struct Pixel {
    unsigned char red; 
    unsigned char green; 
    unsigned char blue; 
};


int img_loader() {
    std::ifstream file("C:/programs/random-fun/mini-projects/imgfill/images/image.jpg", std::ios::binary); 

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



int main() 
{
    img_loader();
    return 0;
}