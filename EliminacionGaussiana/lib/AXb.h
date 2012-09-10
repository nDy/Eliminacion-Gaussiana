#ifndef AXB_H_
#define AXB_H_

#include "Matrix.h"
#include "DataVector.h"

class Axb {
public:

	DataVector* Solve(Matrix*& A, DataVector*& b) {
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

};
#endif
