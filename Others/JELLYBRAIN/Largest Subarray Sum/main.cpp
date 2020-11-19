// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

// BY BRUTE FORCE SOLUTION => O(N^3);
#include <cstdio>
#include <iostream>
#include <vector>

#define N_INF -100000000

using namespace std;


vector<int> Array;
int N;

int max_sum_cubic() {
    int max_global = N_INF;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int sum = 0;
            for (int k = i; k<=j; k++) {
                sum += Array[k];
            }
            max_global = max(max_global, sum);
        }
    }
    return max_global;
}

int max_sum_cuadratic() {
    int max_global = N_INF;
    for (int i=0; i<N; i++) {
        int sum = 0;
        for (int j=i+1; j<N; j++) {
            sum += Array[j];
            max_global = max(max_global, sum);
        }
    }
    return max_global;
}

int max_sum_dp() { // TABULATION
    int DP[N];
    int max_global = Array[0];
    DP[0] = Array[0];
    for (int i=1; i<N; i++) {
        DP[i] = max( DP[i-1] + Array[i], Array[i] );
        max_global = max(max_global, DP[i]);
    }
    return max_global;
}

int max_sum_kadanes() {
    int max_until_now = 0;
    int max_global = N_INF;
    for (int i=0; i<N; i++) {
        max_until_now = max_until_now + Array[i];
        if (max_until_now < 0) {
            max_until_now = 0;
        }
        max_global = max(max_global, max_until_now);
    }
    return max_global;
}

int main() {
    int number;
    while(cin>>number) {
        Array.push_back(number);
    }
    N = Array.size();

    int res = max_sum_kadanes();

    cout<<res<<endl;

    return (0);
}
