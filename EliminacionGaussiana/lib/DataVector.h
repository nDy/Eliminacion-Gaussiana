#ifndef DATAVECTOR_H_
#define DATAVECTOR_H_

class DataVector {
private:
	double* Data;

	int Size;

public:

	DataVector(int Size) {
		this->Size = Size;
	}

	DataVector() {

	}

	~DataVector() {
		delete[] this->Data;
	}

	bool isNull() {

		if (this->Data == NULL) {
			return true;
		}

		for (int i = 0; i < Size; i++) {
			if (this->Data[i] != 0) {
				return false;
			}
		}

		this->Data = NULL;

		return true;
	}

	bool insert(int Position, double Data) {
		if (Position > this->Size)
			return false;
		if (this->Data == NULL)
			this->Data = new double[this->Size];

		this->Data[Position] = Data;

		this->isNull();

		return true;
	}

	double get(int Position) {

		if (this->Data == NULL) {

			return 0.0;
		}
		return this->Data[Position];
	}

	int size() {
		return this->Size;
	}

};

#endif
