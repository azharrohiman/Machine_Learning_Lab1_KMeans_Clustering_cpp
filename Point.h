// database.h - header file: this should be included in any source file that needs database() functions

#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace RHMMUH005 {
	class Point {

		private: // private members

		public: // public members

			Point();
			Point(double, double, int);
			~Point();

			double x, y;
			int id;

	};
}

#endif
