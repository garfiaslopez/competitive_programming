//
//  main.cpp
//  scrabble
//
//  Created by Jose De Jesus Garfias Lopez on 12/7/17.
//  Copyright © 2017 Karmapulse. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

map<char, int> Letters;

int main(int argc, const char * argv[]) {
    
    int caseLetters = 0;
    string word = "";
    
    scanf("%d", &caseLetters);
    
    while (caseLetters--) {
        char letter;
        int timesLetter;
        cin.ignore();
        scanf("%c %d", &letter,&timesLetter);
        Letters[letter] = timesLetter;
    }
    cin>>word;
    bool completed = true;
    for (int i = 0; i<word.length(); i++) {
        if (Letters[word[i]] > 0) {
            Letters[word[i]] = Letters[word[i]] - 1;
        } else {
            completed = false;
        }
    }
    if (completed) {
        cout<<1;
    } else {
        cout<<0;
    }
    
    return 0;
}
