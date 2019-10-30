// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int M[6][6];
int PosFil[7] = {0,0,0,1,2,2,2};
int PosCol[7] = {0,1,2,1,0,1,2};

int main() {
    //read the matrix:
    for (int i=0; i<6;i++) {
        for (int j=0; j<6;j++) {
            cin>>M[i][j];
        }
    }
    //process
    int greaterSum = -99;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            // here do the sum for the hourglass
            int tempSum = 0;
            for (int m=0;m<7;m++) {
                tempSum += M[i+PosFil[m]][j+PosCol[m]];
            }
            if (tempSum >= greaterSum) {
                greaterSum = tempSum;
            }
        }
    }
    cout<<greaterSum<<endl;
    return (0);
}
