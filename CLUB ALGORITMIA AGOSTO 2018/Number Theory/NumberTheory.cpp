/*
    this is a implementation class for functions:
    g++ NumberTheory.cpp -o NumberTheory && ./NumberTheory
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

typedef unsigned long long int Long;


// Another sieve 

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

// Erasthothenes Sieve (give max N number to check & return the primes)
vector<int> primes_until_n(int n) {
    vector<int> primes;
	int raiz = sqrt(n);
	vector<int> Sieve(n + 1);
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
	return primes;
}

bool is_prime(int n) {
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
    for (int i=5; i*i<=n; i=i+6) {
        if (n%i == 0 || n%(i+2) == 0) {
           return false;
        }
    }
    return true;
}


// Prime Factors of X:
vector<Long> prime_factors_of_n_long(Long n) {
    vector<Long> prime_factors;
    Long raiz = sqrt(n);
    for (Long i=2; i<=raiz; i++) {
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

// Prime Factors of X:
Long first_prime_factor_of_n(Long n) {
    Long raiz = sqrt(n);
    for (Long i=2; i<=raiz; i++) {
        while(n%i==0) {
            return i;
        }
    }
    if (n>1) {
        return n;
    }
    return -1;
}


// Prime Factors of X:
vector<int> prime_factors_of_n_2(int number) {
    vector<int> prime_factors;
    vector<int> primes = sieve_until_intmax();
    for (int i = 0; i < primes.size() && primes[i * primes[i]] <= number; i++) {
        // Si el numero es divisible por el primo actual
        while (number % primes[i] == 0) {
            number /= primes[i]; // Dividimos el número
            prime_factors.push_back(primes[i]);
        }
    }
    // Si hubo un residuo mayor a 1 quiere decir que es el único factor primo mayor a la raiz de N
    // Lo imprimimos
    if (number != 1) {
        prime_factors.push_back(number);
    }
    return prime_factors;
}


// Divisors of N
vector<int> divisors_of_n(int n) {
    vector<int> divisors;
    int cont = 0;
    int raiz = sqrt(n);
    for (int i=1; i<=raiz; i++) {
        if (n%i == 0) {
            divisors.push_back(i);
            if (n/i != i) {
                divisors.push_back(n/i);
            }
        }
    }
    return divisors;
}

int number_of_divisors_of_n(int n) {
    int sum = 0;
    for (int i=1; i<=sqrtl(n); i++) {
        if (n%i == 0) {
            sum += 2;
        }
        if (i*i == n) {
            sum -= 1;
        }
    }
    return sum;
}

int main() {
    //primes implementation:
    cout<<"primes until: 100"<<endl;
    vector<int> primes = primes_until_n(100);
    for (int i=0; i<primes.size(); i++) {
        cout<<primes[i]<< ",";
    }
    cout<<endl;

    // first prime factor of n

    //cout<<"first prime factor of (n): "<<first_prime_factor_of_n(24)<<endl;

    //prime factors:
    // cout<<"primes (method 1)"<<endl;
    // vector<Long> prime_factors = prime_factors_of_n_long(187917426909946969);
    // for (int i=0; i<prime_factors.size(); i++) {
    //     cout<< prime_factors[i] << ",";
    // }
    // cout<<endl;

    //prime factors with sieve:
    // cout<<"primes (method 2)"<<endl;
    // vector<int> prime_factors2 = prime_factors_of_n_2();
    // for (int i=0; i<prime_factors2.size(); i++) {
    //     cout<< prime_factors2[i] << ",";
    // }
    // cout<<endl;

    // divisors of n
    // vector<int> divisors = divisors_of_n(8);
    // for (int i=0; i<divisors.size(); i++) {
    //     cout<<divisors[i]<<",";
    // }
    // cout<<endl;

    return (0);
}