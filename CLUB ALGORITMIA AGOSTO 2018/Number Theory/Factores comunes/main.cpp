// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//
// 
//
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned long long int Long;

Long gcd( Long a, Long b ){
	if( b == 0ll ) return a;
	return gcd(b, a%b);
}

Long divisorsOfN(Long n) {
    Long sum = 0;
    for (Long i=1; i<=sqrtl(n); i++) {
        if (n%i==0) { 
            if (n/i == i) {
                sum += 1; 
            } else {
                sum += 2; 
            }
        } 
    }
    return sum;
}

int main() {
    Long a,b;
    cin>>a>>b;
    cout<<divisorsOfN(gcd(a,b))<<endl;
    return (0);
}