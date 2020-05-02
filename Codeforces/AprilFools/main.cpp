// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> results;

    for (int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        results.push_back(make_pair(a,b));
    }

    for (int i=0; i<n; i++) {
        if(results[i].first != results[i].second) {
            cout<<"rated"<<endl;
            return(0);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (results[i].first > results[j].first) {
                cout<<"unrated"<<endl;
                return(0);
            }
        }
    }

    cout<<"maybe"<<endl;

    return (0);
}
