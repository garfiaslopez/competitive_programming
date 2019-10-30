// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: http://codeforces.com/problemset/problem/192/A
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

typedef int Int;

map<int,bool> funkys;
map<int, bool>::iterator it;

Int funky(Int k) {
    return ((k*(k+1))/2);
}

int main() {
    Int N;
    cin >> N;
    Int lastFunky = 0;
    Int totalFunkys = 0;
    for (int i=1; lastFunky <= N; i++) {
        lastFunky = funky(i);
        if (lastFunky <= N) {
            funkys[lastFunky] = true;
            totalFunkys++;
        }
    }
    bool founded = false;

    // for (it = funkys.begin(); it != funkys.end(); it++) {
    //     cout << it->first << ' ' << it->second << '\n';
    // }

    for (it = funkys.begin(); it != funkys.end(); it++) {
        Int search = N - Int(it->first);
        //cout<<"i: "<<it->first<<" _ search "<<search<<endl;
        map<int, bool>::iterator itera = funkys.find(search);
        if (itera != funkys.end()) {
            founded = true;
            break;
        }
    }

    if (founded) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return (0);
}
