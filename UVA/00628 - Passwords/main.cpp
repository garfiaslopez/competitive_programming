// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=569
//
// © Jose Garfias Lopez
//
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<string> dictionary;

void solve(string rule, int rule_char, string password) {
    if (rule_char == rule.size()) {
        cout << password << endl;
        return;
    }

    if (rule[rule_char] == '#') {
        for (int i = 0; i < dictionary.size(); i++) {
            solve(rule, rule_char + 1, password + dictionary[i]);
        }
    } else {
        for (int i = 0; i < 10; i++) {
            solve(rule, rule_char + 1, password + to_string(i));
        }
    }
}


int main(int argc, char const *argv[]){
    int dict_tam;
    string word;

    while(scanf("%d", &dict_tam) != EOF) {
        cout << "--" << endl;

        dictionary.clear();
        for (int i = 0; i < dict_tam; i++) {
            cin >> word;
            dictionary.push_back(word);
        }

        int num_rules;
        cin >> num_rules;

        for (int i = 0; i < num_rules; i++) {
            string rule;
            cin >> rule;
            solve(rule, 0, "");
        }
    }

    return 0;
}