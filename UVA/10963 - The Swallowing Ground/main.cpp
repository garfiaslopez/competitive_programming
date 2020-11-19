// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1904
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int cases;
    scanf("%d\n", &cases);
    while (cases--) {
        int columns;
        scanf("%d", &columns);
        int diff;
        bool gapClosed = true;
        for(int i=0; i<columns; i++) {
            int maxNorh, maxSouth;
            scanf("%d %d", &maxNorh,&maxSouth);
            int tmp = maxNorh - maxSouth;
            if (i==0) {
                diff = tmp;
            } else if (i>0) {
                if (tmp != diff) {
                    gapClosed = false;
                }
            }
        }
        if (gapClosed) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
        if (cases){
            printf("\n");
        }
    }
    return (0);
}
