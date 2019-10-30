// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// Reference url: https://www.geeksforgeeks.org/count-digits-factorial-set-1/
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double logaritmo(int base, int x) {
    return (log(x) / log(base));
}

int findDigits(int n) {
    // factorial exists only for n>=0 but because the number of levels in zero cant exists
    if (n <= 0) {
        return 0;
    }
    if (n <= 1) {
        return 1;
    }
    // else iterate through n and calculate the
    // value
    double digits = 0;
    for (int i=2; i<=n; i++) {
        digits += logaritmo(8, i);
    }
    return floor(digits) + 1;
}

int main() {
    int number;
    scanf("%d\n", &number);
    int digitsInFactorial = findDigits(number);
    printf("%d\n", digitsInFactorial);
    return (0);
}
