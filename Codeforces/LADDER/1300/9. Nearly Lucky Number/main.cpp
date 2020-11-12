// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int isLuckyNumber(int x) {
    int digits = 0;
    int actualDigit = 0;
    int luckies = 0;

    while (x > 0) {
        actualDigit = x%10;
        
        if (actualDigit == 4 || actualDigit == 7) {
            luckies++;
        }
        digits++;
        x /= 10;
    }

    return luckies == digits;
}

int main() {
    string number;
    cin>>number;

    int luckies = 0;
    for (int i=0; i<number.length(); i++) {
        if (number[i] == '4' || number[i] == '7') {
            luckies++;
        }
    }

    if (luckies > 0 && isLuckyNumber(luckies)) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return (0);
}
