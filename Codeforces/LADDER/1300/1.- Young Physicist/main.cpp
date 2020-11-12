// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:   https://codeforces.com/problemset/problem/69/A
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x = 0,y = 0,z = 0;

    int forces;

    cin>>forces;

    while(forces--) {
        int a,b,c;
        cin>>a>>b>>c;
        
        x = x + a;
        y = y + b;
        z = z + c;
    }

    if (x==0 && y==0 && z==0) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return (0);
}
