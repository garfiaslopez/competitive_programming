// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
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

bool isSquareFree(int n) {
    if (n % 2 == 0)
       n = n/2;
    if (n % 2 == 0)
       return false;
    for (int i = 3; i <= sqrt(n); i = i+2) {
        if (n % i == 0) {
           n = n/i;
           if (n % i == 0)
               return false;
        }
    }
    return true;
}

void print() {
    int squareFree = 0;
    for (int i = 0; i < results.size(); i++) {
        if (isSquareFree(results[i])) {
            squareFree++;
        }
    }
    printf("%d\n", squareFree);
    results.clear();
}

int main(int argc, char const *argv[]) {
    c_sieve();
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &numberToProcess);
        process();
        print();
    }
    return 0;
}
