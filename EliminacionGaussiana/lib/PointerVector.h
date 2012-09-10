#ifndef POINTERVECTOR_H_
#define POINTERVECTOR_H_
#include "DataVector.h"

class PointerVector {
private:
	DataVector* Data;
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
			if (!this->Data[i].isNull()) {
				return false;
			}
		}

		delete[] this->Data;

		return true;
	}

	bool insert(int Position, double Data) {
		if (Position >= this->Size*this->DataSize)
			return false;

		if (this->isNull()) {
			this->Data = new DataVector(this->DataSize);
		}

		return this->Data[Position/this->DataSize].insert(Position-(Position/this->DataSize),Data);
	}

	double get(int Position) throw (char*) {
		if (this->isNull()) {
			return NULL;
		}
		return this->Data[Position/this->DataSize].get(Position-(Position/this->DataSize));
	}

};

#endif
