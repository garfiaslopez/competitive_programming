// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=788
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int reachNumber;
    while(scanf("%d", &reachNumber) != EOF) {
        int stan = 0;
        int ollie = 0;
        int multiplierNumber = 1;
        while (stan < reachNumber || ollie < reachNumber) {
            stan = multiplierNumber * 9;
            if (stan < reachNumber) {
                multiplierNumber = multiplierNumber * 2;
            } else {
                break;
            }
            ollie = multiplierNumber * 9;
            if (ollie < reachNumber) {
                multiplierNumber = multiplierNumber * 9;
            } else {
                break;
            }
        }
        // printf("stan: %d , ollie: %d\n",stan, ollie);
        if (ollie >= reachNumber) {
            printf("Ollie wins.\n");
        } else {
            printf("Stan wins.\n");
        }
    }
    return (0);
}
