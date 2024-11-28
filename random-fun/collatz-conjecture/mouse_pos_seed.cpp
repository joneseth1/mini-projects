#include <iostream>
#include <fstream>
#include <Windows.h>
#include <chrono>
#include <bitset>
#include <vector>
#include <random>

using namespace std::chrono;

int get_mouse_pos() {
    POINT p;
    if (GetCursorPos(&p)) {
        return p.x;
    } else {
        return -1;
    }
}

std::vector<int> collatz_prng(int n, int i) {
    std::vector<int> counts;
    int iterations = 0;

    // Use random_device to generate a truly random seed
    std::random_device rd;
    std::mt19937 gen(rd());

    while (iterations <= i) {
        int count = 0;
        int originalN = n; // Save the original value of n

        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
                count++;
            } else {
                n = 3 * n + 1;
            }
        }

        counts.push_back(count);

        // Change n for the next iteration by generating a new random seed
        n = gen();

        iterations++;
    }

    return counts;
}


void write_binary_file(const std::string& filename, const std::vector<int>& numbers) {
    std::ofstream file(filename, std::ios::binary);

    for (int number : numbers) {
        // Convert each number to its binary representation as a string
        std::bitset<32> binaryRepresentation(number);
        std::string binaryString = binaryRepresentation.to_string();

        // Write the binary string to the file
        file.write(binaryString.c_str(), binaryString.size());
        std::cout << "Writing to file... " << std::endl;
        file.put('\n');
    }

    file.close();
}

int main() {
    int cursor = get_mouse_pos();

    if (cursor == -1) {
        std::cerr << "Error getting mouse position." << std::endl;
        return 1;  // Return an error code
    }

    auto currentTimePoint = system_clock::now();
    auto currentTimeInSeconds = duration_cast<seconds>(currentTimePoint.time_since_epoch()).count();

    long long seed = (currentTimeInSeconds / cursor);

    std::cout << "Seed: " << seed << std::endl;

    // Use Collatz as a PRNG and get the random numbers
    std::vector<int> randomNumbers = collatz_prng(seed, 2);

    // Write the random numbers to a binary file
    std::string filename = "random_binary_file.bin";
    write_binary_file(filename, randomNumbers);

    std::cout << "Random binary file created: " << filename << std::endl;

    return 0;
}