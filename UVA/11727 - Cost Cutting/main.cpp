// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2827
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases, number1, number2, number3;
    scanf("%d", &cases);
    for (int test = 1; test<=cases; test++) {
        scanf("%d%d%d", &number1, &number2, &number3);
        int numbers[3] = { number1, number2, number3 };
        int higher = 0;
        int lower = number1;
        int medium = 0;

        for (int i=0; i<3; i++) {
            if (numbers[i] > higher) {
                higher = numbers[i];
            }
            if (numbers[i] < lower) {
                lower = numbers[i];
            }
        }
        for (int i=0; i<3; i++) {
            if (numbers[i] != lower && numbers[i] != higher) {
                medium = numbers[i];
            }
        }
        printf("Case %d: %d\n", test, medium);
    }
    return (0);
}
