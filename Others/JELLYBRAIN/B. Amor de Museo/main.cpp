// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//


#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

queue <pair<int, int> > Q;
int filTam;
int colTam;
int skyMap[10003][10003];
int FIL[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int COL[8] = { 1, -1, 1, 0, -1, 1, -1, 0 };

//    -1 You can`t pass
//    -2 (SOURCE)
//    -3 (OBJECTIVE)
//     0 For Process

void read() {
    for (int i=1; i<=filTam; i++) {
        char line[colTam];
        fflush(stdin);
        scanf("%s\n", line);
        for (int j=0;j<colTam;j++) {
            if (line[j] == '*') {
                skyMap[i][j+1] = -1;
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
void DiscoverDeposit() {
    while (!Q.empty()) {
        pair<int,int> point = Q.front();
        for (int m=0; m<8; m++) {
            int fil = point.first + FIL[m];
            int col = point.second + COL[m];
            if (skyMap[fil][col] == 1) {
                skyMap[fil][col] = 2;
                pair<int,int> p;
                p.first = fil;
                p.second = col;
                Q.push(p);
            }
        }
        Q.pop();
    }
}
int process() {
    int deposits = 0;
    for (int i=1; i<=filTam; i++) {
        for (int j=1;j<=colTam;j++) {
            if (skyMap[i][j] == 1) {
                skyMap[i][j] = 2;
                pair<int,int> p;
                p.first = i;
                p.second = j;
                Q.push(p);
                DiscoverDeposit();
                deposits++;
            }
        }
    }
    return deposits;
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
            int d = process();
            printf("%d\n", d);
        }
    };
    return (0);
}
