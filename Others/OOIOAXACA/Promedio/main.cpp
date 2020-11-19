// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int suma_de_calficaciones (int n) {
    int suma = 0;
    for (int i=0; i<n; i++) {
        int numero;
        cin>>numero;
        suma = suma + numero;
    }
    return suma;
}

int main() {
    int n;
    cin>>n;
    int suma = suma_de_calficaciones(n);
    float resultado = suma/n;
    cout<<fixed<<setprecision(2)<<resultado<<endl;
    return (0);
}
