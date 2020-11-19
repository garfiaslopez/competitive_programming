// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://omegaup.com/arena/problem/Formula-Recursiva-Tres
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

typedef long long ll;

using namespace std;

ll f(ll n) {
    if (n > 5) {
        return f(n-2) * 5;
    }
    return 1;
}

int main() {
    ll n;
    cin>>n;
    cout<<f(n)<<endl;
    return (0);
}
