// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int tam;
    int iteration = 0;
    while (scanf("%d", &tam), tam != 0) {
        iteration++;
        int zeros = 0;
        int others = 0;
        for(int i=0; i<tam; i++) {
            int number;
            scanf("%d", &number);
            if (number == 0) {
                zeros++;
            } else {
                others++;
            }
        }
        printf("Case %d: %d\n", iteration, others - zeros);
    }
    return (0);
}
