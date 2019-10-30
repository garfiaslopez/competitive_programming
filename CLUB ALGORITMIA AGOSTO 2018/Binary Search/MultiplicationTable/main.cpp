// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: http://codeforces.com/problemset/problem/448/D
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long int lli;

lli N,M,K;

lli eval (lli x) {
    lli sum = 0;
    for (int i=1; i<=N;i++) {
        sum = sum + min(x/i,M);
    }
    return sum;
}

lli binary_search(lli ini, lli fin, lli q) {
    lli mid, res=-1;
    while (ini<=fin) {
        mid = (ini+fin)/2;
        lli resEval = eval(mid);
        //cout<<"mid: "<<mid<<" res:"<<resEval<<endl;
        if (resEval >= q) {
            res = mid;
            fin = mid - 1;
        } else {
            ini = mid + 1;
        }
    }
    return res;
}

int main() {
    cin>>N>>M>>K;
    cout<<binary_search(0,N*M,K)<<endl;
    return (0);
}
