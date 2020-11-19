// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://omegaup.com/arena/problem/AERODROM#problems
//
// © Jose Garfias Lopez
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

#define MAX ULLONG_MAX

typedef unsigned long long int ULL;

using namespace std;

int desks_tam, peoples_tam;
vector<int> desks;

ULL eval(ULL t) {
    ULL sum = 0;
    for (int i=0; i<desks_tam;i++) {
        sum += (t/desks[i]);
    }
    return sum;
}

ULL binary_search(int q) {
    // Q: Is the number of people 
    // INI = 0, FIN = 50
    unsigned long long int ini=0, fin=MAX, mid, res=-1;
    while(ini <= fin) {
        mid = (ini + fin) / 2;
        ULL resultEv = eval(mid);
        if(resultEv >= q) {
			res = mid;
			fin = mid-1;
		}
		if(resultEv < q) {
			ini = mid+1;
        }
    }
    return res;
}

int main() {
    cin>>desks_tam>>peoples_tam;
    int t;
    for (int i=0; i<desks_tam; i++) {
        cin>>t;
        desks.push_back(t);
    }
    cout<<binary_search(peoples_tam);
    return (0);
}
