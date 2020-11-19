// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp_asc (int i,int j) { 
    return (i<j); 
}
bool comp_desc (int i,int j) { 
    return (i>j); 
}

int main() {
    int n;
    vector<int> A;
    vector<int> B;
    cin>>n;
    for (int i=0; i<n; i++){
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    for (int i=0; i<n; i++){
        int temp;
        cin>>temp;
        B.push_back(temp);
    }
    sort (A.begin(), A.end(), comp_asc); 
    sort (B.begin(), B.end(), comp_desc);

    int res = 0;
    for (int i=0; i<n; i++) {
        res += A[i] * B[i];
    }
    cout<<res<<endl;
    return (0);
}
