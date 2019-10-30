// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int tam, rotations;
    cin>>tam>>rotations;
    int numbers[tam];
    int rotated[tam];

    for (int i=0;i<tam;i++) {
        cin>>numbers[i];
    }
    
    int minRotations = rotations%tam;
    int steps = tam - minRotations;

    for (int i=0; i<tam; i++) {
        int newIndex = (i + steps) % tam;
        rotated[newIndex] = numbers[i];
    }
    for (int i=0; i<tam; i++) {
        cout<<rotated[i]<<" ";
    }
    cout<<endl;
    return (0);
}
