// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=244&problem=3710&mosmsg=Submission+received+with+ID+21527431
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

bool isOne(string str) {
    int checks = 0;
    if (str.length() == 3) {
        if (str[0] == 'o') {
            checks++;
        }
        if (str[1] == 'n') {
            checks++;
        }
        if (str[2] == 'e') {
            checks++;
        }
    }
    if (checks >= 2) {
        return true;
    }
    return false;
}
bool isThree(string str) {
    if (str.length() == 5) {
        return true;
    }
    return false;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        string word;
        cin>>word;
        if (isThree(word)) {
            printf("3\n");
        } else if (isOne(word)) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
    return (0);
}
