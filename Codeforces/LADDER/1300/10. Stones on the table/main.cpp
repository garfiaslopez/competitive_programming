// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    string stones;
    cin>>stones;

    int remove = 0;
    for (int i=0; i<stones.length() - 1; i++) {
        char actual = stones[i];
        char next = stones[i+1];

        if (actual == next) {
            remove++;
        }
    }

    cout<<remove<<endl;

    return (0);
}
