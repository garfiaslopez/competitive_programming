// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1326
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Numbers;

int binary_search(int ini, int fin, int q) {
    int mid, res=-1;
    while(ini <= fin) {
        mid = (ini + fin) / 2;
        if(Numbers[mid] == q ) {
			res = mid;
			fin = mid-1;
		}
		if(Numbers[mid] < q ) {
			ini = mid+1;
        }
		if(Numbers[mid] > q ) {
			fin = mid-1;
        }
    }
    return res;
}

int main() {
    int N, Q;
    int cases = 1;
    while (scanf("%d%d", &N, &Q), N>0 && Q>0) {
        Numbers = vector<int>(N);
        int temp;
        for (int i=0; i<N; i++) {
            cin>>Numbers[i];
        }
        sort(Numbers.begin(), Numbers.end());
        cout<<"CASE# "<<cases<<":"<<endl;
        for (int i=0; i<Q; i++) {
            cin>>temp;
            int result = binary_search(0, N-1, temp);
            if (result != -1) {
                cout<<temp<<" found at "<<result + 1<<endl;
            } else {
                cout<<temp<<" not found"<<endl;
            }
        }
        cases++;
    } 
    cin>>N>>Q;
    return (0);
}
