// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:   https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4150
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int n, k;
int arr[100002];
int ST[300002];

int helper(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

void update(int nodo, int ini, int fin, int x, int val) {
    if (ini== fin && fin == x) {
        ST[nodo] = val;
    } else if (ini <= x && x <= fin) {
        int mid = (ini + fin) / 2;
        update(nodo * 2, ini, mid, x, val);
        update(nodo * 2 + 1, mid + 1, fin, x, val);
        ST[nodo] = ST[nodo*2] * ST[nodo * 2 +1];
    }
}

int query(int nodo, int ini, int fin, int l, int r) {
    if (r < ini || l > fin) { // if is completly outside
        return 1;
    } else if (ini >= l && fin <= r) { // if is completly inside
        return ST[nodo];
    } else { // partially 
        int mid = (ini + fin) / 2;
        int left = query(nodo * 2, ini, mid, l, r);
        int right = query(nodo * 2 + 1, mid + 1, fin, l, r);
        return left * right;
    }
}

void init_st(int nodo, int ini, int fin) {
    if (ini == fin) {
        ST[nodo] = helper(arr[ini]);
    } else {
        int mid = (ini + fin) / 2;
        init_st(nodo * 2, ini, mid);
        init_st(nodo * 2 + 1, mid + 1, fin);
        ST[nodo] = ST[nodo * 2] * ST[nodo * 2 + 1];
    }
}

int main() {
    while(scanf("%d %d", &n, &k) != EOF) {
        for (int i=1; i<=n; i++) {
            scanf("%d", &arr[i]);
        }
        init_st(1,1,n);
        char letter;
        for (int i=1; i <= k; i++) {
            scanf(" %c", &letter);
            if (letter == 'C') { // update op
                int i, v;
                scanf("%d %d", &i, &v);
                update(1,1,n,i,helper(v));
            } else if (letter == 'P') { // query op
                int l, r;
                scanf("%d %d", &l, &r);
                int val = query(1,1,n,l,r);
                if (val == 1) {
                    printf("+");
                } else if (val == -1) {
                    printf("-");
                } else {
                    printf("0");
                }
            }
        }
        printf("\n");
    }
    return (0);
}
