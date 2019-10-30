// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> timeCashes;
vector<int> peopleInCashes;

int main() {
    int numberOfCashes;
    int numberOfPeople;
    int timeTravel;
    int timeForBuy;
    scanf("%d %d %d %d", &numberOfCashes, &numberOfPeople, &timeTravel, &timeForBuy);
    int lowerTimeCash = 3000;
    int higherTimeCash = 0;

    for (int i=0; i<numberOfCashes; i++) {
        int timeCash;
        scanf("%d", &timeCash);
        timeCashes.push_back(timeCash);
        // lower time
        if (timeCash < lowerTimeCash) {
            lowerTimeCash = timeCash;
        }
        // higher time
        if (timeCash > higherTimeCash) {
            higherTimeCash = timeCash;
        }
    }

    int timeRemain = timeForBuy - (timeTravel * 2) - lowerTimeCash;
    printf("time remain: %d\n", timeRemain);

    if (timeRemain <= 0) {
        printf("NO");
        return (0);
    } else {
        // do the calculation for serve people on timeRemain:
        // sort the array:
        sort(timeCashes.begin(), timeCashes.begin());
        int maxCashes = numberOfCashes;
        int cost = 0;
        while (maxCashes--) {
            printf("actual cash: %d\n", maxCashes);
            int fullCashes = numberOfPeople/(maxCashes + 1);
            if (numberOfPeople%(maxCashes + 1) != 0) {
                int leftMaxCash = (numberOfPeople%(maxCashes + 1)) - 1;
                cost = (fullCashes * timeCashes[maxCashes]) + (timeCashes[leftMaxCash]);
            } else {
                cost = (fullCashes * timeCashes[maxCashes]);
            }
            printf("cost: %d\n", cost);
            if (cost <= timeRemain) {
                break;
            }
        }
        if (cost <= timeRemain) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
    return (0);
}
