#include "Point.h"
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

	Point::Point() {

	}

	// default constructor
	Point::Point(double x, double y, int id) {
		Point::x = x;
		Point::y = y;
		Point::id = id;
	}

	// destructor
	Point::~Point() {
		
	}

};

