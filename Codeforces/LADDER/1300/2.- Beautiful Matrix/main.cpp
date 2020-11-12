// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:   https://codeforces.com/problemset/problem/263/A
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    for (int i=1; i<=5; i++) {
        for (int j=1; j<=5; j++) {
            int x;
            cin>>x;

            if (x == 1) {
                int res = abs(3-i) + abs(3-j);
                cout<<res<<endl;
                break;
            }
        }
    }

    return (0);
}
