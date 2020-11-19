// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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
    vector<int> criba = Criba(2000);
    string word;
    while(cin>>word) {
        int total_words = 0;
        for(int i=0; i<word.length();i++) {
            int actual = word[i] - 96;
            if (actual < 0) {
                actual += 58;
            }
            total_words += actual;
        }
        if (criba[total_words] == 0) {
            cout<<"It is a prime word."<<endl;
        } else {
            cout<<"It is not a prime word."<<endl;
        }
    }
    return (0);
}
