// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1299710

using namespace std;

vector<int> primes;
vector<int> sieve(MAX + 1);

void c_sieve(int n) {
	int raiz = sqrt(n);
	for (int i = 4; i <= n; i += 2)
		sieve[i] = 2;
	for (int i = 3; i <= raiz; i += 2)
		if (!sieve[i])
			for (int j = i * i; j <= n; j += i)
				if (!sieve[j]) sieve[j] = i;
	for(int i = 0; i < n; i++ ){
		if( sieve[i] == 0 ) primes.push_back( i );
	}
}

int main() {
    c_sieve(MAX); // max number by the problem 100001 th prime
    int k;
    while(cin>>k, k != 0) {
        if (sieve[k] != 0) { // check if is prime:
            int indexGreatherK = -1;
            int indexLowerK = -1;
            for (int i=0; i<100001; i++) {
                if (primes [i] < k) {
                    indexLowerK = i;
                }
                if (primes[i] > k ) {
                    indexGreatherK = i;
                    break;
                }
            }
            cout<<primes[indexGreatherK] - primes[indexLowerK]<<endl;

        } else {
            cout<<"0"<<endl;
        }
    }
    return (0);
}
