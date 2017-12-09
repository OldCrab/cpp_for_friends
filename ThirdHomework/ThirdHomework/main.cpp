//
//  main.cpp
//  ThirdHomework
//
//  Created by OldMan on 08/12/2017.
//  Copyright © 2017 OldMan. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

//9.    На вход программе подается предложение на английском языке, заканчивающееся точкой. Требуется написать программу, которая определяет, можно ли переставить английские буквы этого предложения (не учитывая остальные символы) так, чтобы получить палиндром – слово, которое читается одинаково слева направо и справа налево. Строчные и прописные буквы не различаются. Если это сделать нельзя, программа должна вывести на экран слово «Нет», а если можно – слово «Да» и в следующей строчке искомое слово прописными буквами. Если таких слов несколько, нужно вывести последнее в алфавитном порядке слово. Например, если исходная последовательность была такая:
//Deed daad N.
//то результат должен быть следующий:
//Да
//EDDANADDE

map<char,int> createLettersMap(string str, int &lettersCount) {
    map<char,int> map;
    
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        if (!isalpha(ch)) {
            continue;
        }
        
        lettersCount++;
        ch = toupper(ch);
        auto iterator = map.find(ch);
        
        
        if (iterator != map.end()) {
            iterator->second++;
        } else {
            map.insert ( pair<char,int>(ch,1) );
        }
    }
    
    return map;
}

bool hasMoreThenOneOdd(map<char,int> lettersMap) {
    bool hasOdd = false;
    
    for (auto iterator = lettersMap.begin(); iterator != lettersMap.end(); ++iterator) {
        if (iterator->second % 2 != 0) {
            if (hasOdd) {
                return true;
            } else {
                hasOdd = true;
            }
        }
    }
    return false;
}

string composePalindrome(map<char,int> lettersMap, int lettersCount) {
    char* result = new char[lettersCount];
    
    int i = 0;
    
    for (auto iterator = lettersMap.begin(); iterator != lettersMap.end(); ++iterator) {
        char letter = iterator->first;
        
        for (int count = iterator->second; count > 0; count -= 2) {
            if (count == 1) {
                result[lettersCount / 2] = letter;
            } else {
                result[i] = letter;
                result[lettersCount - 1 - i] = letter;
                i++;
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    setlocale(LC_ALL, "Russian");
    
    string initialString;
    getline(cin, initialString);
//    cin >> initialString;
    int lettersCount;
    auto lettersMap = createLettersMap(initialString, lettersCount);
    
    if (hasMoreThenOneOdd(lettersMap)) {
        cout << "Нет" << endl;
        return 1;
    } else {
        cout << "Да" << endl;
    }
    
    string result = composePalindrome(lettersMap, lettersCount);
    
    cout << result << endl;
    
    return 0;
}
