// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases;
    while (scanf("%d", &cases) && cases != 0) {
        int originX;
        int originY;
        scanf("%d %d", &originX, &originY);
        int iterations = cases;
        while (iterations--) {
            int pointX;
            int pointY;
            scanf("%d %d", &pointX, &pointY);
            int newPointX = pointX - originX;
            int newPointY = pointY - originY;

            if (newPointX == 0 || newPointY == 0) {
                printf("divisa\n");
            } else if (newPointX < 0 && newPointY > 0) {
                printf("NO\n");
            } else if (newPointX > 0 && newPointY > 0) {
                printf("NE\n");
            } else if (newPointX > 0 && newPointY < 0) {
                printf("SE\n");
            } else if (newPointX < 0 && newPointY < 0) {
                printf("SO\n");
            }
        }
    }
    return (0);
}
