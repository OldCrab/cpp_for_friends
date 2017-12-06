#include <iostream>
using namespace std;

int** createArray(int edge) {
    int **array = new int* [edge]; // edge строк в массиве изначально
    
    for (int i = 0; i < edge; i++)
        array[i] = new int [edge - i]; // втыкаем второй динамический массив в первый массив, чтобы получился двумерный массив
    return array;
}

void outputTriangleArray(int** array, int edge) {
    for (int row = 0; row < edge; row++) {
        for (int column = 0; column < edge - row; column++) {
            cout << array[row][column] << " ";
        }
        cout << endl;
    }
}

void release(int** array, int edge) {
    for (int row = 0; row < edge; row++) {
        delete []array[row];
    }
}

int main(int argc, const char * argv[]) {
    
    int initialValue = 30; // первое значение
    int finalValue = 80; // последнее значение
    int columnStep = 10; // шаг по вертикали
    int rowStep = 5; // шаг по горизонтали
    
    int trianglesEdge = (finalValue - initialValue) / columnStep + 1; // - ребро треугольника, "+ 1" потому что 80 включается в треугольник
    int **array = createArray(trianglesEdge);
    
    // заполнение массива
    for (int column = 0; column < trianglesEdge; column++) { //column - текущий номер столбца, по которому мы проходимся
        int columnInitialValue = initialValue + rowStep * column; //первое значение в столбце
        cout << "columnInitialValue " << columnInitialValue << endl; // посмотришь, как работает программа и удалишь эту строку
        for (int row = 0; row < trianglesEdge - column; row++) { //row - текущий номер строки, по которой мы проходимся
            int value = columnInitialValue + columnStep * row; 
            cout << "value " << value << endl; // посмотришь, как работает программа и удалишь эту строку
            array[row][column] = value; // присваиваем значение нужному элементу
        }
    }
    
    outputTriangleArray(array, trianglesEdge); // функция вывода
    release(array, trianglesEdge); // функция освобождения памяти от массива
    
    return 0;
}
