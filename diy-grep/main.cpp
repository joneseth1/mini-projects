#include <iostream>
#include <fstream>
#include <string>


// Takes two params, the filename and string pattern to search for 
void searchFile(const std::string& filename, const std::string& pattern) {
	std::ifstream file(filename);
	if (!file.is_open()) { // Checks to see if file can be opened, if not then errors out 
		std::cerr << "ERROR: Could not open file " << filename << std::endl; 
		return; 
	}

	// Reads line by line and checks if pattern is found
	// If pattern is found, then prints it 
	std::string line;
	int lineNumber = 0;

	while (std::getline(file, line)) {
		lineNumber++; 
		size_t found = line.find(pattern);
		if (found != std::string::npos) {
			std::cout << "At Line " << lineNumber << ": " << line << std::endl; 
		}
	}

	file.close();
}



int main(int argc, char* argv[]) {
	// Check for correct number of args
	if ( argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <filename> <pattern>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string pattern = argv[2];

 
	searchFile(filename, pattern);


	return 0;
}