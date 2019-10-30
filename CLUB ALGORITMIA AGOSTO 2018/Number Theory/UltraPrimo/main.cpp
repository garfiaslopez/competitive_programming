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

#define MAX 2000

using namespace std;

int charToInt(char c) {
    return c - '0';
}

vector<int> primes;
vector<int> Criba(int n) {
	int raiz = sqrt(n);
	vector<int> criba(n + 1);
	for (int i = 4; i <= n; i += 2)
		criba[i] = 2;
	for (int i = 3; i <= raiz; i += 2)
		if (!criba[i])
			for (int j = i * i; j <= n; j += i)
				if (!criba[j]) criba[j] = i;
	return criba;
}

int main() {
    vector<int> criba = Criba(1100);
    for( int i = 0; i < 1100; i++ ){
		if( criba[i] == 0 ) primes.push_back( i );
	}
    //fill_sieve(2000);
    //c_sieve();
    int cases;
    cin>>cases;
    while(cases--) {
        string numbers;
        cin>>numbers;
        int sum = 0;
        for (int i=0; i<numbers.length();i++) {
            sum += charToInt(numbers[i]);
        }
        bool isUltraPrime = false;
        for (int i=0; i<primes.size(); i++) {
            if (primes[i] == sum) {
                isUltraPrime = true;
                break;
            }
        }
        if (isUltraPrime) {
            cout<<"UltraPrimo"<<endl;
        } else {
            cout<<"No UltraPrimo"<<endl;
        }
    }

    return (0);
}
