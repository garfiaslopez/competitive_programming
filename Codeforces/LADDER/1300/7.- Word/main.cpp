// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int freqLower = 0;
    int freqUpper = 0;

    string str = "";
    cin>>str;

    for (int i=0; i<str.length(); i++) {
        if (isupper(str[i])) {
            freqUpper++;
        } else {
            freqLower++;
        }
    }

    for (int i=0; i<str.length(); i++) {
        if (freqUpper > freqLower) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }


    cout<<str<<endl;

    return (0);
}
