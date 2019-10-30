//
//  main.cpp
//  MatrizSimetrica
//
//  Created by Jose De Jesus Garfias Lopez on 12/7/17.
//  Copyright © 2017 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>


int main(int argc, const char * argv[]) {

    int TAM = 0;
    scanf("%d",&TAM);
    int MATRIX[TAM][TAM];
    
    for (int i = 0; i<TAM; i++) {
        for (int j = 0; j<TAM; j++) {
            scanf("%d",&MATRIX[i][j]);
        }
    }
    
    bool simetric = true;
    
    for (int i=0; i<TAM; i++) {

    }
    
    for (int i = 0; i<TAM; i++) {
        for (int j = 0; j<TAM; j++) {
            if (MATRIX[i][j] != MATRIX[j][i]) {
                simetric = false;
                break;
            }
        }
    }
    
    if (simetric == true) {
        printf("SI");
    } else {
        printf("NO");
    }
    
    return 0;
}
