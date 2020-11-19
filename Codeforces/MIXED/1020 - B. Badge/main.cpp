// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://codeforces.com/problemset/problem/1020/B
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int MAX = 0;
    cin>>MAX;
    vector <int> goTo(MAX + 4);
    for(int i=1; i<=MAX; i++) {
        cin>>goTo[i];
    }

    for (int a = 1; a <= MAX; a++) {

        vector <int> visited (MAX + 4);
        for (int i=0; i<MAX+4;i++) {
            visited[i] = 0;
        } 

        int doubleChecked = -1;
        bool searching = true;
        int actual = a;
        while (searching) {
            visited[actual] = visited[actual] + 1;
            if (visited[actual] >= 2) {
                doubleChecked = actual;
                searching = false;
                break;
            }
            actual = goTo[actual];
        }
        cout<<doubleChecked<<" ";
    }

    return (0);
}
