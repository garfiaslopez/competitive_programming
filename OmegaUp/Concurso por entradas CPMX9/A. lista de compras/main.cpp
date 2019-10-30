// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string.h>
#include <iterator>
#include <map>

using namespace std;

map<string, int>MapLetters;

int main() {
    char Map[1000];
    int productsTotal;
    int listTotal;
    scanf("%d%d\n",&productsTotal, &listTotal);
    fflush(stdin);
    for (int i=0; i<listTotal; i++) {
        string product;
        int price;
        cin>>product;
        cin>>price;
        MapLetters[product] = price;
    }
    int total = 0;
    for (int i=0; i<productsTotal; i++) {
        string productToBuy;
        cin>>productToBuy;
        if (MapLetters[productToBuy]) {
            total += MapLetters[productToBuy];
        }
    }
    printf("%d\n", total);
    return (0);
}
