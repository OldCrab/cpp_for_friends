//
//  main.cpp
//  RandomizedArrays
//
//  Created by OldMan on 06/12/2017.
//  Copyright © 2017 justice. All rights reserved.
//

#include <iostream>
using namespace std;

int getPositiveRandomNumber(int max) {
    return rand() % (max + 1);
}

int getRandomNumber(int min, int max) {
    return min + getPositiveRandomNumber(-min + max);
}

int* createRandomizedArray(int size) {
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = getRandomNumber(-100, 100);
    }
    return array;
}

void fillArrayByZeros(int* fillable, int* filling, int &fillableSize, int fillingSize) {
    for (int i = 0; i < fillingSize; i++) {
        if (filling[i] == 0) {
            fillable[fillableSize++] = 0;
        }
    }
}

void fillArrayByNegativeValues(int* fillable, int* filling, int &fillableSize, int fillingSize) {
    for (int i = 0; i < fillingSize; i++) {
        if (filling[i] < 0) {
            fillable[fillableSize++] = filling[i];
        }
    }
}

void outputArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void release(int* array) {
    delete []array;
}

int main(int argc, const char * argv[]) {
    int arraySize1, arraySize2, arraySize3 = 0, arraySize4 = 0;
    arraySize1 = getPositiveRandomNumber(500);
    do {
        arraySize2 = getPositiveRandomNumber(500);
    } while (arraySize1 == arraySize2);
    
    int *array1 = createRandomizedArray(arraySize1);
    int *array2 = createRandomizedArray(arraySize2);
    int *array3 = new int[2];
    int *array4 = new int[2];

    fillArrayByZeros(array3, array1, arraySize3, arraySize1);
    fillArrayByZeros(array3, array2, arraySize3, arraySize2);
    
    fillArrayByNegativeValues(array4, array1, arraySize4, arraySize1);
    fillArrayByNegativeValues(array4, array2, arraySize4, arraySize2);

    //    outputArray(array1, arrayDimension1);
    //    outputArray(array2, arrayDimension2);
    //    outputArray(array3, arrayDimension3);
    //    outputArray(array4, arrayDimension4);
    
    //освобождаем память от массивов
    release(array1);
    release(array2);
    release(array3);
    release(array4);

    return 0;
}
