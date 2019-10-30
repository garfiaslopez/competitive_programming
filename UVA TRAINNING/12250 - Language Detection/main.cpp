// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=244&page=show_problem&problem=3402
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string wordString;
    int iteration = 0;
    while (cin>>wordString, wordString != "#") {
        iteration++;
        if (wordString == "HELLO") {
            printf("Case %d: ENGLISH\n", iteration);
        } else if (wordString == "HOLA") {
            printf("Case %d: SPANISH\n", iteration);
        } else if (wordString == "HALLO") {
            printf("Case %d: GERMAN\n", iteration);
        } else if (wordString == "BONJOUR") {
            printf("Case %d: FRENCH\n", iteration);
        } else if (wordString == "CIAO") {
            printf("Case %d: ITALIAN\n", iteration);
        } else if (wordString == "ZDRAVSTVUJTE") {
            printf("Case %d: RUSSIAN\n", iteration);
        } else {
            printf("Case %d: UNKNOWN\n", iteration);
        }
    }
    return (0);
}
