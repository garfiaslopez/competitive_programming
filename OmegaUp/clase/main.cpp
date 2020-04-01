/// g++ main.cpp -o main && ./main

#include <iostream>

using namespace std;
  
void printDivisors(int n) { 
    for (int i=n; i > 0; i--) {
        if (n%i==0) {
            cout<<i<<endl;
        }
    }
} 
  
int main() { 
    int n;
    cin>>n;

    printDivisors(n); 
    return 0; 
}