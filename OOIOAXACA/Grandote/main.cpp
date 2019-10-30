// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://omegaup.com/arena/problem/pow-2#problems
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int suma_de_potencia_de_2(int n) {
    int sum = 0;
    for (int i=0; i<=n; i++) {
        sum = sum + pow(2,i);
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    int sum = suma_de_potencia_de_2(n);
    cout<<sum;
    return (0);
}
