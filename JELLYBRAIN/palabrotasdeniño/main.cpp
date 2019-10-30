// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string carta;
    getline(cin,carta);

    for (int i=0; i<carta.length(); i++) {
	    char letra = carta[i];
        if (letra == ' ') {
            cout<<"espacio"<<endl;
        } else {
            cout<<"char: "<<letra<<endl;
        }
    }
    return (0);
}
