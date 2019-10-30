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
        int markets = 0;
        scanf("%d",&markets);
        int lower = 99;
        int greater = 0;
        for (int i=0; i<markets; i++) {
            int place = 0;
            scanf("%d", &place);
            if (place >= greater) {
                greater = place;
            }
            if (place <= lower) {
                lower = place;
            }
        }
        printf("%d\n", ((greater - lower) * 2));
    }
    return (0);
}
