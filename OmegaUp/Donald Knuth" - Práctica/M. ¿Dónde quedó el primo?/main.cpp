// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// reference url: https://www.geeksforgeeks.org/sieve-of-atkin/
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 9832717

// Initialise the sieve array with false values
bool sieve[MAX];
vector<long int> primes;

void SieveOfAtkin(int limit) {
    // 2 and 3 are known to be prime
    if (limit > 2)
        primes.push_back(2);
    if (limit > 3)
        primes.push_back(3);

    /* Mark siev[n] is true if one
       of the following is true:
    a) n = (4*x*x)+(y*y) has odd number of
       solutions, i.e., there exist
       odd number of distinct pairs (x, y)
       that satisfy the equation and
        n % 12 = 1 or n % 12 = 5.
    b) n = (3*x*x)+(y*y) has odd number of
       solutions and n % 12 = 7
    c) n = (3*x*x)-(y*y) has odd number of
       solutions, x > y and n % 12 = 11 */
    for (int x = 1; x * x < limit; x++) {
        for (int y = 1; y * y < limit; y++) {

            // Main part of Sieve of Atkin
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;

            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }

    // Mark all multiples of squares as non-prime
    for (int r = 5; r * r < limit; r++) {
        if (sieve[r]) {
            for (int i = r * r; i < limit; i += r * r)
                sieve[i] = false;
        }
    }
}

int main() {

    for (int i = 0; i < MAX; i++)
        sieve[i] = false;
    SieveOfAtkin(MAX);
    for (long int a = 5; a <= MAX; a++) {
        if (sieve[a]) {
            primes.push_back(a);
        }
    }
    int numberForSearch;

    scanf("%d", &numberForSearch);
    printf("%ld\n", primes[numberForSearch - 1]);

    return 0;
}
