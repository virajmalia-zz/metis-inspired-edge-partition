#ifndef MMIO_H
#define MMIO_H

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace mmio_ns
{
	class matrix_market
	{
		private:
			int rowNum;
			int colNum;
			int nnzNum;
			int *rowIndex;
			int *colIndex;
			float *value;
		public:
			matrix_market();
			~matrix_market();
			void read_matrix(char* fileName);
			void write_matrix(char* fileName);
	};
}


#endif
