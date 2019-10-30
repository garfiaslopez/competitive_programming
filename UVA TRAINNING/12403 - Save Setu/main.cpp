// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=279&page=show_problem&problem=3834
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases;
    scanf("%d", &cases);
    int totalAmount = 0;
    while (cases--) {
        string operation;
        cin>>operation;
        if (operation == "donate") {
            int donation;
            scanf("%d", &donation);
            totalAmount += donation;
        } else if (operation == "report") {
            printf("%d\n", totalAmount);
        }
    }
    return (0);
}
