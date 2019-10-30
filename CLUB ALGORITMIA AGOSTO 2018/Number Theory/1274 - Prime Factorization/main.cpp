// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> primes;
vector<int> Sieve(1001);

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

// Prime Factors of X:
void prime_factors_of_n(int n, map<int,int> &mapped_primes) {
    vector<int> prime_factors;
    int raiz = sqrt(n);
    for (int i=2; i<=raiz; i++) {
        while(n%i==0) {
            mapped_primes[i] = mapped_primes[i] + 1;
            n = n/i;
        }
    }
    if (n>1) {
        mapped_primes[n] = mapped_primes[n] + 1;
    }
}
void print_width_3 (int n) {
    if (n >= 100) {
        cout<<n;
    } else if (n > 9) {
        cout<<" "<<n;
    } else {
        cout<<"  "<<n;
    }
}

void print_new_line() {
    cout<<endl<<"      ";
}

int main() {
    primes_until_n(100);

    int n;
    while(cin>>n && n > 0) {
        map<int,int> mapped_primes;
        for (int i=2; i<=n; i++) {
            prime_factors_of_n(i, mapped_primes);
        }
        map<int,int>::iterator it;
        print_width_3(n);
        cout<<"! =";
        int primes = 0;
        for (it=mapped_primes.begin(); it!=mapped_primes.end(); it++) {
            if(primes == 15) {
                print_new_line();
                primes = 0;
            }
            primes++;
            print_width_3(it->second);
        }
        cout<<endl;
    }

    return (0);
}
