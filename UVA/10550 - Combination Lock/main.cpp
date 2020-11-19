// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=246&page=show_problem&problem=3565
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

// direction: 0-> cw y 1-> ccw
int calculateRotation(int start, int end, int direction) {
    int cw = 0;
    int ccw = 0;
    if (end > start) {
        ccw = end - start;
        cw = 40 - ccw;
    } else if (start > end) {
        cw = start - end;
        ccw = 40 - cw;
    }
    if (direction == 0) {
        return cw;
    }else{
        return ccw;
    }
    return 0;
}
double calculateDegress(int total) {
    double division = (total/40.0);
    double res = (division*360);
    return res;
}

int main() {
    int initialPosition = -1;
    int firstCombination = -1;
    int secondCombination = -1;
    int thirdCombination = -1;

    while(initialPosition != 0 || firstCombination != 0 || secondCombination != 0 || thirdCombination != 0) {
        scanf("%d %d %d %d", &initialPosition, &firstCombination, &secondCombination, &thirdCombination);
        if (initialPosition != 0 || firstCombination != 0 || secondCombination != 0 || thirdCombination != 0) {
            int totalNumbers = 120; //offsset (cw, ccw)
            int firstOffset = calculateRotation(initialPosition, firstCombination, 0);
            int secondOffset = calculateRotation(firstCombination, secondCombination, 1);
            int thirdOffset = calculateRotation(secondCombination, thirdCombination, 0);
            int total = totalNumbers + firstOffset + secondOffset + thirdOffset;
            printf("%.0f\n", calculateDegress(total));
        }
    }
    return (0);
}
