// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: http://poj.org/problem?id=1064
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double Double;
typedef long int Int;

Int totalCables, neededCables;
Double totalLengthCable = 0.00;
vector<Double> Messures;

Int eval(double cut) {
    Int sum=0;
    for (int i=0; i<totalCables; i++) {
        sum += int(Messures[i]/cut);
    }
    return sum;
}

double binary_search() {
    int iterations = 100;
    double neededCablesDouble = (double)neededCables;
    double ini=0, fin=(totalLengthCable/neededCables), res=-1, mid;
    while(iterations--) {
        mid = (ini + fin) / 2.00;
        Int resultEval = eval(mid);
        //cout<<"mid: "<<mid<<" res: "<<resultEval<<endl;
        if (resultEval >= neededCables) {
            res = mid;
            ini = mid + 0.0001;
        } else if (resultEval < neededCables) {
            fin = mid - 0.0001;
        }
    }
    return res;
}

int main() {
    // read:
    cin>>totalCables>>neededCables;
    for (int i=0; i<totalCables; i++) {
        Double temp;
        cin>>temp;
        totalLengthCable += temp;
        Messures.push_back(temp);
    }
    Double res = binary_search();
    if (res != -1) {
        cout<<fixed<<setprecision(2)<<res<<endl;
    } else {
        cout<<0.00<<endl;
    }
    return (0);
}
