#include "mmio.h"

using namespace std;

namespace mmio_ns
{
	matrix_market::matrix_market() {
		rowNum = 0;
		colNum = 0;
		nnzNum = 0;
	}

	matrix_market::~matrix_market() {
		rowIndex = NULL;
		colIndex = NULL;
		value = NULL;
	}

	void matrix_market::read_matrix(char *fileName) {
		ifstream fin;
		fin.open(fileName);
		
		char garbage[256];
		while(fin.peek()=='%') {
			fin.getline(garbage, 256);
		}

		fin >> rowNum >> colNum >> nnzNum;
		rowIndex = (int *) malloc(nnzNum * sizeof(int));
		colIndex = (int *) malloc(nnzNum * sizeof(int));
		value = (float *) malloc(nnzNum * sizeof(float));

		for (int i = 0; i < nnzNum; ++i) {
			int row, col;
			fin >> row >> col;
			row--;
			col--;
			rowIndex[i] = row;
			colIndex[i] = col;
			if (fin.peek()=='\n')
				value[i] = 1.0;
			else
				fin >> value[i];
		}

		fin.close();
	}

	void matrix_market::write_matrix(char *fileName) {
		ofstream fout;
		fout.open(fileName);
		fout << rowNum << " " << colNum << " " << nnzNum << endl;

		for (int i = 0; i < nnzNum; ++i) {
			fout << rowIndex[i] + 1 << " " << colIndex[i] + 1 << " " << value[i] << endl;
		}

		fout.close();
	}
}








