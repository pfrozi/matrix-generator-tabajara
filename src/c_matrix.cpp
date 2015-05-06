#include "../include/c_matrix.h"

Matrix::Matrix(){

}
Matrix::~Matrix(){

    for(int i=0;i<rows;i++){
        free(this->matrix[i]);
    }
    free(this->matrix);
}

void Matrix::setRows(int r){
    this->rows = r;
}
void Matrix::setColumns(int c){
    this->columns = c;
}
void Matrix::initMatrix(){

    this->matrix = (int**)malloc(sizeof(int*)*this->rows);

    for(int i=0;i<rows;i++){
        this->matrix[i] = (int*)malloc(sizeof(int)*this->columns);
    }

}
void Matrix::setPosMatrix(int row, int column, int value){

    this->matrix[row][column] = value;
}
int Matrix::getPosMatrix(int row, int column){

    return this->matrix[row][column];
}

void Matrix::setRandom(){

    srand(time(NULL));

    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->columns;j++){
            this->matrix[i][j] = rand() % 100;
        }
    }
}
Matrix* Matrix::matrixProduct(Matrix* matrix){

    Matrix* result = new Matrix();

    int rows_result=this->getRows();
    int columns_result=matrix->getColumns();

    result->setRows(rows_result);
    result->setColumns(columns_result);

    result->initMatrix();

    for(int i=0;i<rows_result;i++){
        for(int j=0;j<columns_result;j++){

            int val = 0;

            for(int k=0;k<this->getColumns();k++){

                val += this->getPosMatrix(i,k) * this->getPosMatrix(k, j);
            }

            result->setPosMatrix(i,j,val);
        }
    }

    return result;
}

int Matrix::getRows(){

    return rows;
}
int Matrix::getColumns(){

    return columns;
}

void Matrix::exportToFile(std::string path){

    FILE *pfile = fopen(path.c_str(), FILE_MODE_WRITE);


    if(pfile == NULL){
        throw MATRIX_ERROR_EXPORTFILE;
    }else{
        fprintf(pfile, "LINHAS = %d\nCOLUNAS = %d\n",this->rows,this->columns);

        for(int i=0;i<this->rows;i++){

            for(int j=0;j<this->columns;j++){
                fprintf(pfile,"%d ",this->matrix[i][j]);
            }

            fprintf(pfile,"\n");
        }

        fclose(pfile);
    }
}
