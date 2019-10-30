// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=441&problem=4022&mosmsg=Submission+received+with+ID+21527534
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string god;
    int iterations = 0;
    while (cin>>god, god != "*") {
        iterations++;
        if (god == "Hajj") {
            printf("Case %d: Hajj-e-Akbar\n", iterations);
        } else if (god == "Umrah") {
            printf("Case %d: Hajj-e-Asghar\n", iterations);
        }
    }
    return (0);
}
