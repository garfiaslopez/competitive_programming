// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3084
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int my_pow(int x) {
    int p=1;
    for (int i=0;i<x;i++) {
        p *= 2;
    }
    return p;
}

int main() {
    int number;
    while (cin>>number, number != 0) {
        int a = 0, b = 0;
        int pos_on = 0;
        for (int i=0; i<32; i++) { // iterate bits;
            if (number & (1<<i)) { // if ith bit is ON
                if ((pos_on % 2) == 0) { // is even
                    a += my_pow(i);
                } else {
                    b += my_pow(i);
                }
                pos_on++; // move ON cursor.
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    return (0);
}
