//
//  main.cpp
//  PrimeFactors
//
//  Created by Jose De Jesus Garfias Lopez on 3/19/18.
//  Copyright © 2018 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

// se calcula la criba hasta este numero por que sqrt(2^31);
#define MAX 46341
bitset<MAX> sieve;
vector<int> primes;


int numberToProcess = 1;
vector<int> results;

bool needEndl = false;

void c_sieve() {
    sieve.set();
    for (int i = 2; i < MAX; i++) {
        if (sieve.test(i)) {
            primes.push_back(i);
            for (int j = i*i; j < MAX; j+=i) sieve.reset(j);
        }
    }
}

void read() {
    cin>>numberToProcess;
}

void process() {
    int cribaIndex = 0;
    int numberToDivide = abs(numberToProcess);
    while (numberToDivide != 1) {
        int prime = primes[cribaIndex];
        if (prime != 0) {
            if ((numberToDivide % prime) == 0) { // es divisible entre:
                numberToDivide = numberToDivide/prime;
                results.push_back(prime);
            } else {
                cribaIndex++;
            }
        } else {
            numberToDivide = 1;
            results.push_back(abs(numberToProcess));
        }
    }
}

void print() {
    cout<< numberToProcess << " = ";
    if (numberToProcess < 0) {
        cout<<"-1 x ";
    }
    for (int i = 0; i < results.size(); i++) {
        cout << results[i];
        if (i != results.size() - 1) {
            cout<< " x ";
        } else {
            cout<<endl;
        }
    }
    results.clear();
}

int main(int argc, char const *argv[]) {
    c_sieve();
    while (cin>>numberToProcess && numberToProcess != 0) {
        process();
        print();
    }
    return 0;
}
