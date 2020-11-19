// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases;
    cin>>cases;
    cout<<"Lumberjacks:"<<endl;
    while (cases--) {
        int numbers[10] = { 0 };
        for (int i=0; i<10; i++) {
            cin>>numbers[i];
        }
        // process
        int increasings = 0;
        int decreasings = 0;
        for (int i=0; i<9; i++) {
            if (numbers[i] < numbers[i+1]) {
                increasings++;
            } else if (numbers[i] > numbers[i+1]) {
                decreasings++;
            }
        }
        if (increasings > 0 && decreasings == 0) {
            cout<<"Ordered"<<endl;
        } else if (decreasings > 0 && increasings == 0) {
            cout<<"Ordered"<<endl;
        } else {
            cout<<"Unordered"<<endl;
        }
    }
    return (0);
}
