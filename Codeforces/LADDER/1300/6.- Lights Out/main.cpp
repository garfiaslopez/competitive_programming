// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix (3, vector<int>(3, 0));
vector<vector<int>> sumMatrix (3, vector<int>(3, 0));
int maxY = 3;
int maxX = 3;

/*
void sumToUp(int posi, int posj, int sumVal) {
    for (int i=posi-1; i>=0; i--) {
        sumMatrix[i][posj] += sumVal;
    }
}
void sumToDown(int posi, int posj, int sumVal) {
    for (int i=posi+1; i<maxY; i++) {
        sumMatrix[i][posj] += sumVal;
    }
}
void sumToLeft(int posi, int posj, int sumVal) {
    for (int i=posj-1; i>=0; i--) {
        sumMatrix[posi][i] += sumVal;
    }
}
void sumToRight(int posi, int posj, int sumVal) {
    for (int i=posj+1; i<maxX; i++) {
        sumMatrix[posi][i] += sumVal;
    }
}
*/
// 4 Way lookup
vector<int> FIL = {-1,0,1,0 };
vector<int> COL = { 0,1,0,-1};

int main() {
    // read
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin>>matrix[i][j];
        }
    }
    // process;

    for (int i=0; i<maxX; i++) {
        for (int j=0; j<maxY; j++) {
            int sumVal = matrix[i][j];

            sumMatrix[i][j] += sumVal;

            for (int m=0; m<4; m++) {
                int newI = i + FIL[m];
                int newJ = j + COL [m];

                if (newI >= 0 && newI < maxX && newJ >=0 && newJ < maxY) {
                    sumMatrix[newI][newJ] += sumVal;
                }

            }
        } 
    }
    // debug m



    // print
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            // result:
            if ((sumMatrix[i][j] % 2) == 0) {
                cout<<1;
            } else {
                cout<<0;
            }
        }
        cout<<endl;
    }

    return (0);
}
