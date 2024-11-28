#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::string decode(const std::string& message_file) {
    std::ifstream file(message_file);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file '" << message_file << "'" << std::endl;
        return "";
    }

    std::cout << "File opened successfully: " << message_file << std::endl;

    // Initialize variables
    std::string line;
    std::vector<std::string> decoded_message;
    int last_number = 0;

    // Read each line of the file
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        std::string word;
        
        // Extract number and word from the line
        if (!(iss >> number >> word)) {
            break;
        }

        // Check if the number follows the pyramid pattern
        if (number == last_number + 1) {
            decoded_message.push_back(word);
            last_number = number;
        }
    }
    file.close();

    // Concatenate the decoded message
    std::string decoded_str;
    for (const auto& word : decoded_message) {
        decoded_str += word + " ";
    }
    // Remove the last space
    if (!decoded_str.empty()) {
        decoded_str.pop_back();
    }

    return decoded_str;
}

int main() {
    std::string message_file = "encoded_message.txt";
    std::string decoded_message = decode(message_file);
    std::cout << decoded_message << std::endl;
    return 0;
}
