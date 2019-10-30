//
//  main.cpp
//  Bijele
//
//  Created by Jose De Jesus Garfias Lopez on 3/26/18.
//  Copyright © 2018 Jose De Jesus Garfias Lopez. All rights reserved.
//
//  http://coj.uci.cu/24h/problem.xhtml?pid=1180
//
//


#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int cases = 0;
    int kings = 0;
    int queens = 0;
    int rooks = 0;
    int bishops = 0;
    int knights = 0;
    int pawns = 0;
    scanf("%d",&cases);
    for (int i = 0; i<cases; i++) {
        scanf("%d %d %d %d %d %d",&kings, &queens, &rooks, &bishops, &knights, &pawns);
        printf("%d %d %d %d %d %d\n",1 - kings, 1 - queens, 2 - rooks, 2 - bishops, 2 - knights, 8 - pawns);
    }
}
