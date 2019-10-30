// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=400
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#define MAX 100005

using namespace std;

int charToInt(char A) {
    return (int)A - 'A';
}

class UnionFind {
    int tam;
    int parent[MAX];
    public: 
        UnionFind(int t) { // MakeSet
            tam = t;
            for (int i=0; i<=MAX; i++) {
                parent[i] = -1;
            }
        }
        void Init(int A, int B) {
            if (parent[A] == -1) {
                parent[A] = A;
            }
            if (parent[B] == -1) {
                parent[B] = B;
            }
        }
        int Find(int A) {
            if (parent[A] == A) {
                return A;
            } else {
                // Union find normal
                // return Find(parent[A]); 
                //Compresion de caminos
                return parent[A] = Find(parent[A]); 
            }
        }
        void Union(int A, int B) {
            int aRoot = Find(A);
            int bRoot = Find(B);
            parent[aRoot] = bRoot;
        }
        int Conexas() {
            int counter = 0;
            for (int i=0; i<tam; i++) {
                if (parent[i] == i) {
                    counter++;
                }
            }
            return counter;
        }
        bool SameComponent(int A, int B) {
            if (Find(A) == Find(B)) { // mismo padre
                return true;
            }
            return false;
        }
        void Print() {
            cout<<"-----------------------"<<endl;
            for(int i=0; i<=tam + 1; i++) {
                cout<< i <<"  ";
            }
            cout<<endl;
            for(int i=0; i<=tam + 1; i++) {
                cout<<parent[i] << "  ";
            }
            cout<<endl;
            cout<<"-----------------------"<<endl;
        }
};

int main() {
    int cases;
    scanf("%d\n", &cases);
    for (int c=1; c<=cases; c++) {
        char TAM;
        scanf("%c\n",&TAM);
        UnionFind UF = UnionFind(charToInt(TAM)+1);
        string Union;
        while(getline(cin, Union), Union != "\0") {
            int A = charToInt(Union[0]);
            int B = charToInt(Union[1]);
            UF.Init(A, B);
            UF.Union(B, A);
        }
        // UF.Print();
        cout<<UF.Conexas()<<endl<<endl;
    }
    return (0);
}
