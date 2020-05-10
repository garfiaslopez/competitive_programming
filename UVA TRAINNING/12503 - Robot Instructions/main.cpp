// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3947
//
// © Jose Garfias Lopez
//

// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int instructions;
        cin>>instructions;
        vector<int> history(instructions + 2);
        int position = 0;
        cin.ignore(1);
        for (int i=1; i<=instructions; i++) {
            string instruction;          
            getline(cin, instruction);
            if (instruction == "LEFT") {
                position -= 1;
                history[i] = -1;
            } else if (instruction == "RIGHT") {
                position += 1;
                history[i] = 1;
            } else {
                string indexString = instruction.substr(8,instruction.length()-1);
                position += history[stoi(indexString)];
                history[i] = history[stoi(indexString)];
            }
        }
        cout<<position<<endl;
    }
    return (0);
}
