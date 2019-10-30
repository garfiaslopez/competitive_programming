// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string word) {
    string rev = word;
    reverse(rev.begin(), rev.end());
    return rev == word;
}

int main() {
    string word;
    while (cin>>word) {
        if (is_palindrome(word)) {
            cout<<word<<endl;
        } else {
            int last_pal = -1;
            for (int i=word.length() - 2; i>=0; i--) {
                if (is_palindrome(word.substr(i))) {
                    last_pal = i;
                }
            }
            if (last_pal != -1) {   
                string copy = word.substr(0, last_pal);
                reverse(copy.begin(), copy.end());
                cout << word << copy <<endl;
            } else {
                string copy = word.substr(0, word.length() - 1);
                reverse(copy.begin(), copy.end());
                cout << word << copy <<endl;
            }
        }
    }
    return (0);
}
