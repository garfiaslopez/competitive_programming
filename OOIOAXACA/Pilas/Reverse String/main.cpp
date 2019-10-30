// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main() {

    string palabra;
    stack<char> pila;

    cin>>palabra;

    for (int i = 0; i<palabra.size(); i++) {
        pila.push(palabra[i]);
    }

    while(!pila.empty()) {
        cout<< pila.top() ;
        pila.pop();
    }
    cout<<endl;

    return (0);
}
