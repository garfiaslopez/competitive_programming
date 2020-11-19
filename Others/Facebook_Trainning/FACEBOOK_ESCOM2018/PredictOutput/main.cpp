// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int Matrix [3][4];
int MatrixB[3][4];

void read() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<4;j++) {
            cin>>Matrix[i][j];
        }
    }
}

void print() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<4;j++) {
            cout<<MatrixB[i][j]<<" ";
        }
    }
}

int main() {
    
    read();
    for (int i=0;i<3;i++) {
        for (int j=0;j<4;j++) {
            MatrixB[i][4 - 1 - j] = Matrix[i][j];
        }
    }
    print();


    return (0);
}
