// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long int x, long long int y, long long int p) {
    long long int res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// C++ function to calculate
// number of digits in x
int numberOfDigits(int x) {
    int i = 0;
    while (x) {
        x /= 10;
        i++;
    }
    return i;
}

// C++ function to print last k digits of a^b
long long int printLastKDigits(int a, int b, int k) {
    // Generating 10^k
    long long int temp = 1;
    for (int i = 1; i <= k; i++)
        temp *= 10;
    // Calling modular exponentiation
    temp = power(a, b, temp);
    // Printing leftmost zeros. Since (a^b)%k
    // can have digits less then k. In that
    // case we need to print zeros
    // for (int i = 0; i < k - numberOfDigits(temp); i++)
    //     cout<<0<<" - ";
    // If temp is not zero then print temp
    // If temp is zero then already printed
    if (temp)
        return temp;
    else
        return 0;
}

int main() {
    int number;
    scanf("%d\n", &number);
    long long int sum = 0;
    for (int i=1; i<=number; i++) {
        sum += printLastKDigits(i, i, 7);
    }
    printf("%lli\n",sum%10000000);
    return (0);
}
