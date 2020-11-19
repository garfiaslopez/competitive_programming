// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;


// pair<int,int> binary_search(int gcd, int lcm) {
//     int ini = 1;
//     int fin = 2147483647;
//     int a = 0;
//     int b = 0;
//     while(ini<=fin) {
//         int mid = (ini+fin)/2;
//         double midEval = ((double)gcd * (double)lcm) / (double)mid;
//         //cout<<"mid: " <<mid<<"  eval: "<<midEval<<"  diff: "<<abs(midEval - floor(midEval))<<endl;
//         if (abs(midEval - floor(midEval)) == 0) {
//             ini = mid + 1;
//             a = mid;
//             b = midEval;
//         } else {
//             fin = mid - 1;
//         }
//     }
//     if (a > 0) {
//         return make_pair(a,b);
//     } else {
//         return make_pair(-1,-1);
//     }
// }

int get_lcm(int a, int b) {
    return ((max(a,b))/(__algo_gcd(a,b))) * min(a,b);
}

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int gcd, lcm;
        cin>>gcd>>lcm;

        if (__algo_gcd(gcd,lcm) == gcd && get_lcm(gcd,lcm)) {
            cout<<gcd<<" "<<lcm<<endl;
        } else {
            cout<<"-1"<<endl;
        }



        // bool found = false;
        // int product = gcd * lcm;
        // for (int i=1; i<=lcm; i++) {
        //     if (product%i == 0 && __gcd(i,product/i) == gcd) {
        //         found = true;
        //         cout<<i<<" "<<product/i<<endl;
        //         break;
        //     }
        // }
        // if (!found) {
        //     cout<<"-1"<<endl;
        // }

        // pair<int,int> res = binary_search(gcd,lcm);
        // if (res.first != -1) {
        //     int a = res.second;
        //     int b = res.first;
        //     if (__gcd(a,b) == gcd &&  get_lcm(a,b) == lcm) {
        //         cout<<res.second<<" "<<res.first<<endl;
        //     } else {
        //         cout<<"-1"<<endl;
        //     }
        // } else {
        //     cout<<"-1"<<endl;
        // }
    }
    return (0);
}
