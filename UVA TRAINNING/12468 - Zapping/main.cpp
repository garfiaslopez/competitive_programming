// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3912
//
// © Jose Garfias Lopez
//

// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int now = 0, toSwitch = 0;
    bool keepCalculating = true;
    while(keepCalculating) {
        int a,b;
        cin>>a>>b;
        if (a == -1 || b == -1) {
            keepCalculating = false;
            break;
        }
        int now = min(a,b);
        int toSwitch = max(a,b);
        int stepsToFront = toSwitch - now;
        int stepsToBack = now + (99 - toSwitch) + 1;

        cout<<min(stepsToBack, stepsToFront)<<endl;
    }
    return (0);
}
