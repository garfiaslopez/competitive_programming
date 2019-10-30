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
    int N, D;
    cin>>N>>D;
    vector<int> numbers(100000);
    vector<int> numbers_copy(100000);

    for (int i=0;i<N;i++) {
        cin>>numbers[i];
    }
    int difference_rotation = 0;
    for (int i=0; i<D; i++) {
        int rotation;
        cin>>rotation;
        difference_rotation += rotation;
    }
    int rotations = difference_rotation;
    if (difference_rotation < 0) {
        rotations = N - (-1 * difference_rotation);
    }
    //cout<<rotations<<endl;
    for (int i=0; i<N; i++) {
        numbers_copy[(i+rotations) % N] = numbers[i];
    }
    for (int i=0; i<N; i++) {
        cout<<numbers_copy[i]<<" ";
    }
    return (0);
}
