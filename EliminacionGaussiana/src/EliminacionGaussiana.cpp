//============================================================================
// Name        : EliminacionGaussiana.cpp
// Author      : nDy
// Version     : 1.0
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "DataVector.h"
using namespace std;

DataVector* SolveGauss(double** A, DataVector*& b, int X) {
	DataVector* x;

	x = new DataVector(b->size());

	double aux;

	for (int i = 1; i <= X - 1; i++) {
		for (int j = 2; j <= X; j++) {
			aux = A[i][j] / A[i][i];
			A[i][j] = 0.0;

			x->insert(j, x->get(j) - aux * x->get(i));

			for (int k = j; k <= X; k++) {
				A[k][j] = A[k][j] - aux * A[j][i];
			}
		}
	}
	return x;
}

int GetMinor(double **src, double **dest, int row, int col, int order) {
	int colCount = 0, rowCount = 0;

	for (int i = 0; i < order; i++) {
		if (i != row) {
			colCount = 0;

			for (int j = 0; j < order; j++) {
				if (j != col) {

					dest[rowCount][colCount] = src[i][j];
					colCount++;

				}
			}

			rowCount++;

		}
	}

	return 1;

}

double CalcDeterminant(double **mat, int order) {

	if (order == 1)
		return mat[0][0];

	double det = 0;

	double **minor;

	minor = new double*[order - 1];

	for (int i = 0; i < order - 1; i++)
		minor[i] = new double[order - 1];

	for (int i = 0; i < order; i++) {
		GetMinor(mat, minor, 0, i, order);
		det += (i % 2 == 1 ? -1.0 : 1.0) * mat[0][i]
				* CalcDeterminant(minor, order - 1);
	}

	for (int i = 0; i < order - 1; i++)
		delete[] minor[i];

	delete[] minor;

	return det;

}

void MatrixInversion(double **A, int order, double **Y) {
	double det = 1.0 / CalcDeterminant(A, order);
	double *temp = new double[(order - 1) * (order - 1)];
	double **minor = new double*[order - 1];

	for (int i = 0; i < order - 1; i++)
		minor[i] = temp + (i * (order - 1));

	for (int j = 0; j < order; j++) {
		for (int i = 0; i < order; i++) {

			GetMinor(A, minor, j, i, order);
			Y[i][j] = det * CalcDeterminant(minor, order - 1);

			if ((i + j) % 2 == 1)
				Y[i][j] = -Y[i][j];

		}
	}

	delete[] temp;
	delete[] minor;

}

int main() {
	double c;
	double ** matrix;
	DataVector* vector;
	DataVector* result;
	double ** inv;
	int Xx;
	string line;
	ifstream myfile("matrix.mtx");

	if (myfile.is_open()) {

		//datos del encabezado, tamaño de matriz
		getline(myfile, line);

		getline(myfile, line);

		int i = 0;

		while (line[i] != ' ') {
			i++;
		}
		int x = atoi(line.substr(0, i).c_str());
		int j = i;
		Xx = x;
		while (line[j] != ' ') {
			j++;
		}
		int y = atoi(line.substr(i, j - i).c_str());
		//inicializacion de matriz
		matrix = new double*[x];

		for (int i = 0; i < x; ++i)
			matrix[i] = new double[y];
		//inicializacion de inversa
		inv = new double*[x];

		for (int i = 0; i < x; ++i)
			inv[i] = new double[y];

		while (!myfile.eof()) {
			getline(myfile, line);

			i = 0;

			while (line[i] != ' ') {
				i++;
			}
			x = atoi(line.substr(0, i).c_str());
			j = i + 1;

			while (line[j] != ' ') {
				j++;
			}
			y = atoi(line.substr(i, j - i).c_str());

			i = j + 1;

			while (line[i] != 'e') {
				i++;
			}
			c = atof(line.substr(j, i - j).c_str());

			matrix[x][y] = c;

		}

		myfile.close();

	} else
		cout << "Unable to open file";

	MatrixInversion(matrix, Xx, inv);
	vector = new DataVector(Xx);
	for (int i = 0; i < Xx; ++i)
		vector->insert(i, inv[i][Xx - 1]);

	result = SolveGauss(matrix, vector, Xx);

	delete[] matrix;
	delete[] inv;

	return 0;
}
