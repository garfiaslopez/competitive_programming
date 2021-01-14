// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:       https://cses.fi/problemset/task/1141
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> numbers;

    cin>>n;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        numbers.push_back(temp);
    }

    int uniques = 0;
    int maxUniques = INT_MIN;
    set<int> seen;

    for (int i=0; i<n; i++) {
        int trackId = numbers[i];
        //cout<<"trackId: "<<trackId<<endl;

        if(seen.find(trackId) == seen.end()) {
            //cout<<"increment"<<endl;
            uniques++;
            seen.insert(trackId);
        } else {
            //cout<<"clear"<<endl;
            seen.clear();
            seen.insert(trackId);
            uniques = 1;
        }
        //cout<<trackId<<" - "<<uniques<<endl;
        maxUniques = max(maxUniques, uniques);
    }

    cout<<maxUniques<<"\n";

    return (0);
}
