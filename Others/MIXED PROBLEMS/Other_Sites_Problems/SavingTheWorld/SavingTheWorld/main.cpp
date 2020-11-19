//
//  main.cpp
//  SavingTheWorld
//
//  Created by Jose De Jesus Garfias Lopez on 4/16/18.
//  Copyright © 2018 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int shield;
string commands;

int calculate_damage() {
    int load = 1;
    int dam = 0;
    for (int i=0; i < commands.length(); i++) {
        if (commands[i] == 'C') {
            load = load*2;
        }
        if (commands[i] == 'S') {
            dam += load;
        }
    }
    return dam;
}

int next_swap() {
    for (int i = (int)commands.length() - 1; i >= 0; i--) {
        if (i > 0 && commands[i] == 'S' && commands[i-1] == 'C') {
            swap(commands[i], commands[i-1]);
            return 1;
        }
    }
    return 0;
}

void process(int cases) {
    cin>>shield;
    cin>>commands;
    
    int count_swaps = 0;
    while (shield < calculate_damage()) {
        if (next_swap()) {
            count_swaps ++;
        } else {
            count_swaps = -1;
            break;
        }
    }
    if (count_swaps == -1) {
        printf("Case #%d: IMPOSSIBLE\n", cases);
    } else {
        printf("Case #%d: %d\n", cases, count_swaps);
    }
}

int main(int argc, const char * argv[]) {
    
    int cases = 0;
    scanf("%d", &cases);
    for (int i = 1; i <= cases ; i++) {
        process(i);
    }
    
    return 0;
}
