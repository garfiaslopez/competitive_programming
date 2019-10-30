// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=25&problem=2307&mosmsg=Submission+received+with+ID+21594911
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int charToInt(char c) {
    return c - '0';
}

string doSumDigits(string s) {
    int sum = 0;
    for (int i=0; i<s.length(); i++) {
        sum += charToInt(s[i]);
    }
    if (sum <= 9) {
        return to_string(sum);
    } else {
        return doSumDigits(to_string(sum));
    }
}

int main() {
    string n;
    while (cin>>n, n != "0") {
        cout<<doSumDigits(n)<<endl;
    }
    return (0);
}
