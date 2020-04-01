// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <algorithm>    // std::next_permutation, std::sort

using namespace std;

#define ll long long int 
  
const int MAX_CHAR = 26; 
const int MAX_FACT = 26; 
ll fact[MAX_FACT]; 
  
// utility for calculating factorials 
void precomputeFactorials() { 
    fact[0] = 1; 
    for (int i = 1; i < MAX_FACT; i++) 
        fact[i] = fact[i - 1] * i; 
}

string generateString (int n) {
    string caseString = "";
    for (int i=0; i<n-2; i++) {
        caseString += "a";
    }
    caseString += "bb";
    cout<<"test:"<<caseString<<endl;
    return caseString;
}

void nPermuteSlow(string str, long int n) { 
    // Keep iterating until 
    // we reach nth position 
    long int i = 1; 
    do { 
        // check for nth iteration 
        if (i == n) 
            break; 
  
        i++; 
    } while (next_permutation(str.begin(), str.end())); 
    cout << str << endl;
}

int main() {
    precomputeFactorials(); 

    int cases;
    cin>>cases;
    while(cases--) {
        int n,k;
        cin>>n>>k;
        nPermute(generateString(n), k);
    }
    return(0);
}