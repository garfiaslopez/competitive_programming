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

vector<int> primes;
vector<int> Sieve(1000001);

void primes_until_n(int n) {
	int raiz = sqrt(n);
    //mark multiple of 2
	for (int i = 4; i <= n; i += 2)
		Sieve[i] = 2;
    //iterate until sqrt to odd's numbers
	for (int i = 3; i <= raiz; i += 2)
		if (!Sieve[i])
			for (int j = i * i; j <= n; j += i)
				if (!Sieve[j]) Sieve[j] = i;
    //return primes:
    for (int i=2; i<=n; i++) {
        if(Sieve[i] == 0) primes.push_back(i);
    }
}

string goldbach(int n) {
    for (int i=0; i<primes.size();i++) {
        int test = n - primes[i];
        if (test%2 != 0) {
            if (Sieve[test] == 0) {
                return to_string(n) + " = " + to_string(primes[i]) + " + " + to_string(test);
            }
        }
    }
    return "Goldbach's conjecture is wrong.";
}

int main() {
    primes_until_n(1000000);
    int n;
    while(cin>>n && n>0) {
        cout<<goldbach(n)<<endl;
    }
    return (0);
}
