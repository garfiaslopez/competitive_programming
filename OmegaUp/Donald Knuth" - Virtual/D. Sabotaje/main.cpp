// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

long int calculate(long int n) {
    long int sum = 0;
    for (int i=0; i<n; i++) {
        sum += pow(n - i, 2) * pow(-1, i);
    }
    return sum;
}

int main() {
    long int cases;
    scanf("%li", &cases);
    fillVector();
    while (cases--) {
        long int n;
        scanf("%li", &n);
        printf("%li\n", sums[n-1]);
    }
    return (0);
}
