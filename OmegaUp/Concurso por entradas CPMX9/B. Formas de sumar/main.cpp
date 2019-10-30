// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//
#include <stdio.h>
#include <string.h>

using namespace std;

int count(int S[], int m, int n ) {
    int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
    return table[n];
}

int main() {
    int number;
    int arrayOfNumbers[100];
    scanf("%d\n", &number);
    for (int i=0; i<number - 1; i++) {
        arrayOfNumbers[i] = i + 1;
    }
    int total = count(arrayOfNumbers, number - 1, number);
    printf("%d\n",total);
    return (0);
}
