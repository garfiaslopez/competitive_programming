// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=278&page=show_problem&problem=3794
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases;
    scanf("%d", &cases);
    for (int i=1; i<=cases; i++) {
        int l,w,h;
        scanf("%d%d%d", &l,&w,&h);
        if (l > 20 || w > 20 || h > 20) {
            printf("Case %d: bad\n", i);
        } else {
            printf("Case %d: good\n", i);
        }
    }
    return (0);
}
