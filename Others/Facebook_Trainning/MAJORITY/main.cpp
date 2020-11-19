// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int majorityElement(const vector<int> &A) {
    map<int,int> frequencies;
    map<int,int>::iterator it;
    for (int i=0; i<A.size(); i++) {
        frequencies[A[i]] += 1;
    }
    int maxKey = -1;
    int actualMax = 0;
    for (it = frequencies.begin(); it != frequencies.end(); it++) {
        //cout<<"key: "<<it->first<<" value: "<<it->second<<endl;
        if (it->second > actualMax) {
            actualMax = it->second;
            maxKey = it->first;
        }
    }
    return maxKey;
}

int main() {
    int tam;
    cin>>tam;
    vector<int> A;
    for (int i=0;i<tam;i++) {
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    cout<<majorityElement(A);
    return (0);
}
