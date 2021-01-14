// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:       https://cses.fi/problemset/task/1640/
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,x;
    cin>>n>>x;

    map<int,int> seen;
    bool found = false;

    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        if (i>0) {
            if (seen.find(temp) != seen.end()) {
                cout<<i+1<<" "<<seen[temp] + 1<<"\n";
                found = true;
                break;
            }
        }
        seen[(x-temp)] = i;
    }

    if (!found) {
        cout<<"IMPOSSIBLE\n";
    }
    return (0);
}
