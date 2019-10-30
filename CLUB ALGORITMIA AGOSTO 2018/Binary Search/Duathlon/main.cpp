// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

#define INF 10000000000
typedef double Double;

using namespace std;
vector< pair<Double, Double> > speeds;

struct Stats {
    int time;
    Double k;
    Double r;
};

int calculateTime(Double r, int distance) {
    Double k = distance - r;
    Double minTime = INF;
    for (int i=0; i<speeds.size()-2; i++) { // Iterate for participants (no cheater)
        Double timeI = ((r/speeds[i].first) + (k/speeds[i].second)) * 3600;
        if (timeI < minTime) {
            minTime = timeI;
        }
    }
    Double lastTime = ((r/speeds[speeds.size() - 1].first) + (k/speeds[speeds.size() - 1].second)) * 3600;
    return minTime - lastTime;
}

Stats minSpeed(int distance, pair<Double, Double> participant) {
    Double ini = 0.00;
    Double fin = (double)distance;
    Double m1;
    int e1, res;
    for (int i=0; i<20; i++) {
        cout<<"ini: "<<ini<<" - fin: "<<fin<<endl;
        m1 = (ini+fin)/2.0;
        cout<<"m1: "<<m1<<endl;
        e1 = calculateTime(m1, distance);
        cout<<"e1: "<<e1<<endl;
        if (e1 > 0) {
            res = m1;
            fin = m1 - 0.01;
        } else {
            ini = m1 + 0.01;

        }
    }
    // to return: 
    Stats s;
    s.time = res;
    s.r = ini;
    s.k = distance - ini;
    return s;
}

int main() {
    int distance;
    while(cin>>distance) {
        int participants;
        cin>>participants;
        for (int i=0;i<participants;i++) {
            Double a,b;
            cin>>a>>b;
            speeds.push_back(make_pair(a,b));
        }
        // get minimum for cheater:
        Stats info = minSpeed(distance, speeds[participants - 1]);
        cout<<"RESULTADOS: "<<info.time<<"s - r: "<<info.r<<" - k: "<<info.k<<endl;
        cout<<calculateTime(14.29, 100)<<endl;
    }
    return (0);
}
