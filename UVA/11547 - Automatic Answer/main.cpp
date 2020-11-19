// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2542
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases, n;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        int operation = (((((((((n * 567) / 9) + 7492) * 235) / 47) - 498)) % 100) / 10);
        if (operation < 0) {
            operation *= -1;
        }
        printf("%d\n", operation);
    }
    return (0);
}
