//
//  main.cpp
//  FirstHomework
//
//  Created by OldMan on 07/12/2017.
//  Copyright © 2017 justice. All rights reserved.
//

//  Заданы две матрицы А(N,N) и В(N,N). Найти след матрицы, равной произведению АВ, и след матрицы, равной произведению ВА. Вычисление произведения двух матриц оформить в виде функции.

#include <iostream>
using namespace std;

void release(int** array, int edge) {
    for (int row = 0; row < edge; row++) {
        delete []array[row];
    }
}

class Matrix {
public:
    string name;
    int **value;
    int rowsCount;
    int columnsCount;
    
    bool isSquare() {
        return rowsCount == columnsCount;
    }
    
    int getTrace() {
        int counter = 0;
        for (int i = 0; i < rowsCount; i++) {
            counter += value[i][i];
        }
        return counter;
    }
    
    Matrix(string outsideName, int width, int height)
    {
        rowsCount = height;
        columnsCount = width;
        name = outsideName;
    }
    
    ~Matrix()
    {
        release(value, rowsCount);
    }
};

int** createArray(int rowsCount, int columnsCount) {
    int **array = new int* [rowsCount];
    
    for (int i = 0; i < rowsCount; i++)
        array[i] = new int [columnsCount];
    
    return array;
}

Matrix* mutiplyMatrices(Matrix &firstMatrix, Matrix &secondMatrix) {
    if (firstMatrix.columnsCount != secondMatrix.rowsCount) {
        //Умножать матрицы можно тогда и только тогда, когда количество столбцов первой матрицы равно количеству строк второй матрицы.
        return NULL;
    }
    
    int rowsCount = firstMatrix.rowsCount;
    int columnsCount = secondMatrix.columnsCount;
    int lineSize = firstMatrix.columnsCount;
    
    int **array = createArray(rowsCount, columnsCount);
    //Произведением матрицы A(m,n) на матрицу B(n,k) называется матрица C(m,k) такая, что элемент матрицы C, стоящий в i-ой строке и j-ом столбце, т.е. элемент c(i,j), равен сумме произведений элементов i-ой строки матрицы A на соответствующие элементы  j-ого столбца матрицы B.
    for (int row = 0; row < rowsCount; row++) {
        for (int column = 0; column < columnsCount; column++) {
            int counter = 0;
            for (int line = 0; line < lineSize; line++) {
                counter += firstMatrix.value[row][line] * secondMatrix.value[line][column];
            }
            array[row][column] = counter;
        }
    }
    
    Matrix *matrix = new class Matrix("AB", rowsCount, columnsCount);
    
    matrix->value = array;

    return matrix;
}

Matrix createMatrix(string name) {
    int rowsCount, columnsCount;
    
    cout << "Input size of matrix " + name + ": ";
    cin >> rowsCount >> columnsCount;
    cout << endl;
    
    return Matrix(name, rowsCount, columnsCount);
}

void fillMatrix(Matrix &matrix) {
    int **array = createArray(matrix.rowsCount, matrix.columnsCount);
    int currentValue;
    
    cout << "Fill matrix " + matrix.name << endl;
    
    for (int i = 0; i < matrix.rowsCount; i++) {
        for (int j = 0; j < matrix.columnsCount; j++) {
            cin >> currentValue;
            array[i][j] = currentValue;
        }
    }
    matrix.value = array;
}

void outputMatrix(Matrix matrix) {
    for (int row = 0; row < matrix.rowsCount; row++) {
        for (int column = 0; column < matrix.columnsCount; column++) {
            cout << matrix.value[row][column] << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    Matrix matrixA = createMatrix("A");
    Matrix matrixB = createMatrix("B");
    
    fillMatrix(matrixA);
    fillMatrix(matrixB);
    
    Matrix *matrixAB = mutiplyMatrices(matrixA, matrixB);
    
    if (!matrixAB) {
        cout << "Sizes are invalid!!!" << endl;
        return 1;
    }
    
    outputMatrix(*matrixAB); // - вывод матрицы AB
    //    outputMatrix(matrixA);
    //    outputMatrix(matrixB);

    if (matrixAB->isSquare()) {
        cout << "Matrix trace = " << matrixAB->getTrace();
    } else {
        cout << "Can't find trace from non-square matrix" ;
    }
    
    // tr(AB) = tr(BA) - одно из свойств следа матрицы: https://ru.wikipedia.org/wiki/%D0%A1%D0%BB%D0%B5%D0%B4_%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D1%8B - таким образом, чтобы не тратить процессорное время, мы можем не рассчитывать матрицу BA для нахождения ее следа, так как он равен следу матрицы AB.

    
    delete &matrixA;
    delete &matrixB;
    delete matrixAB;
    
    return 0;
}


