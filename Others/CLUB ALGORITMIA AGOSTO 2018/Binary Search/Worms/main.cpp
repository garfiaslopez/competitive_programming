// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: http://codeforces.com/problemset/problem/474/B
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Querys;
vector<pair<int,int> > Worms;
int totalWorms, totalQuerys;

int Binary_Search(int query) {
    int ini=0, fin=totalWorms-1, res=-1, mid;
    while(ini<=fin) {
        mid = (ini+fin)/2;
        pair<int,int> resEval = Worms[mid];
        //cout<<"mid "<<mid<<" -> "<<Worms[mid].first<<" - "<<Worms[mid].second<< "q: "<<query<<endl;
        if (query >= resEval.first && query <= resEval.second) {
            res = mid;
            break;
        } else if (query < resEval.first) {
            fin = mid - 1;
        } else if (query > resEval.second) {
            ini = mid + 1;
        }
    }
    return res;
}

int main() {
    cin>>totalWorms;
    int lastIndex = 0;
    for (int i=0; i<totalWorms; i++) {
        int worm;
        cin>>worm;
        lastIndex++;
        int newLastIndex = lastIndex + worm - 1;
        Worms.push_back(make_pair(lastIndex, newLastIndex));
        lastIndex = newLastIndex;
    }
    cin>>totalQuerys;
    for (int i=0; i<totalQuerys; i++) {
        int q;
        cin>>q;
        int res = Binary_Search(q);
        if (res != -1) {
            cout<<res + 1 <<endl;
        }
    }
    return (0);
}
