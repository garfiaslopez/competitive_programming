#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
#define INF 2000000

int ST[1000000];

int operation (int a, int b) {
    return min(a,b);
}

void init_st(int nodo, int start, int end, int value) {
    if (start == end) { // check if your a leaf
        ST[nodo] = value;
    } else { // go to their childrens
        int mid = (start + end) / 2;
        init_st(nodo * 2, start, mid, value);
        init_st(nodo * 2 + 1, mid + 1, end, value);
        ST[nodo] = operation(ST[nodo * 2], ST[nodo * 2 + 1]);
    }
}

int query_st(int nodo, int start, int end, int l, int r) {
    // check the conditions for the range:
    if (end < l || r < start) { // out of range, return something that doesn't affect the op
        return INF;
    } else if (l <= start && end <= r) { // if start and end is inside of l r
        return ST[nodo];
    } else {
        // go to check the childrens
        int mid = (start + end) / 2;
        int left = query_st(nodo * 2, start, mid, l, r);
        int right = query_st(nodo * 2 + 1, mid + 1, end, l, r);
        return operation(left, right);
    }
}