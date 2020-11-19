// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int INF = 2147483647;

int divisors_of_n(int n) {
    int sum = 0;
    for (int i=1; i<=sqrtl(n); i++) {
        if (n%i == 0) {
            sum += 2;
        }
        if (i*i == n) {
            sum -= 1;
        }
    }
    return sum;
}

int main() {
    int N;
    cin>>N;
    if (N>1) {
        int DivOfN = divisors_of_n(N);
        int positiveDiv = -1;
        for (int i=N+1; i <= INF; i++) {
            int temp = divisors_of_n(i);
            if (DivOfN == temp) {
                positiveDiv = i;
                break;
            }
        }

        int negativeDiv = -1;
        for (int i=N-1; i>=1; i--) {
            int temp = divisors_of_n(i);
            if (DivOfN == temp) {
                negativeDiv = i;
                break;
            }
        }

        if (positiveDiv != -1 && negativeDiv != -1) { // encontre por ambos lados
            int distanceA = positiveDiv - N;
            int distanceB = N - negativeDiv;
            if (distanceA <= distanceB) { // si ambos estan a la misma distancia imprime el mas grande
                cout<<positiveDiv;
            } else {
                cout<<negativeDiv<<endl;
            }
        } else {
            cout<<max(positiveDiv, negativeDiv); // print the number different -1
        }
    }

    return (0);
}