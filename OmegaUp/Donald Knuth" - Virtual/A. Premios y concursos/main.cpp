// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int prices;
    int cases;
    int priceValues[10001];
    scanf("%d%d", &prices, &cases);
    for (int i=0; i<prices; i++) {
        scanf("%d", &priceValues[i]);
    }
    while (cases--) {
        int maximumValue;
        int actualLarge = priceValues[0];
        scanf("%d", &maximumValue);
        for(int i=prices - 1; i>=0; i--) {
            if (priceValues[i] > actualLarge && priceValues[i] <= maximumValue) {
                actualLarge = priceValues[i];
            }
        }
        printf("%d ", actualLarge);
    }
    return (0);
}
