// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int Col[4] = { -1, 0, 1, 0 };
int Fil[4] = { 0, 1, 0, -1 };
char Matrix[120][120];
int maxFil;
int maxCol;

void readMatrix() {
    cin>>maxFil>>maxCol;
    for (int i=1;i<=maxFil; i++) {
        for(int j=1; j<=maxCol; j++) {
            cin>>Matrix[i][j];
        }
    }
}
void borderMatrix() {
    for (int i=0; i<=maxCol + 1; i++) {
        Matrix[0][i] = '.';
        Matrix[maxFil+1][i] = '.';
    }
    for(int i=0; i<=maxFil + 1; i++) {
        Matrix[i][0] = '.';
        Matrix[i][maxCol+1] = '.';
    }
}

void process() {
    for (int i=1; i<=maxFil;i++) {
        for (int j=1; j<=maxCol; j++) {
            if (Matrix[i][j] != '-') {
                if ((i+j) % 2 == 0) {
                    Matrix[i][j] = 'B';
                } else {
                    Matrix[i][j] = 'W';
                }
            }
        }
    }
}

void printMatrix() {
    for (int i=1; i<=maxFil; i++) {
        for (int j=1; j<=maxCol; j++) {
            cout<<Matrix[i][j];
        }
        cout<<"\n";
    }
}

void printCompleteMatrix() {
    for (int i=0; i<=maxFil+1; i++) {
        for (int j=0; j<=maxCol+1; j++) {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    readMatrix();
    //borderMatrix();
    //printCompleteMatrix();
    process();
    printMatrix();
    return (0);
}
