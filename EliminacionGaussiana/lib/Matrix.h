#ifndef MATRIX_H_
#define MATRIX_H_

#include "PointerVector.h"

class Matrix {
private:
	PointerVector** Data;
	int Size;
	int BlockSize;
	int DataSize;

public:

	Matrix(int Size, int BlockSize) {
		this->Size = Size;
		this->BlockSize = BlockSize;
		this->DataSize = Size / BlockSize;
	}

	~Matrix() {
		delete[] this->Data;
	}

	bool isNull() {
		if (this->Data == NULL) {
			return true;
		}

		for (int i = 0; i < Size; i++) {
			if (!this->Data[i]->isNull()) {
				return false;
			}
		}

		delete[] this->Data;

		return true;
	}

	bool insert(int X, int Y, double Data) {
		if (X >= this->Size || Y >= this->Size)
			return false;

		if (this->isNull()) {
			this->Data = new PointerVector*[this->Size];
		}

		return this->Data[Y - 1]->insert(X, Data);
	}

	double get(int X, int Y) {
		if (this->isNull()) {
			return 0.0;
		}
		return this->Data[Y - 1]->get(X);
	}

	int size() {
		return this->Size;
	}

};

#endif
