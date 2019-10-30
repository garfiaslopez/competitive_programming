// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// reference url: https://www.hackerrank.com/challenges/leonardo-and-prime/problem
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
    if (limit > 2)
        primes.push_back(2);
    if (limit > 3)
        primes.push_back(3);
    for (int x = 1; x * x < limit; x++) {
        for (int y = 1; y * y < limit; y++) {
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
    for (int r = 5; r * r < limit; r++) {
        if (sieve[r]) {
            for (int i = r * r; i < limit; i += r * r)
                sieve[i] = false;
        }
    }
}

int main() {
    for (int i = 0; i <= MAX; i++)
        sieve[i] = false;
    SieveOfAtkin(MAX);
    for (long int a = 5; a < MAX; a++) {
        if (sieve[a]) {
            primes.push_back(a);
        }
    }
    int cases;
    scanf("%d", &cases);
    unsigned long long int numberForSearch;
    while (cases--) {
        scanf("%lld", &numberForSearch);
        unsigned long long int multiplier = 1;
        int indexPrime = 0;
        int uniquePrimes = 0;
        while(multiplier <= numberForSearch) {
            if (indexPrime <= primes.size() - 1) {
                multiplier *= primes[indexPrime];
                if (multiplier <= numberForSearch) {
                    uniquePrimes++;
                }
                indexPrime++;
            } else {
                break;
            }
        }
        printf("%d\n", uniquePrimes);
    }
    return 0;
}
