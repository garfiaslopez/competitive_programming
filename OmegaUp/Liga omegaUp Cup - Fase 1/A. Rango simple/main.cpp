// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tam;
    cin>>tam;
    vector<int> array;

    for(int i=0; i<tam; i++) {
        int number;
        cin>>number;
        array.push_back(number);
    }

    int a,b;
    cin>>a>>b;

    int count = 0;
    for (int i=0; i<tam;i++) {
        if (a <= array[i] && b >= array[i]) {
            count++;
        }
    }

    cout<<count<<endl;
    return (0);
}
