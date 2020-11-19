// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//


#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

vector<int> sieve_until_intmax() {
    int MAX = 46341;
    bitset<46341> sieve;
    vector<int> primes;
    sieve.set();
    for (int i = 2; i < MAX; i++) {
        if (sieve.test(i)) {
            primes.push_back(i);
            for (int j = i*i; j < MAX; j+=i) {
                sieve.reset(j);
            }
        }
    }
    return primes;
}

typedef unsigned long long int Long;

bool is_prime(Long n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    Long raiz = sqrtl(n);
    if (n%2 == 0 || n%3 == 0) return false; 
    for (Long i=5; i*i<=n; i=i+6) {
        if (n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> primes = sieve_until_intmax();

    int n;
    cin>>n;

    if (n == 3) { cout<<1<<endl<<3<<endl; }
    for (int i=n-1; i>=3; i--) {
        if (is_prime(i)) {
            // cout<<i<<endl;
            for (int j=0; j<primes.size(); j++) {
                int P = n - i - primes[j];
                if (P==0) {
                    cout << 2 << endl;
                    cout << i << " " << primes [j] << endl;
                    break;
                } else if (is_prime(P)) {
                    cout << 3 << endl;
                    cout << i << " " << primes [j] << " " << n - i - primes[j]<< endl;
                    break;
                }
            }
            break;
        }
    }

    return (0);
}
