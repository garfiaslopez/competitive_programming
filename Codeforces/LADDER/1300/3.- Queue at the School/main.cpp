// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:   https://codeforces.com/problemset/problem/266/B
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,t;
    cin>>n>>t;

    vector<char> Q;
    for (int i=0; i<n; i++) {
        char a;
        cin>>a;
        Q.push_back(a);
    }


    while(t--) {
        int index = n-1;

        while(index >= 1) {
            if (Q[index] == 'G' && Q[index - 1] == 'B') {
                Q[index] = 'B';
                Q[index - 1] = 'G';
                index--;
            }
            index--;
        }
    }

    for (int i=0; i<n; i++) {
        cout<<Q[i];
    }
    cout<<endl;

    return (0);
}
