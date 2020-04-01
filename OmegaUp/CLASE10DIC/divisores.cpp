#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    // 10, 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1
    for (int i=n; i>=1; i--) {
        if (n % i == 0) {
            // i es un divisor de n
            cout<<i<<endl;
        }
    }

    return 0;
}