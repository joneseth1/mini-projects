#include <iostream>
#include <fstream>

int main() {
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
    }

    std::cout << "JPG file header is valid" << std::endl;
    file.close();

    return 0;
}
