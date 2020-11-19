// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=246&page=show_problem&problem=3565
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int process(int sodas, int having, int cost) {

    if (cost == 1) {
        return 0;
    }

    int totalSodas = sodas + having;
    int newSodas = totalSodas/cost;
    int remind = totalSodas - (newSodas * cost);
    int canAfford = newSodas;

    while (newSodas != 0) {
        totalSodas = remind + newSodas;
        newSodas = totalSodas/cost;
        remind = totalSodas - (newSodas * cost);
        canAfford += newSodas;
    }

    return canAfford;
}

int main() {
    int bottles = -1;
    while (scanf("%d", &bottles) && bottles != 0) {
        printf("%d\n",process(bottles, 1, 3));
    }
    return (0);
}
