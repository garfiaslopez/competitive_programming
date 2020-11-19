// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1055
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int months;
    while (cin>>months, months > 0) {
        double initialPay;
        double totalDebt;
        int totalDrops;
        double drops[100] = {0.0};
        cin>>initialPay;
        cin>>totalDebt;
        cin>>totalDrops;
        for (int i=0; i<totalDrops; i++) {
            int month;
            double total;
            cin>>month;
            cin>>total;
            drops[month] = total;
        }
        // normalize array;
        int totalMonths = 0;
        double actualDrop = 0.0;
        double carValue = (totalDebt + initialPay) - ((totalDebt + initialPay) * drops[0]);
        actualDrop = drops[0];
        double debtValue = totalDebt;
        double payPerMonth = totalDebt/months;
        //cout<<"month: 0"<<" - drop: "<<actualDrop<<endl;
        //cout<<"carValue: "<<carValue<<" debtValue: "<<debtValue<<endl;
        if (carValue < debtValue) {
            for (int i=1; i<=months; i++) {
                if (drops[i] != 0.0) {
                    actualDrop = drops[i];
                }
                //cout<<"month: "<<i<<" - drop: "<<actualDrop<<endl;
                carValue -= (carValue * actualDrop);
                debtValue -= payPerMonth;
                //cout<<"carValue: "<<carValue<<" debtValue: "<<debtValue<<endl;
                if (carValue >= debtValue) {
                    totalMonths=i;
                    break;
                }
            }
        }
        if (totalMonths == 1) {
            cout<<totalMonths<<" month"<<endl;
        } else {
            cout<<totalMonths<<" months"<<endl;
        }
    }
    return (0);
}
