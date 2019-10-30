// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

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

int main() {
    int n;
    while(cin>>n, n!=0) {
        int evens = 0;
        for (int t=1; t<=n; t++) {
            vector<int> pf = PrimeFactors(t);
            for(int i=0; i<pf.size(); i++) {
                cout<<pf[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    return (0);
}
