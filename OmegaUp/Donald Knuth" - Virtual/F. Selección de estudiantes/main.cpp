// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int charToInt(char i) {
    return (int)i - 48;
}

int main() {
    char firstNumber;
    char secondNumber;
    char buff;
    while(scanf ("%c", &buff) && buff != '\n') {
        if (buff != '\n') {
            firstNumber = buff;
        }
    }
    while(scanf ("%c", &buff) && buff != '\n') {
        if (buff != '\n') {
            secondNumber = buff;
        }
    }
    int mult = charToInt(firstNumber) * charToInt(secondNumber);
    if (mult < 10) {
        printf("%d\n", mult);
    } else {
        printf("%d\n", mult%10);
    }
    return (0);
}
