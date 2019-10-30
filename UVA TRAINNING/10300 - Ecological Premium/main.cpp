// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=15&problem=1241&mosmsg=Submission+received+with+ID+21582310
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int farmers;
        cin>>farmers;
        int sum=0;
        while (farmers--) {
            int farmSize, animals, env;
            cin>>farmSize>>animals>>env;
            sum += farmSize * env;
        }
        cout<<sum<<endl;
    }
    return (0);
}
