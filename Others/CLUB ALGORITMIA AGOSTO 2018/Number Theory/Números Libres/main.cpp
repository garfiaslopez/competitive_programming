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
    int cases;
    cin>>cases;
    while(cases--) {
        unsigned long long int a,b;
        cin>>a>>b;
        if (__algo_gcd(a,b) == 1) {
            cout<<"SI"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return (0);
}
