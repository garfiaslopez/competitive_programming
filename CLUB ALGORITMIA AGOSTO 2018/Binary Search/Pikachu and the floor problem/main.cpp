// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

typedef unsigned long long int ull;
typedef long double Double;

using namespace std;

int cases;
int N;
ull P;

ull eval(Double x) {
    ull sum = 0;
    for (int i=1; i<=N; i++) {
        sum += (int)i*x;
    }
    return sum;
}

ull ternary_search() {
    // searching P:
    Double ini = 0.00;
    Double fin = (Double)P;
    Double res = -1;
    for (int i=0;i<100;i++) {
        //cout<<"ini: "<<ini<<" fin:"<<fin<<endl;
        Double m1 = ini + (fin-ini)/3.0;
        Double m2 = fin - (fin-ini)/3.0;
        //cout<<"m1: "<<m1<<" m2:"<<m2<<endl;
        ull e1 = eval(m1);
        ull e2 = eval(m2);
        //cout<<"e1: "<<e1<<" e2:"<<e2<<endl;
        if (e1 == P) {
            res = m1;
            break;
        }
        if (e2 == P) {
            res = m2;
            break;
        }
        if (e2 > P) {
            fin = m2;
        } else if (P>e1 && P<e2) {
            ini = m1;
            fin = m2;
        } else {
            ini = m1;
        }
    }
    return res;
}

int main() {
    cin>>cases;

    while(cases--) {
        cin>>N>>P;
        cout<<ternary_search()<<endl;
    }
    return (0);
}
