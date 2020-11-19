// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=562
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

char typeOfSequence(string s) {
    int number = atoi(s.c_str());
    if (number == 1 | number == 4 | number == 78) {
        return '+';
    } else if (s[s.length() -1] == '5' && s[s.length()-2] == '3') {
        return '-';
    } else if (s[0] == '9' && s[s.length()-1] == '4') {
        return '*';
    } else if (s[0] == '1' && s[1] == '9' && s[2] == '0') {
        return '?';
    }
    return '?';
}

int main() {
    int cases;
    cin>>cases;
    while (cases--) {
        string sequence;
        cin>>sequence;
        cout<<typeOfSequence(sequence)<<endl;
    }
    return (0);
}
