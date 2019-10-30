// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// Reference url: https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
// © Jose Garfias Lopez
//
#include <stdio.h>
#include <string.h>

using namespace std;

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
int count( int S[], int m, unsigned long long int n ) {
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is constructed
    // in bottom up manner using the base case (n = 0)
    unsigned long long table[n+1];
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    // Base case (If given value is 0)
    table[0] = 1;
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(unsigned long long int i=0; i<m; i++)
        for(unsigned long long int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
    return table[n];
}

int main() {
    int numbers;
    int arrayOfNumbers[605];
    unsigned long long int desiredNumber;
    scanf("%d\n", &numbers);
    for (int i=0; i<numbers; i++) {
        int number;
        scanf("%d", &number);
        arrayOfNumbers[i] = number;
    }
    scanf("%llu", &desiredNumber);
    int visited[desiredNumber];
    memset(visited, 0, sizeof(visited));
    unsigned long long int totalWays =  0;
    for (int i=0; i<numbers; i++) {
        visited[desiredNumber - arrayOfNumbers[i]] = count(arrayOfNumbers, numbers, (desiredNumber - arrayOfNumbers[i]));
        if (visited[desiredNumber - arrayOfNumbers[i]] != 0) {
            totalWays += visited[desiredNumber - arrayOfNumbers[i]];
        }
    }
    printf("%llu\n",totalWays);
    return (0);
}
