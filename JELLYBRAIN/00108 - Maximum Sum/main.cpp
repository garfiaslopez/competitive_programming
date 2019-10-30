// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_INF -100000;

// int kadanes(vector<int> Array, int N) {
//     int max_until_now = 0;
//     int max_global = 0;
//     for (int i=0; i<N; i++) {
//         max_until_now = max_until_now + Array[i];
//         if (max_until_now < 0) {
//             max_until_now = 0;
//         }
//         max_global = max(max_global, max_until_now);
//     }
//     return max_global;
// }

// int max_sum_dp(int * Array, int N) { // TABULATION
//     int DP[N];
//     int max_global = Array[0];
//     DP[0] = Array[0];
//     cout<< Array[0]<< " ";
//     for (int i=1; i<N; i++) {
//         DP[i] = max( DP[i-1] + Array[i], Array[i] );
//         max_global = max(max_global, DP[i]);
//     }
//     cout<<endl<<"MAX:"<<max_global<<endl;
//     return max_global;
// }

int main() {
    int N;
    cin>>N;
    int Matrix[N][N];

    //int max_total = N_INF;

    // read the matrix: 
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>Matrix[i][j];
        }
    }

    int max_sum = Matrix[0][0];
    // proccess the matrix: 

    for (int k=0; k<N; k++) {

        // Aux vector for SUM
        vector<int> SumArray(N, 0);
        
        for (int i=k; i<N; i++) {

            // KADANES:
            int max_until_now = 0;
            int max_local = N_INF;
            for (int a=0; a<N; a++) {
                SumArray[a] += Matrix[i][a];
                max_until_now = max(max_until_now + SumArray[a], 0);
                max_local = max(max_local, max_until_now);
            }

            max_sum = max(max_sum, max_local);
        }
    }

    cout<<max_sum<<endl;

    return (0);
}
