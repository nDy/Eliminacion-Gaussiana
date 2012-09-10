//============================================================================
// Name        : EliminacionGaussiana.cpp
// Author      : nDy
// Version     : 1.0
//============================================================================

#include <iostream>
#include "../lib/mmio.h"
#include "../lib/Matrix.h"
using namespace std;

int main(int argc, char **argv) {

	Matrix* matrix;

	matrix = new Matrix(100, 10);

	delete matrix;

	return 0;
}

