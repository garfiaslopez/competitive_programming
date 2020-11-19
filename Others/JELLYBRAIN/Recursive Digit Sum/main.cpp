// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long int lli;

int super_digit(string number) {
    int total_digits = 0;
    for (int i=0;i<number.length();i++) {
        total_digits += (number[i] - '0');
    }
    return total_digits%9;
}

int main() {
    string number;
    int times;
    cin>>number>>times;
    int base_digit = super_digit(number);
    int res = (base_digit * (times % 9))%9;
    if (res == 0) {
        cout<<9<<endl;
    } else {
        cout<<res<<endl;
    }
    
    return (0);
}
