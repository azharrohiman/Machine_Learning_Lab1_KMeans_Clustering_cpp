// database.h - header file: this should be included in any source file that needs database() functions

#ifndef CLUSTER_H
#define CLUSTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Point.h"

namespace RHMMUH005 {
	class Cluster {

		private: // private members

		public: // public members

			Cluster();
			Cluster(Point, int);
			~Cluster();

			Point mean;
			int id;

			Point getPoints();

	};
}

#endif
