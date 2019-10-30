// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases = 0;
    scanf("%d", &cases);
    while (cases--) {
        int m;
        int n;
        scanf("%d %d", &n, &m);
        int nDiv = n/3;
        int mDiv = m/3;
        printf("%d\n", nDiv * mDiv);
    }
    return (0);
}
