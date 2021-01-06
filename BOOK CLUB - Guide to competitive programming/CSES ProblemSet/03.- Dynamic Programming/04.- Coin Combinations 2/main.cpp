// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:       https://cses.fi/problemset/task/1636
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

i64 mod = (1000000000LL + 7LL);

i64 search_recursive(vector<int> &possibilities, int target, int i, vector<vector<i64>> &dp) {
	// BASE CASES
	if (target < 0 || i >= possibilities.size() || i < 0) {
		return 0;
	}
	if (target == 0) {
		return 1;
	}
	if (dp[i][target] != -1) {
		return dp[i][target];
	}
	
	// INCLUDE OR EXCLUDE (0/1 knapsack)
	int newTarget = target - possibilities[i];
	i64 ways = (search_recursive(possibilities, newTarget, i, dp) % mod) + (search_recursive(possibilities, target, i + 1, dp) % mod);

	
	return dp[i][target] = ways % mod;
}

i64 search_iterative(vector<int> &possibilities, int target, vector<vector<i64>> &dp) {
	
    int n = possibilities.size();
    
    for (int i=0; i<=target; i++) {
        dp[0][i] = 0;
    }
    for (int j=0; j<=n; j++) {
        dp[j][0] = 1;
    }
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=target; j++) {
            int k = possibilities[i-1];
            
            if (j<k) {
                dp[i][j] = (dp[i-1][j]) % mod;
            } else {
                dp[i][j] = (dp[i-1][j] % mod) + (dp[i][j-k] % mod);
            }        
            
        }
    }
    
    return dp[n][target] % mod;
}

int main() {
	int n, x;
	cin>>n>>x;
	vector<int> possibilities;
	
	for (int i=0; i<n; i++) {
		int tmp;
		cin>>tmp;
		possibilities.push_back(tmp);
	}
	
	vector<vector<i64>> dp = vector<vector<i64>>(n + 10, vector<i64>(x + 10, -1));
	i64 answer = search_iterative(possibilities, x, dp);
	
	cout<<answer<<"\n";
}