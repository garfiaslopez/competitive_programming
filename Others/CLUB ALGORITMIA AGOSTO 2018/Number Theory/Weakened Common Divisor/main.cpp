// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int Long;

bool allEquals = true;
int total_pairs;
vector<pair<Long,Long> > pairs;

Long gcd( Long a, Long b ){
	if( b == 0ll ) return a;
	return gcd(b, a%b);
}

Long get_prime_of_n(Long n) {
    cout<<"n: "<<n<<endl;
    if (n != 1) {

        // check if number is on pairs first:
        for (int i=0; i<pairs.size(); i++) {
            if (n != pairs[i].first && n%pairs[i].first == 0) {
                return n/pairs[i].first;
            }
            if (n != pairs[i].second && n%pairs[i].second == 0) {
                return n/pairs[i].second;
            }
        }

        // if not, search the number:
        Long raiz = sqrtl(n);
        for (Long i=2; i<=raiz; i++) {
            if (n%i==0) {
                return i;
            }
        }
        if (n>1) {
            return n;
        }
    }
    return -1;
}

Long calculate_gcd() {
    if (total_pairs >= 2) {
        Long pre_wcd = gcd(pairs[0].first * pairs[0].second, pairs[1].first * pairs[1].second);
        for (int i=2; i<pairs.size(); i++) {
            pre_wcd = gcd(pre_wcd, pairs[i].first * pairs[i].second);
        }
        return get_prime_of_n(pre_wcd);
    }
    return pairs[0].first;
}

int main() {
    cin>>total_pairs;
    for (int i=0; i<total_pairs; i++) {
        Long a,b;
        cin>>a>>b;
        pairs.push_back(make_pair(a,b));
        if (i >= 1 && pairs[i-1] != pairs[i]) {
            allEquals = false;
        }
    }
    if (allEquals) {
        cout<<pairs[0].first<<endl;
    } else {
        cout<<calculate_gcd()<<endl;
    }
    
    return (0);
}
