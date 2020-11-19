// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int persons, budget, hotels, weekends;
    while (cin>>persons) {
        cin>>budget>>hotels>>weekends;
        int lowerDeal = budget+10;
        for(int i=0;i<hotels;i++) {
            int pricePerson;
            cin>>pricePerson;
            for(int j=0;j<weekends;j++) {
                int availableBeds;
                cin>>availableBeds;
                if (availableBeds >= persons) {
                    int m = persons * pricePerson;
                    if (m <= budget && m < lowerDeal) {
                        lowerDeal = m;
                    }
                }
            }
        }
        if (lowerDeal != budget+10) {
            cout<<lowerDeal<<endl;
        } else {
            cout<<"stay home"<<endl;
        }
    }
    return (0);
}
