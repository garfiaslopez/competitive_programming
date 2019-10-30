// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long double Double;

Double funcEval(Double x) {
    return (2.0*(x*x)) - (12.0*x) + (7.0);
}

Double ternary_search(Double ini, Double fin) {
    Double res;
    for (int i=0; i<=200; i++) {
        //cout<<"ini: "<<ini<<"  fin: "<<fin<<endl;

        //int mid1 = ini + ((fin - ini)/3.0);
        //int mid2 = fin - ((fin - ini)/3.0);
        Double mid1 = (ini*2+fin)/3.0;
        Double mid2 = (ini+2*fin)/3.0;

        //int mid2 = ((3*ini) + fin - ini)/3.0;
        //int mid2 = (2*ini + fin)/3;
        //int mid1 = (ini + 2*fin)/3;

        //cout<<"m1: "<<mid1<<"  m2: "<<mid2<<endl;
        
        Double e1 = funcEval(mid1);
        Double e2 = funcEval(mid2);

        //cout<<"e1: "<<e1<<"  e2: "<<e2<<endl;
        if (e1 <= e2) { // searching for minimum in func.
            fin = mid2;
            res = e1;
        } else if (e2 < e1) {
            ini = mid1;
            res = e2;
        }
    }
    return res;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int ini,fin;
        cin>>ini>>fin;
        cout<<fixed<<setprecision(0)<<ternary_search(ini,fin)<<endl;
    }
    return (0);
}
