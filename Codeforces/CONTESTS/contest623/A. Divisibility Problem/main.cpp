// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <math.h>       /* ceil */

using namespace std;

int main() {
    int cases;
    int a,b;
    cin>>cases;
    while(cases--) {
        cin>>a>>b;
        if (a%b != 0) {
            int residuo = a%b;
            int nextResult = ((a - residuo) + b);
            int steps = nextResult - a;
            cout<<steps<<endl;
        } else {
            cout<<0<<endl;
        }

    }
    return (0);
}
