// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <math.h>
#define MOD 10000

using namespace std;

int my_pow(int N, int P) {
    if (P == 0) return 1;
    if (P == 1) return (N % MOD);
    int temp_pow = my_pow(N, P/2);
    if ((P % 2) == 0) {
        return (temp_pow * temp_pow) % MOD;
    }
    return (((temp_pow * temp_pow) % MOD) * (N % MOD)) % MOD;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int x,y,n;
        scanf("%d%d%d", &x,&y,&n);
        int powerXY = my_pow(x,y);
        printf("%d\n", powerXY);
        int res = powerXY%n;
        printf("%d\n", res);
    }
    return (0);
}
