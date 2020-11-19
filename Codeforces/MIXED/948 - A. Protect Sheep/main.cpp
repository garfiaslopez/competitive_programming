// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://codeforces.com/problemset/problem/948/A
//
// © Jose Garfias Lopez
//


#include <cstdio>
#include <iostream>

using namespace std;

int Col[4] = { -1, 0, 1, 0 };
int Fil[4] = { 0, 1, 0, -1 };
char Matrix[520][520];
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

bool checkValidMatrix() {
    bool isValid = true;
    for (int i=1; i<=maxFil;i++) {
        for (int j=1; j<=maxCol; j++) {
            if (Matrix[i][j] == 'S') {
                for (int m=0; m<4; m++) {
                    if (Matrix[i+Fil[m]][j+Col[m]] == 'W') {
                        return false;
                    }
                }
            }
        }
    }
    return isValid;
}

void printValidMatrix() {
    for (int i=1; i<=maxFil; i++) {
        for (int j=1; j<=maxCol; j++) {
            if (Matrix[i][j] == '.') {
                cout<<"D";
            } else {
                cout<<Matrix[i][j];
            }
        }
        cout<<"\n";
    }
}

int main() {
    readMatrix();
    //borderMatrix();
    //printCompleteMatrix();
    if (checkValidMatrix()) {
        cout<<"Yes"<<endl;
        printValidMatrix();
    } else {
        cout<<"No"<<endl;
    }
   
    return (0);
}
