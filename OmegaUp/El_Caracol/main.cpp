// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://omegaup.com/arena/TRAINING_2018/#problems/El-Caracol
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int p,s,r,d;
    scanf("%d%d%d", &p,&s,&r);
    int actualStep=0;
    int days = 0;
    while (actualStep<p) {
        actualStep += s;
        if (actualStep<p) {
            actualStep -=r;
        }
        days++;
    }
    printf("%d\n", days);
    return (0);
}
