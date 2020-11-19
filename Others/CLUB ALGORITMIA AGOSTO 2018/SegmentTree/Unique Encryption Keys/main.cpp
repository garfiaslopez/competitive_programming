// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3892
//
// © Jose Garfias Lopez
// a segment tree of min's vals

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

#define INF 2000000

int m, q;
int arr[1000002];
int derCercano[1000002];
int ST[2100002];

void preprocess() {
    map <int,int> mapa;
    for (int i = m; i >= 1; i--) {
        if (mapa[arr[i]] > 0) {
            derCercano[i] = mapa[arr[i]];
            mapa[arr[i]] = i;
        } else {
            derCercano[i] = INF;
            mapa[arr[i]] = i;
        }
    }
}
void init_st (int nodo, int ini, int fin) {
    if (ini == fin) {
        ST[nodo] = derCercano[ini];
    } else {
        int mid = (ini + fin) / 2;
        init_st(nodo * 2, ini, mid);
        init_st(nodo * 2 + 1, mid + 1, fin);
        ST[nodo] = min(ST[nodo * 2], ST[nodo * 2 + 1]);
    }
}

int query(int nodo, int ini, int fin, int l, int r) {
    if (fin < l || r < ini) {
        return INF;
    } else if (l <= ini && fin <= r) {
        return ST[nodo];
    } else {
        int mid = (ini + fin) / 2;
        int izq = query(nodo * 2, ini, mid, l, r);
        int der = query(nodo * 2 + 1, mid + 1, fin, l, r);
        return min (izq, der);
    }
}
int main() {
    scanf("%d %d", &m, &q);
    while(!(m == 0 && q == 0)){
        for (int i = 1; i <= m; i++) {
            scanf("%d", &arr[i]);
        }
        preprocess();
        init_st(1,1,m);
        for (int i = 1; i<= q; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            int idx = query(1,1,m,l,r);
            if (idx > r) {
                printf("OK\n");
            } else {
                printf("%d\n", arr[idx]);
            }
        }
        printf("\n");
        scanf("%d %d", &m, &q);
    } 
    return (0);
}
