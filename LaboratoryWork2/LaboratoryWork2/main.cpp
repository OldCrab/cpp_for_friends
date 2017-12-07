//
//  main.cpp
//  LaboratoryWork2
//
//  Created by OldMan on 07/12/2017.
//  Copyright © 2017 justice. All rights reserved.
//

// Составить  функцию  нахождения  суммы  и произведения четных  цифр  числа, суммы  и произведения нечетных  цифр  числа.

//Указание. Написать программу двумя способами: с помощью глобальных переменных, с помощью указателей


#include <iostream>
using namespace std;

int oddSum;
int oddProduct;
int evenSum;
int evenProduct;

void solveByGlobalVariables(int number) {
    oddSum = 0;
    evenSum = 0;
    oddProduct = number != 0 ? 1 : 0;
    evenProduct = number / 10 != 0 ? 1 : 0;
    
    int digitNumber = 1;
    while (number != 0) {
        int digit = number % 10;
        if (digitNumber % 2 == 0) {
            evenSum += digit;
            evenProduct *= digit;
        } else {
            oddSum += digit;
            oddProduct *= digit;
        }
        digitNumber++;
        number /= 10;
    }
}

void solveByPointers(int number, int *oddSumPtr, int *oddProductPtr, int *evenSumPtr, int *evenProductPtr) {
    *oddSumPtr = 0;
    *evenSumPtr = 0;
    *oddProductPtr = number != 0 ? 1 : 0;
    *evenProductPtr = number / 10 != 0 ? 1 : 0;
    
    int digitNumber = 1;
    while (number != 0) {
        int digit = number % 10;
        if (digitNumber % 2 == 0) {
            *evenSumPtr += digit;
            *evenProductPtr *= digit;
        } else {
            *oddSumPtr += digit;
            *oddProductPtr *= digit;
        }
        digitNumber++;
        number /= 10;
    }
}

int main(int argc, const char * argv[]) {
    int innerOddSum;
    int innerOddProduct;
    int innerEvenSum;
    int innerEvenProduct;
    
    solveByPointers(123456782, &innerOddSum, &innerOddProduct, &innerEvenSum, &innerEvenProduct);
    cout << innerOddSum << "  " << innerOddProduct << endl << innerEvenSum << "  " << innerEvenProduct << "  " << endl << endl;
    solveByGlobalVariables(123456782);
    cout << oddSum << "  " << oddProduct << endl << evenSum << "  " << evenProduct << "  " << endl;

    return 0;
}
