// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=78&page=show_problem&problem=2726
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int banksTam, debts;
    while (cin>>banksTam>>debts, banksTam > 0) {
        int banks[banksTam];
        for (int i=0;i<banksTam;i++) {
            cin>>banks[i];
        }
        for (int i=0;i<debts;i++) {
            int origin,destiny,value;
            cin>>origin>>destiny>>value;
            banks[origin-1] -= value;
            banks[destiny-1] += value;
        }
        bool canPay = true;
        for (int i=0;i<banksTam;i++) {
            if (banks[i] < 0) {
                canPay = false;
                break;
            }
        }
        if (canPay) {
            cout<<"S"<<endl;
        } else {
            cout<<"N"<<endl;
        }
    }
    return (0);
}
