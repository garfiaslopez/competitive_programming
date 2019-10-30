// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

#include <vector>
#include <cmath>
#include <map>

using namespace std;

//Divisors of N
vector<int> divisors_of_n(int n) {
    vector<int> divisors;
    int cont = 0;
    int raiz = sqrt(n);
    for (int i=1; i<=raiz; i++) {
        if (n%i == 0) {
            divisors.push_back(i);
            if (n/i != i) {
                divisors.push_back(n/i);
            }
        }
    }
    return divisors;
}


int main() {
    int N;
    cin>>N;

    vector<int> tetrafactors;
    for (int i=2;i<5500000; i++) {
        if (divisors_of_n(i).size() == 4) {
            tetrafactors.push_back(i);
        }
    }
    cout<<tetrafactors[N-1]<<endl;
    cout<<"size: "<<tetrafactors.size()<<endl;

    return (0);
}
