#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
#include <fstream>

struct Points {
	float x, y;
};

int main(int argc, char* argv[]) {

	float x, y;
	char comma;

	std::ifstream file("input");

	while (file >> x >> comma >> y) {
		std::cout << x << " " << y << std::endl;

		//std::cout << x << std::endl;
	}

	return 0;
}
