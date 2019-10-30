// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int dayNumber(int day, int month, unsigned long long int year) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + t[month-1] + day) % 7;
}

int main() {
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        int day;
        int month;
        unsigned long long int year;
        scanf("%d%d%llu", &day,&month,&year);
        int days = dayNumber(day, month, year);
        if (days == 1) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
    return (0);
}
