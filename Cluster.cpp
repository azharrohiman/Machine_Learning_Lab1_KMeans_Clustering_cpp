#include "Cluster.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// for testing
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>

using namespace RHMMUH005;
using namespace std;

namespace RHMMUH005 {

	Cluster::Cluster() {

	}

	Cluster::Cluster(Point p, int id) {
		Cluster::mean = p;
		Cluster::id = id;
	}

	// destructor
	Cluster::~Cluster() {
		
	}

	Point Cluster::getPoints() {
		return Cluster::mean;
	}
};

