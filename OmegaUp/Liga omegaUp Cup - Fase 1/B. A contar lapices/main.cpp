// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tam, k, counter = 0;
    cin>>tam>>k;
    for (int i=0; i<tam;i++) {
        int number;
        cin>>number;
        if(number == k) {
            counter++;
        }
    }
    cout<<counter<<endl;
    
    return (0);
}
