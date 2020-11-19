//
//  main.cpp
//  Factovisors
//
//  Created by Jose De Jesus Garfias Lopez on 3/20/18.
//  Copyright © 2018 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// se calcula la criba hasta este numero por que sqrt(2^31);

#define MAX 46341
bitset<MAX> sieve;
vector<int> primes;

map<int,int> primesOfNumber;

int factorialNumber = 0;
int testNumber = 0;
bool canDivide = true;


void c_sieve() { // do the Sieve of Eratosthenes
    sieve.set();
    for (int i = 2; i < MAX; i++) {
        if (sieve.test(i)) {
            primes.push_back(i);
            for (int j = i*i; j < MAX; j+=i) sieve.reset(j);
        }
    }
}

void getPrimes(int number) {
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= number; i++) {
        while (number % primes[i] == 0) {
            number /= primes[i];
            if (primesOfNumber[primes[i]]) {
                primesOfNumber[primes[i]] = primesOfNumber[primes[i]] + 1;
            } else {
                primesOfNumber[primes[i]] = 1;
            }
        }
    }
    if (number != 1) {
        if (primesOfNumber[number]) {
            primesOfNumber[number] = primesOfNumber[number] + 1;
        } else {
            primesOfNumber[number] = 1;
        }
    }
}

int getPower(int n, int p) {
    int sum = 0;
    if (n == p) {
        sum = 1;
    } else {
        long int exponent = p;
        int i = 1;
        while (exponent <= n) {
            exponent = pow(p, i);
            i++;
            sum = sum + floor(n/exponent);
        }
    }
    return sum;
}

void process() {  // do the Legendre's formula
    getPrimes(testNumber); // obtener los primos del numero a testear.
    for(auto it = primesOfNumber.cbegin(); it != primesOfNumber.cend(); ++it) {
        int power = getPower(factorialNumber, it->first);
        if (it->second > power) {
            canDivide = false;
            break;
        }
    }
}

void print() {
    if(canDivide) {
        printf("%d divides %d!\n",testNumber,factorialNumber);
    } else {
        printf("%d does not divide %d!\n",testNumber,factorialNumber);
    }
}

void clear() {
    primesOfNumber.clear();
    canDivide = true;
}

int main(int argc, char const *argv[]) {
    c_sieve();
    while ((scanf("%d %d", &factorialNumber, &testNumber)) != EOF) {
        process();
        print();
        clear();
    }
    return 0;
}

