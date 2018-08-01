#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "Point.h"

using namespace std;

struct Points {
	float x, y;
};

float distance(RHMMUH005::Point& point1, RHMMUH005::Point point2) {

	float x = point1.x - point2.x;
	float y = point1.y - point2.y;

	float dist = pow(x, 2) + pow(y, 2);
	return sqrt(dist);
};

int main(int argc, char* argv[]) {

	char comma;

	//vector<Points> point;
	vector<RHMMUH005::Point> point;
	RHMMUH005::Point coords;

	ifstream file("input");

	while (file >> coords.x >> comma >> coords.y) {
		point.push_back(coords);
	}

	for (int i = 0; i < point.size(); i++) {
		cout << point.at(i).x << " " << point.at(i).y << endl;
	}

	cout << distance(point[0], point[4]) << endl;

	return 0;
}
