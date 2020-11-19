// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

bitset<1010> Sieve;
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

int sum_of_divisors_of_n(int n) {
    int sum = 0;
    int raiz = sqrt(n);
    for (int i=1; i<=raiz; i++) {
        if (n%i == 0) {
            sum += i;
            if (n/i != i) {
                sum += n/i;
            }
        }
    }
    return sum;
}

int main() {
    primes_until_n(1005);
    int caso = 0;
    int n;
    while(cin>>n && n > 0) {
        caso++;
        if (n-1 > 1) {
            if (Sieve[n-1] == 1 && Sieve[n] == 0) {
                cout<<"Case "<<caso<<": "<<n-1<<endl;
            } else {
                int res = -1;
                for (int i=1; i<=1000; i++) {
                    int s = sum_of_divisors_of_n(i);
                    if (s == n && s >= res) {
                        res = i;
                    }
                }
                cout<<"Case "<<caso<<": "<<res<<endl;
            }
        } else {
            if (n==1) 
                cout<<"Case "<<caso<<": "<<1<<endl;
            if (n==2)
                cout<<"Case "<<caso<<": "<<-1<<endl;
        }
    }
    return (0);
}
