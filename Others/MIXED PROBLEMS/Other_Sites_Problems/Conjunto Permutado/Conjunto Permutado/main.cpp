//
//  main.cpp
//  Conjunto Permutado
//
//  Created by Jose De Jesus Garfias Lopez on 12/7/17.
//  Copyright © 2017 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

map<int, int> Numbers;
map<int, int> SecondNumbers;

int main(int argc, const char * argv[]) {
    int TAM = 0;
    scanf("%d", &TAM);
    for(int i = 0; i<TAM; i++) {
        int number;
        scanf("%d", &number);
        if (Numbers[number]) {
            Numbers[number] = Numbers[number] + 1;
        } else {
            Numbers[number] = 1;
        }
    }
    for(int i = 0; i<TAM; i++) {
        int number;
        scanf("%d", &number);
        if (SecondNumbers[number]) {
            SecondNumbers[number] = SecondNumbers[number] + 1;
        } else {
            SecondNumbers[number] = 1;
        }
    }
    if (Numbers == SecondNumbers) {
        printf("SI");
    } else {
        printf("NO");
    }
    return 0;
}

