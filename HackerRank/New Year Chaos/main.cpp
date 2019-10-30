// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
int bubbleSort(vector<int> &arr) {
    int swaps = 0;
    int n = arr.size();
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++) {
        swapped = false;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
                swaps++;
            }
        }
        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
    return swaps;
}


int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        int tam;
        cin>>tam;
        vector<int> numbers;
        bool possible = true;
        for (int i=1; i<=tam; i++) {
            int tempNumber;
            cin>>tempNumber;
            if((tempNumber - i) > 2) {
                possible = false;
            }
            numbers.push_back(tempNumber);
        }
        if (possible) {
            cout<<bubbleSort(numbers)<<endl;

        } else {
            cout<<"Too chaotic"<<endl;
        }
    }
    return (0);
}
