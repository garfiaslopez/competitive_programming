// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=12&problem=976
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int charToInt (char c) {
    if (c != '\n') {
        return (int)c - 48;
    }
    return 0;
}

int main() {
    char first[10];
    char second[10];
    memset(first, -1, 10);
    memset(second, -1, 10);
    while (scanf("%s %s", first, second) == 2) {
        if (first[0] != '0' || second[0] != '0') {
            int firstNumber[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int secondNumber[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int indexFn = 0;
            int indexSn = 0;
            for (int i=9; i>=0; i--) {
                int fn = charToInt(first[i]);
                if (fn >= 0) {
                    firstNumber[indexFn] = fn;
                    indexFn++;
                }
                int sn = charToInt(second[i]);
                if (sn >= 0) {
                    secondNumber[indexSn] = sn;
                    indexSn++;
                }
            }
            int carrys = 0;
            int carry = 0;
            for (int i=0; i<10; i++) {
                int sum = carry + firstNumber[i] + secondNumber[i];
                if ((sum-10) >= 0) {
                    carry = (sum/10);
                    carrys++;
                } else {
                    carry = 0;
                }
            }
            if (carrys == 0) {
                printf("No carry operation.\n");
            } else if (carrys == 1) {
                printf("1 carry operation.\n");
            } else {
                printf("%d carry operations.\n", carrys);
            }
            memset(first, -1, 10);
            memset(second, -1, 10);
        }
    }
    return (0);
}
