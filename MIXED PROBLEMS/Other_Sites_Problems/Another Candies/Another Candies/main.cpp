//
//  main.cpp
//  Another Candies
//
//  Created by Jose De Jesus Garfias Lopez on 3/26/18.
//  Copyright © 2018 Jose De Jesus Garfias Lopez. All rights reserved.
// http://coj.uci.cu/24h/problem.xhtml?pid=1078
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int cases = 0;
    scanf("%d",&cases);
    for (int i = 0; i<cases; i++) {
        int kids = 0;
        int totalCandies = 0;
        scanf("%d",&kids);
        for (int j=0; j<kids; j++) {
            int candy = 0;
            scanf("%d",&candy);
            totalCandies = totalCandies + candy;
        }
        if (totalCandies%kids == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
