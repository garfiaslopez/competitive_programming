//
//  main.cpp
//  Al reves
//
//  Created by Jose De Jesus Garfias Lopez on 12/7/17.
//  Copyright © 2017 Karmapulse. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int start = 0;
    int end = 0;
    string text = "";
    string result = "";
    
    scanf("%d %d", &start, &end);
    cin.ignore();
    getline(cin, text);
    
    int step = end;
    for (int a = 0; a < text.length(); a++) {
        if (a >= start && a <= end) {
            result = result + text[step];
            step--;
        } else {
            result = result + text[a];
        }
    }
    cout<<result;
    return 0;
}
