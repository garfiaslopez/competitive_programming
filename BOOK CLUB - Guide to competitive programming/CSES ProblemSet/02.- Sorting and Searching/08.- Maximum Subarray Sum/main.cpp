// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:       https://cses.fi/problemset/task/1643
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

typedef long long i64;

using namespace std;

int main() {
    int n;
    cin>>n;
    
	vector<int> numbers;
	vector<i64> dp(n);
	
	for (int i=0; i<n; i++) {
		int x;
		cin>>x;
		numbers.push_back(x);
	}
	
	i64 maxOfAll = LLONG_MIN;
	for (int i=0; i<n; i++) {
		if (i == 0) {
			dp[i] = (i64)numbers[i];
		} else {
			dp[i] = max((i64)dp[i-1] + (i64)numbers[i], (i64)numbers[i]);
		}
		maxOfAll = max(maxOfAll, dp[i]);
	}
	
	cout<<maxOfAll<<"\n";
	
    return (0);
}
