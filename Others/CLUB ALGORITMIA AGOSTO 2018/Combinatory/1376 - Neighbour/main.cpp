// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

#define INF 9999999

using namespace std;

int main() {
    string N;
    cin>>N;
    int actualN = stoi(N);
    int minN = INF;
    while(next_permutation(N.begin(), N.end())) {
        int actual = stoi(N);
        if (actual > actualN && actual < minN) {
            minN = actual;
        }
    }
    if (minN != INF) {
        cout<<minN<<endl;
    } else {
        cout<<0<<endl;
    }
    return (0);
}
