//============================================================================
// Name        : EliminacionGaussiana.cpp
// Author      : nDy
// Version     : 1.0
//============================================================================

#include <iostream>
#include "../lib/mmio.h"
#include "../lib/Matrix.h"
#include "../lib/DataVector.h"
using namespace std;

DataVector* SolveGauss(Matrix*& A, DataVector*& b) {
	DataVector* x;

	x = new DataVector(b->size());

	double aux;

	for (int i = 1; i <= A->size() - 1; i++) {
		for (int j = 2; j <= A->size(); j++) {
			aux = A->get(i, j) / A->get(i, i);
			A->insert(i, j, 0.0);

			x->insert(j, x->get(j) - aux * x->get(i));

			for (int k = j; k <= A->size(); k++) {
				A->insert(k, j, A->get(k, j) - aux * A->get(j, i));
			}
		}
	}
	return x;
}

int main(int argc, char **argv) {
/*
	Matrix* A;

	A = new Matrix(10, 5);

	A->insert(1,5,5.9542);

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout<<A->get(i,j)<<" ";
		}
		cout<<endl;
	}

	delete A;
*/

	DataVector* A;

	A= new DataVector(5);

	A->insert(3,5.7536);

	for (int j = 1; j <= 5; j++) {
				cout<<A->get(j)<<" ";
			}

	delete A;

	return 0;
}

