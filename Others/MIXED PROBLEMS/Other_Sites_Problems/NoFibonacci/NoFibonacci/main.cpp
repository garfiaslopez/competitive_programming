//
//  main.cpp
//  NoFibonacci
//
//  Created by Jose De Jesus Garfias Lopez on 12/7/17.
//  Copyright © 2017 Karmapulse. All rights reserved.
//

#include <iostream>

using namespace std;

void doFibo(int first, int second, int maxFibo) {
    int newFibo = first + second;
    if ((second - first) > 1) {
        for (int i = first + 1; i < second; i ++) {
            cout<< i <<" ";
        }
    }
    if (newFibo <= maxFibo) {
        doFibo(second, newFibo, maxFibo);
    } else {
        if ((maxFibo - second) > 1) {
            for (int i = second + 1; i < maxFibo; i ++) {
                cout<< i <<" ";
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int maxNumber;
    cin>>maxNumber;
    doFibo(1, 2, maxNumber);
    return 0;
}
