#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
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

		if (this->Data[Y - 1]==NULL) {

			this->Data[Y - 1] = new PointerVector(this->BlockSize,
					this->DataSize);

		}

		return this->Data[Y - 1]->insert(X, Data);
	}

	double get(int X, int Y) {
		if (this->isNull()) {
			return 0.0;
		}
		return this->Data[Y - 1]->get(X);
	}

	DataVector* getRow(int Y) {
		DataVector* Row;

		Row = new DataVector(this->Size);

		for (int i = 1; i <= this->size(); i++) {
			Row->insert(i, this->get(i, Y));
		}

		return Row;
	}

	DataVector* getCollumn(int X) {
		DataVector* Collumn;

		Collumn = new DataVector(this->Size);

		for (int i = 1; i <= this->size(); i++) {
			Collumn->insert(i, this->get(X, i));
		}

		return Collumn;
	}

	Matrix * invert() {
		Matrix * A;

		return A;
	}

	/*
	 double det() {
	 for (int i = 1; i <= this->Size; i++) {
	 Matrix M = a.minor(1, i);
	 d += (i % 2 + i % 2 - 1) * this->get(1, i) * M.det(); // faster than with pow()
	 }

	 }
	 */

	int size() {
		return this->Size;
	}

};

#endif
