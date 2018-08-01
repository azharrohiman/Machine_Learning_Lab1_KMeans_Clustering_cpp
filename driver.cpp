#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <map>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace RHMMUH005;

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
	vector<Point> point;
	Point coords;

	vector<Cluster> clusters;

	vector<float> cluster1Distances;
	vector<float> cluster2Distances;
	vector<float> cluster3Distances;

	vector<Point> group_one;
	vector<Point> group_two;
	vector<Point> group_three;

	ifstream file("input");

	while (file >> coords.x >> comma >> coords.y) {
		point.push_back(coords);
	}

	clusters.push_back(Cluster(point.at(0), 1));
	clusters.push_back(Cluster(point.at(3), 2));
	clusters.push_back(Cluster(point.at(6), 3));

	for (int i = 0; i < clusters.size(); i++) {
		for (int j = 0; j < point.size(); j++) {
			if (i == 0) {
				cluster1Distances.push_back(distance(point.at(j), clusters.at(i).getPoints()));
			}

			if (i == 1) {
				cluster2Distances.push_back(distance(point.at(j), clusters.at(i).getPoints()));
			}

			if (i == 2) {
				cluster3Distances.push_back(distance(point.at(j), clusters.at(i).getPoints()));
			}
		}
	}

	for (int i = 0; i < cluster1Distances.size(); i++) {
		if (cluster1Distances.at(i) < cluster2Distances.at(i)) {
			if (cluster1Distances.at(i) < cluster3Distances.at(i)) {
				group_one.push_back(point.at(i));
			}

			else {
				group_three.push_back(point.at(i));
			}
		}

		else if (cluster2Distances.at(i) < cluster3Distances.at(i)) {
			group_two.push_back(point.at(i));
		}

		else {
			group_three.push_back(point.at(i));
		}
	}

	/*
	for (int i = 0; i < group_three.size(); i++) {
		cout << group_three.at(i).x << " " << group_three.at(i).y << endl;
	}
	*/

	return 0;
}
