#ifndef POINTERVECTOR_H_
#define POINTERVECTOR_H_
#include "DataVector.h"

class PointerVector {
private:
	DataVector** Data;
	int Size;
	int DataSize;
public:

	PointerVector(int Size, int DataSize) {
		this->Size = Size;
		this->DataSize = DataSize;
	}

	~PointerVector() {
		delete[] this->Data;
	}

	bool isNull() {
		if (this->Data == NULL) {
			return true;
		}

		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < this->Data[i]->size(); j++) {
				if (this->Data[i]->get(j) != 0) {
					return false;
				}
			}
		}

		this->Data = NULL;

		return true;
	}

	bool insert(int Position, double Data) {

		if (Position >= this->Size * this->DataSize) {
			return false;
		}

		if (this->Data == NULL)
			this->Data = new DataVector*[this->Size];

		if (this->Data[(Position / this->DataSize)] == NULL)
			this->Data[(Position / this->DataSize)] = new DataVector(
					this->DataSize);

		return this->Data[(Position / this->DataSize)]->insert(
				(Position % this->DataSize), Data);
	}

	double get(int Position) throw (char*) {
		if (this->Data == NULL) {
			return 0.0;
		}
		return this->Data[Position / this->DataSize]->get(
				Position - (Position / this->DataSize));
	}

	int size() {
		return this->Size;
	}

};

#endif
