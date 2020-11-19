// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases = 0;
    cin>>cases;
    while(cases--) {
        int a,b;
        cin>>a>>b;
        int minimum = min(a,b);
        int maximum = max(a,b);

        if (minimum == maximum) {
            cout << (minimum * 2) * (maximum * 2) << endl;
        } else if ((minimum * 2) <= maximum) {
            cout << maximum * maximum << endl;
        } else if ((minimum * 2) > maximum) {
            cout << (minimum*2) * (minimum*2) << endl;
        }
    }
    return (0);
}
