//
//  main.cpp
//  SodaSurpler
//
//  Created by Jose De Jesus Garfias Lopez on 3/27/18.
//  Copyright © 2018 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int process(int sodas, int having, int cost) {
    
    if (cost == 1) {
        return 0;
    }
    
    int totalSodas = sodas + having;
    int newSodas = totalSodas/cost;
    int remind = totalSodas - (newSodas * cost);
    int canAfford = newSodas;
    
    while (newSodas != 0) {
        totalSodas = remind + newSodas;
        newSodas = totalSodas/cost;
        remind = totalSodas - (newSodas * cost);
        canAfford += newSodas;
    }
    
    return canAfford;
}

int main(int argc, const char * argv[]) {

    int cases = 0;
    scanf("%d", &cases);
    
    int e,f,c = 0;
    for (int i=0; i<cases; i++) {
        scanf("%d %d %d", &e,&f,&c);
        printf("%d\n",process(e, f, c));
    }
    
    return 0;
}
