// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string coded;
    string decoded = "";
    cin>>coded;

    int n = coded.length();

    for (int i=0; i<n; i++) {
        char c = coded[i];

        if (c == '.') {
            decoded += '0';
        } else if (c == '-') {
            char next = coded[i+1];
            if (next == '.') {
                decoded += '1';
            } else if (next == '-') {
                decoded += '2';
            }
            i++;
        }
    }

    for (int i=0; i<decoded.length(); i++) {
        cout<<decoded[i];
    }
    cout<<endl;

    return (0);
}
