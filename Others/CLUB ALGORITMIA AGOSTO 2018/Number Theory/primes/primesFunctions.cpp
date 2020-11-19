#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> sieve(int N) {
    vector<bool> isPrime(N+1, true);
    vector<int> primes;

    // se tachan todos los numeros pares
    for (int i=4; i<=N; i+=2) {
        isPrime[i] = false;
    }

    // se empieza del 3 hasta
    for (int i=3; i*i <= N; i+=2) { // de 2 en 2 ya que tachamos los pares...
        if (isPrime[i]) {
            for (int j=i*i; i<=N; i+=2*i ) {
                isPrime[j] = false;
            }
        }
    }

    // recover all primes:
    for (int i=2; i<=N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    vector<int> primes = sieve(13);
    for (int i=0; i<primes.size();i++){
        cout<<primes[i]<<" ";
    }
    cout<<endl;
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