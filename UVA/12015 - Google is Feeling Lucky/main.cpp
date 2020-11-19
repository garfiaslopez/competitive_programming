// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3166
//
// © Jose Garfias Lopez
//

// #include <bits/stdc++.h>

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int cases = 0;
    cin>>cases;
    
    for (int caseNumber = 1; caseNumber <= cases; caseNumber++) {
        int maxRank = INT_MIN;
        vector<pair<string, int> > webPages;

        for(int i=0; i<10; i++) {
            string webUrl;
            cin>>webUrl;
            int rank;
            cin>>rank;
            webPages.push_back(make_pair(webUrl, rank));
            maxRank = max(maxRank, rank);
        }
        
        cout<<"Case #"<<caseNumber<<':'<<endl;
        for (int i=0; i<10; i++) {
            pair<string,int> webPage = webPages[i];
            if (webPage.second == maxRank) {
                cout<<webPage.first<<endl;
            }
        }

    }
    return (0);
}
