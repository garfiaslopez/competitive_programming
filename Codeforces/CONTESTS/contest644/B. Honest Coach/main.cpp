// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin>>cases;

    while (cases--) {
        int n;
        cin>>n;
        vector<int> stregths;
        for (int i=0; i<n;i++) {
            int s;
            cin>>s;
            stregths.push_back(s);
        }
        sort(stregths.begin(), stregths.end());

        int minDiff = INT_MAX;
        for (int i=1; i<stregths.size(); i++) {
            minDiff = min(minDiff, abs(stregths[i] - stregths[i-1]));
        }
        if (stregths.size() == 1){
            minDiff = stregths[0];
        }
        cout<<minDiff<<endl;
    }
    
    return (0);
}
