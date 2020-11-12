// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

bool hasDistinctDigits(int x) {
    unordered_map<int, int> digitsCount;

    while(x>0) {
        int dig = x%10;
        
        if (digitsCount.find(dig) != digitsCount.end()) {
            digitsCount[dig] += 1;
        } else {
            digitsCount[dig] = 1;
        }

        x /= 10;
    }

    bool allOnes = true;
    for (auto it : digitsCount) {
        //cout<<it.first<<", "<<it.second<<endl;
        if (it.second >= 2) {
            allOnes = false;
            break;
        }
    }

    return allOnes;
}

int main() {
    int year;
    cin>>year;

    year++;
    while(!hasDistinctDigits(year)) {
        year++;
    }
    cout<<year<<endl;

    return (0);
}
