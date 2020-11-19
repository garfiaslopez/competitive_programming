#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

#define MAX 1050
bitset<MAX> sieve;
vector<int> primes;

void c_sieve() {
    sieve.set();
    for (int i = 2; i < MAX; i++) {
        if (sieve.test(i)) {
            primes.push_back(i);
            for (int j = i*i; j < MAX; j+=i) sieve.reset(j);
        }
    }
}

vector<int> PrimeFactors(int number) {
    int N = number;
    vector<int> primeFact;
    int raiz = sqrt(N);
    for (int i=2; i<=raiz; i++) {
        while(N%i==0) {
            primeFact.push_back(i);
            N /= i;
        }
    }
    if (N>1) {
        primeFact.push_back(N);
    }
    return primeFact;
}

int main(int argc, char const *argv[]) {
    c_sieve();

    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;
    }

    return 0;
}