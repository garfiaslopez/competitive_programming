// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1282
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

#define ERROR 1e-9
using namespace std;

double p,q,r,s,t,u;

double solve(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * (x*x) + u;
}

double binary_search() {
    double ini = 0, fin = 1, res=-1, mid;
    while (ini<fin) {
        mid = (ini + fin)/2.0;
        double sol = solve(mid);
        //cout<<"mid: "<<mid<<" res: "<<sol<<endl;
        if (sol == 0 || fabs(sol) < ERROR) {
            res = mid;
            break;
        } else if (sol > 0) {
            ini = mid;
        } else if (sol < 0) {
            fin = mid;
        }
    }
    return res;
}

int main() {
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u) != EOF) {
        double res = binary_search();
        if (res != -1) {
            cout<<fixed<<setprecision(4)<<res<<endl;
        } else {
            cout<<"No solution"<<endl;
        }
        // for (double x = 0;x<=1; x+=0.1) {
        //     cout<<"x = "<<x<<" res: "<<solve(x)<<endl;
        // }
        // cout<<endl;
    }
    return (0);
}
