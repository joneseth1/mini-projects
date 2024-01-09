#include <iostream>
#include <fstream>
#include <string>


void searchFile(const std::string& filename, const std::string& pattern) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "ERROR: Could not open file " << filename << std::endl;
		return; 
	}
}



int main(int argc, char* argv[]) {

	return 0;
}