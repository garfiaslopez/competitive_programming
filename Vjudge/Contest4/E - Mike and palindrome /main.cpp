// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//

#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    string originalS;
    cin>>originalS;
    int tamS = originalS.length()-1;
    int middle = floor((tamS+1)/2);
    int errors = 0;
    int j;
    for (int i=0; i<middle; i++) {
        j = tamS - i;
        if (originalS[i] != originalS[j]) {
            errors++;
        }
    }
    if (errors == 1) {
        cout<<"YES"<<endl;
    } else if((tamS+1)%2!=0 && errors == 0) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
