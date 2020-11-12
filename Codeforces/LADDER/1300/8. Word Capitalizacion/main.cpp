// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string str;
    cin>>str;

    str[0] = toupper(str[0]);

    cout<<str<<endl;
    return (0);
}
