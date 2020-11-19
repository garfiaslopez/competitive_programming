//
//  main.cpp
//  cincoyseis
//
//  Created by Jose De Jesus Garfias Lopez on 12/7/17.
//  Copyright © 2017 Karmapulse. All rights reserved.
//

#include <iostream>

using namespace std;

int normalizersix(int number) {
    string str = to_string(number);
    for (int i = 0; i<str.length(); i++) {
        if (str[i] == '5') {
            str[i] = '6';
        }
    }
    return stoi(str);
}

int normalizerfive(int number) {
    string str = to_string(number);
    for (int i = 0; i<str.length(); i++) {
        if (str[i] == '6') {
            str[i] = '5';
        }
    }
    return stoi(str);
}

int main(int argc, const char * argv[]) {
    int first = 0;
    int second = 0;
    scanf("%d %d", &first, &second);
    int min = normalizerfive(first) + normalizerfive(second);
    int max = normalizersix(first) + normalizersix(second);
    printf("%d %d", min, max);
    return 0;
}

