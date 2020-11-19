// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int calcDuration (int minutes, int slice, int price) {
    double timesIn = minutes/slice;

    if ((timesIn-(int)timesIn) == 0) {
        timesIn++;
    } else {
        timesIn = ceil(timesIn);
    }

    return timesIn * price;
}

int main() {
    // Mile   10 cents every < 30 seconds
    // Jiuice 15 cents every < 60 seconds

    int cases;
    cin>>cases;
    for (int caseN = 1; caseN <= cases; caseN++) {
        int calls;
        cin>>calls;

        int totalMile = 0;
        int totalJuice = 0;
        while(calls--) {
            int callDuration;
            cin>>callDuration;
            totalMile += calcDuration(callDuration, 30, 10);
            totalJuice += calcDuration(callDuration, 60, 15);
        }
        if (totalJuice == totalMile) {
            cout<<"Case "<<caseN<<": Mile Juice "<< totalMile<<endl;
        } else if (totalMile < totalJuice) {
            cout<<"Case "<<caseN<<": Mile "<< totalMile<<endl;
        } else {
            cout<<"Case "<<caseN<<": Juice "<< totalJuice<<endl;
        }
    }    
    return (0);
}
