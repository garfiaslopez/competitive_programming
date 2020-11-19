// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long int Long;

bool is_prime(Long n) {
    if (n <= 1)  return false; 
    if (n <= 3)  return true;
    Long raiz = sqrtl(n);
    if (n%2 == 0 || n%3 == 0) return false; 
    for (Long i=5; i*i<=n; i=i+6) {
        if (n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int cases;
    cin>>cases;
    Long n;
    while(cases--) {
        cin>>n;
        while(true) {
            if (is_prime(n)) {
                cout<<n<<endl;
                break;
            }
            n++;
        }
    }
    return (0);
}
