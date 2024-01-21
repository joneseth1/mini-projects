#include <iostream>
#include <fstream>
#include <Windows.h>
#include <chrono>
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

std::pair<int, int> collatz_prng(int n)
{
    int count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
            count++;
        }
    }

    return std::make_pair(n, count);
}

void write_binary_file(const std::string& filename, const std::vector<char>& data)
{
    std::ofstream file(filename, std::ios::binary);
    file.write(data.data(), data.size());
    file.close();
}

int main()
{
    int cursor = get_mouse_pos();

    auto currentTimePoint = system_clock::now();
    auto currentTimeInSeconds = duration_cast<seconds>(currentTimePoint.time_since_epoch()).count();

    long long seed = (currentTimeInSeconds / cursor);

    std::cout << "Seed: " << seed << std::endl;
    
    // Use Collatz as a PRNG and get the count
    std::pair<int, int> result = collatz_prng(seed);

    std::cout << "End Number: " << result.first << std::endl;
    std::cout << "Random Number: " << result.second << std::endl;

    // Generate random bytes based on the count
    std::vector<char> randomBytes(result.second);
    for (int i = 0; i < result.second; ++i)
    {
        result = collatz_prng(result.first); // Use Collatz again for more random numbers
        randomBytes[i] = static_cast<char>(result.first);
    }

    // Write the random bytes to a binary file
    std::string filename = "random_binary_file.bin";
    write_binary_file(filename, randomBytes);

    std::cout << "Random binary file created: " << filename << std::endl;

    return 0;
}
