// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int CeilIndex(vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
        int m = l + (r-l)/2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int lisl(vector<int> &v) {
    if (v.size() == 0)
        return 0;
    vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
    return length;
}

int main() {
    int tam;
    scanf("%d\n", &tam);
    vector<int> v;
    for (int i=0; i<tam;i++) {
        int number;
        scanf("%d", &number);
        v.push_back(number);
    }
    printf("%d\n", lisl(v));
    return (0);
}
