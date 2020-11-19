// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

bitset<33> Sieve;

void primes_until_n(int n) {
	int raiz = sqrt(n);
    Sieve.set();
    //mark multiple of 2
	for (int i = 4; i <= n; i += 2)
        Sieve.reset(i);
    //iterate until sqrt to odd's numbers
	for (int i = 3; i <= raiz; i += 2)
		if (Sieve[i])
			for (int j = i * i; j <= n; j += i)
				if (Sieve[j]) Sieve.reset(j);
}

// Prime Factors of X:
vector<int> prime_factors_of_n(int n) {
    vector<int> prime_factors;
    int raiz = sqrt(n);
    for (int i=2; i<=raiz; i++) {
        while(n%i==0) {
            prime_factors.push_back(i);
            n = n/i;
        }
    }
    if (n>1) {
        prime_factors.push_back(n);
    }
    return prime_factors;
}


int main() {
    primes_until_n(32);

    int n;
    while(cin>>n && n > 0) {
        int mersenne_prime = pow(2, n) - 1;
        //cout<<"mp:"<<mersenne_prime<<endl;
        vector<int> pf = prime_factors_of_n(mersenne_prime);

        // for(int i=0; i<pf.size(); i++) {
        //     cout<<pf[i]<<",";
        // }

        if (pf.size() == 1 && pf[0] == mersenne_prime) {
            if (Sieve[n] == 1) {
                unsigned long long int res = pow(2,(n - 1)) * mersenne_prime;
                cout<<"Perfect: "<<res<<"!"<<endl;
            }
        } else {
            if (Sieve[n] == 1) {
                cout<<"Given number is prime. But, NO perfect number is available."<<endl;
            } else {
                cout<<"Given number is NOT prime! NO perfect number is available."<<endl;
            }
        }
    }
    return (0);
}
