// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string> 

using namespace std;

int main() {
    int N;
    cin>>N;
    if (N%10 == 0) {
        cout<<10<<endl;
    } else {
        string number = to_string(N);
        int sum = 0;
        for (int i=0; i<number.length(); i++) {
            int n = number[i] - 48;
            sum += n;
        }
        cout<<sum<<endl;
    }
    return (0);
}
