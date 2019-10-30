// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    char character;
    bool openQuoted = true;
    while(scanf("%c", &character) != EOF) {
        if (character == '"') {
            if (openQuoted) {
                printf("``");
                openQuoted = false;
            } else {
                printf("''");
                openQuoted = true;
            }
        } else {
            printf("%c", character );
        }
    }
    return (0);
}
