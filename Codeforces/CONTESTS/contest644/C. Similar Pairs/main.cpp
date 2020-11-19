// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

bool isSimilar (int a, int b) {

    return false;
}

int main() {
    int cases;
    cin>>cases;
    while (cases--) {
        vector<int> numbers;
        int n;
        cin>>n;
        for (int i=0; i<n; i++) {
            int num;
            cin>>num;
            numbers.push_back(num);
        }

        bool found = true;
        for (int i=0; i<numbers.size(); i++) {
            bool foundPair = false;
            for (int j=i; j<numbers.size(); j++) {
                if (isSimilar) {
                    foundPair = true;
                    break;
                }
            }
        }

        if (found) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    return (0);
}
