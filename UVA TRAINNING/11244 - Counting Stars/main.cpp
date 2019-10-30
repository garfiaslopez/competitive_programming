// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2201
// © Jose Garfias Lopez
//
//

#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int filTam;
int colTam;
int skyMap[103][103];

int FIL[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int COL[8] = { 1, -1, 1, 0, -1, 1, -1, 0 };

void read() {
    for (int i=1; i<=filTam; i++) {
        char line[colTam];
        fflush(stdin);
        scanf("%s\n", line);
        for (int j=0;j<colTam;j++) {
            if (line[j] == '*') {
                skyMap[i][j+1] = 1;
            } else {
                skyMap[i][j+1] = 0;
            }
        }
    }
}

void border() {
    for (int i=0; i<=filTam + 1; i++) {
        skyMap[i][0] = -1;
        skyMap[i][colTam + 1] = -1;
    }
    for (int j=0; j<=colTam + 1; j++) {
        skyMap[0][j] = -1;
        skyMap[filTam + 1][j] = -1;
    }
}

bool isAlone(int i, int j) {
    for (int m=0; m<8; m++) {
        int fil = i + FIL[m];
        int col = j + COL[m];
        if (skyMap[fil][col] == 1) {
            return false;
        }
    }
    return true;
}

int process() {
    int alone = 0;
    for (int i=1; i<=filTam; i++) {
        for (int j=1;j<=colTam;j++) {
            if (skyMap[i][j] == 1) {
                if (isAlone(i,j)) {
                    alone++;
                }
            }
        }
    }
    return alone;
}

void printMatrix() {
    for (int i=0; i<=filTam + 1; i++) {
        for (int j=0; j<=colTam + 1; j++) {
            printf("%d ", skyMap[i][j]);
        }
        printf("\n");
    }
}

int main() {
    while (scanf("%d%d\n", &filTam, &colTam) == 2) {
        if (filTam != 0 && colTam != 0) {
            read();
            border();
            //printMatrix();
            int alones = process();
            printf("%d\n", alones);
        }
    };
    return (0);
}
