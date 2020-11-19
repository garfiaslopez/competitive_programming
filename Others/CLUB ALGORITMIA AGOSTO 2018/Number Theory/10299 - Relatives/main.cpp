// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while(cin>>n && n > 0) {
        int coprimes = 0;
        for (int i=1; i<n; i++) {
            if (__algo_gcd(i,n) == 1) {
                coprimes++;
            }
        }
        cout<<coprimes<<endl;
    }
    return (0);
}
