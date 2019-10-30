//
//  main.cpp
//  Mediana
//
//  Created by Jose De Jesus Garfias Lopez on 12/7/17.
//  Copyright © 2017 Karmapulse. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int TAM;
    scanf("%d",&TAM);
    int numbers[TAM];
    for (int i = 0; i<TAM; i++) {
        scanf("%d",&numbers[i]);
    }
    
    sort(numbers, numbers + TAM);
    
//    for (int i = 0; i<TAM; i++) {
//        printf("%d ",numbers[i]);
//    }
    
    if ( TAM % 2 == 0) {
        int half = (TAM/2);
        float medium = (numbers[half - 1] + numbers[half]) / 2.0;
        printf("%.1f", medium);
    } else {
        int half = TAM/2;
        float medium = numbers[half];
        printf("%.1f", medium);
    }
    return 0;
}
