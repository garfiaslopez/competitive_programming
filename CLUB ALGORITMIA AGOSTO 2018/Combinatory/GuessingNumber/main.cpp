// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin>>n;
    cout<<log2(n) + 1<<endl;
    return (0);
}
