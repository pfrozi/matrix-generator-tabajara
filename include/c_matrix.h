#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

#define FILE_MODE_READ "r"
#define FILE_MODE_WRITE "w"

#define MATRIX_ERROR_EXPORTFILE 1

#ifndef MATRIX_H
#define MATRIX_H

using namespace std;


class Matrix{

    public:

        Matrix();
        ~Matrix();

        void setRows(int r);
        void setColumns(int c);
        void initMatrix();
        void setPosMatrix(int row, int column, int value);
        void setRandom();

        int getPosMatrix(int row, int column);
        int getRows();
        int getColumns();

        Matrix* matrixProduct(Matrix* matrix);

        void exportToFile(std::string path);

    protected:

    private:
        int rows;
        int columns;

        int** matrix;
};

#endif // MATRIX
