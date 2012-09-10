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
			if (!this->Data[i]->isNull()) {
				return false;
			}
		}

		delete[] this->Data;

		return true;
	}

	bool insert(int Position, double Data) {

		if (Position >= this->Size * this->DataSize) {
			return false;
		}

		if (this->isNull()) {
			this->Data = new DataVector*[this->Size / this->DataSize];
		}
		std::cout << "Build" << std::endl;
		if (this->Data[(Position / this->DataSize) - 1] == NULL) {

			this->Data[(Position / this->DataSize) - 1] = new DataVector(
					this->DataSize);

		}

		return this->Data[(Position / this->DataSize) - 1]->insert(
				(Position % this->DataSize), Data);
	}

	double get(int Position) throw (char*) {
		if (this->isNull()) {
			return 0.0;
		}
		return this->Data[Position / this->DataSize - 1]->get(
				Position - (Position / this->DataSize));
	}

	int size() {
		return this->Size;
	}

};

#endif
