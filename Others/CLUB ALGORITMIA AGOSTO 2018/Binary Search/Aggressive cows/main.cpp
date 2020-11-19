// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://www.spoj.com/problems/AGGRCOW/en/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Stalls, Cows;
vector<int> Positions;

bool eval(int minimun, int cows) {
    int actualIndex = Positions[0];
    int cowsSaved = 0;
    for (int i=0; i<Stalls; i++) {
        if (Positions[i] >= actualIndex) {
            cowsSaved++;
            actualIndex = Positions[i] + minimun;
        }
        if (cowsSaved >= cows) {
            return true;
        }
    }
    return false;
}

int Binary_Search(int ini, int fin, int q) {
    int mid,res=-1;
    while(ini<=fin) {
        mid = (ini+fin)/2;
        int midEval = eval(mid, q);
        // cout<<"mid: "<<mid<<" eval: "<<midEval<<endl;
        if (midEval) { // if is a posible sol go to right
            res = mid;
            ini = mid + 1;
        } else { // if not, go to left
            fin = mid - 1;
        }
    }
    return res;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        cin>>Stalls>>Cows;
        for (int i=0; i<Stalls; i++) {
            int temp;
            cin>>temp;
            Positions.push_back(temp);
        }
        sort(Positions.begin(), Positions.end());
        cout<<Binary_Search(Positions[0], Positions[Stalls-1], Cows)<<endl;
        Positions.clear();
    }
    return (0);
}
