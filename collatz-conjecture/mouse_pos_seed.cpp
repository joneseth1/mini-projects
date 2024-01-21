#include <iostream>
#include <fstream>
#include <Windows.h>
#include <chrono>
#include <bitset>
#include <vector>

using namespace std::chrono;

int get_mouse_pos()
{
    while (true)
    {
        POINT p;
        if (GetCursorPos(&p))
        {
            return p.x;
        }
        Sleep(1000);
    }
}

int collatz_prng(int n)
{
    int count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            count++;
        }
        else
        {
            n = 3 * n + 1;
        }
    }

    return count;
}

void write_binary_file(const std::string& filename, int number)
{
    std::ofstream file(filename, std::ios::binary);

    // Convert the integer to its binary representation as a string
    std::bitset<32> binaryRepresentation(number);
    std::string binaryString = binaryRepresentation.to_string();

    // Write the binary string to the file
    file.write(binaryString.c_str(), binaryString.size());

    file.close();
}

int main()
{
    int cursor = get_mouse_pos();

    auto currentTimePoint = system_clock::now();
    auto currentTimeInSeconds = duration_cast<seconds>(currentTimePoint.time_since_epoch()).count();

    long long seed = (currentTimeInSeconds / cursor);

    std::cout << "Seed: " << seed << std::endl;

    // Use Collatz as a PRNG and get the random number
    int randomNumber = collatz_prng(seed);

    std::cout << "Random Number: " << randomNumber << std::endl;

    // Write the random number to a binary file
    std::string filename = "random_binary_file.bin";
    write_binary_file(filename, randomNumber);

    std::cout << "Random binary file created: " << filename << std::endl;

    return 0;
}
