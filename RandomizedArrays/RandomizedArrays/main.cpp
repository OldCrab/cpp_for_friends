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

int* createRandomizedArray(int dimension) {
    int *array = new int[dimension];
    for (int i = 0; i < dimension; i++) {
        array[i] = getRandomNumber(-100, 100);
    }
    return array;
}

void fillArrayByZeros(int* fillable, int* filling, int &fillableDimension, int fillingDimension) {
    for (int i = 0; i < fillingDimension; i++) {
        if (filling[i] == 0) {
            fillable[fillableDimension++] = 0;
        }
    }
}

void fillArrayByNegativeValues(int* fillable, int* filling, int &fillableDimension, int fillingDimension) {
    for (int i = 0; i < fillingDimension; i++) {
        if (filling[i] < 0) {
            fillable[fillableDimension++] = filling[i];
        }
    }
}

void outputArray(int* array, int dimension) {
    for (int i = 0; i < dimension; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int arrayDimension1, arrayDimension2, arrayDimension3 = 0, arrayDimension4 = 0;
    arrayDimension1 = getPositiveRandomNumber(500);
    do {
        arrayDimension2 = getPositiveRandomNumber(500);
    } while (arrayDimension1 == arrayDimension2);
    
    int *array1 = createRandomizedArray(arrayDimension1);
    int *array2 = createRandomizedArray(arrayDimension2);
    int *array3 = new int[2];
    int *array4 = new int[2];

    fillArrayByZeros(array3, array1, arrayDimension3, arrayDimension1);
    fillArrayByZeros(array3, array2, arrayDimension3, arrayDimension2);
    
    fillArrayByNegativeValues(array4, array1, arrayDimension4, arrayDimension1);
    fillArrayByNegativeValues(array4, array2, arrayDimension4, arrayDimension2);

//    outputArray(array1, arrayDimension1);
//    outputArray(array2, arrayDimension2);
//    outputArray(array3, arrayDimension3);
//    outputArray(array4, arrayDimension4);
    return 0;
}
