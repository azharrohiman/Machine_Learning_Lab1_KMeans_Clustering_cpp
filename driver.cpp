#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <math.h>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace RHMMUH005;

struct Points {
	double x, y;
};

double distance(RHMMUH005::Point& point1, RHMMUH005::Point point2) {

	//cout << std::fixed;
	//cout << std::setprecision(1);

	double x = point1.x - point2.x;
	double y = point1.y - point2.y;

	double dist = pow(x, 2) + pow(y, 2);
	//cout << dist << endl;
	return sqrt(dist);
};

Point calculateMeanPoint(vector<Point> group) {
	//cout << std::fixed;
	//cout << std::setprecision(1);

	double x = 0;
	double y = 0;

	for (int i = 0; i < group.size(); i++) {
		x = x + group.at(i).x;
		y = y + group.at(i).y;
	}
	//cout << x/group.size() << endl;

	Point mean;
	if (group.size() != 0) {
		mean.x = x/group.size();
		mean.y = y/group.size();
	}

	return mean;
}

bool compareMeans(vector<Point> group, Point points) {
	//cout << std::fixed;
	//cout << std::setprecision(1);

	double x = 0;
	double y = 0;

	for (int i = 0; i < group.size(); i++) {
		x = x + group.at(i).x;
		y = y + group.at(i).y;
	}

	if (group.size() != 0) {
		x = x/group.size();
		y = y/group.size();
	}

	//cout << x << " and " << points.x << " " << y << " and " << points.y << endl;

	if (x == points.x && y == points.y) {
		return false;
	}

	else {
		return true;
	}
}

int main(int argc, char* argv[]) {

	cout << std::fixed;
	cout << std::setprecision(1);

	char comma;
	bool k_mean_iteration = true;

	//vector<Points> point;
	vector<Point> point;
	Point coords;

	//vector<Cluster> clusters;
	vector<Point> clusters;

	vector<double> cluster1Distances;
	vector<double> cluster2Distances;
	vector<double> cluster3Distances;

	vector<Point> group_one;
	vector<Point> group_two;
	vector<Point> group_three;

	ifstream file("input");

	while (file >> coords.x >> comma >> coords.y) {
		point.push_back(coords);
	}

	clusters.push_back(point.at(0));
	clusters.push_back(point.at(3));
	clusters.push_back(point.at(6));

	while (k_mean_iteration) {

		for (int i = 0; i < clusters.size(); i++) {
			for (int j = 0; j < point.size(); j++) {
				if (i == 0) {
					cluster1Distances.push_back(distance(point.at(j), clusters.at(i)));
				}

				if (i == 1) {
					cluster2Distances.push_back(distance(point.at(j), clusters.at(i)));
				}

				if (i == 2) {
					cluster3Distances.push_back(distance(point.at(j), clusters.at(i)));
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

		if (compareMeans(group_one, clusters.at(0)) || compareMeans(group_two, clusters.at(1)) || compareMeans(group_three, clusters.at(2))) {

			clusters.clear();
			cluster1Distances.clear();
			cluster2Distances.clear();
			cluster3Distances.clear();

			clusters.push_back(calculateMeanPoint(group_one));
			clusters.push_back(calculateMeanPoint(group_two));
			clusters.push_back(calculateMeanPoint(group_three));

			group_one.clear();
			group_two.clear();
			group_three.clear();
		}

		else {
			k_mean_iteration = false;
		}
		

		for (int i = 0; i < clusters.size(); i++) {
			cout << clusters.at(i).x << " " << clusters.at(i).y << endl;
		}
		cout << endl;

	}

	return 0;
}
