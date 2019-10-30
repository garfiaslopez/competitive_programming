// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=540
//
// © Jose Garfias Lopez
//
#include <cstdio>
#include <iostream>
#include <vector>

#define MAX 10005

using namespace std;

int charToInt(char A) {
    return (int)A - 'A';
}

class UnionFind {
    int tam;
    int parent[MAX];
    public:
        UnionFind(vector<int> arr) {
            tam = 30;
            for (int i=0; i<30; i++) {
                parent[i] = -1;
            }
            for (int i=0; i<arr.size(); i++) {
                parent[arr[i]] = arr[i];
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
            for(int i=0; i<tam; i++) {
                cout<< i <<"  ";
            }
            cout<<endl;
            for(int i=0; i<tam; i++) {
                cout<<parent[i] << "  ";
            }
            cout<<endl;
            cout<<"-----------------------"<<endl;
        }
        pair<int,int> ParentsAndAloneParents() {
            pair<int,int> p = make_pair(0,0);
            vector<int> pa;
            for (int i=0; i<tam; i++) {
                if (parent[i] == i) {
                    pa.push_back(i);
                }
            }
            for (int i=0; i<pa.size(); i++) {
                int paVeces = 0;
                for (int j=0; j<tam; j++) {
                    if (parent[j] == pa[i]) {
                        paVeces++;
                    }
                }
                if (paVeces > 1) {
                    p.first += 1;
                } else {
                    p.second += 1;
                }
            }
            return p;
        }
};

int main() {
    int cases;
    scanf("%d\n", &cases);
    for (int c=1; c<=cases; c++) {
        string Union;
        vector<pair<int,int> > Unions;
        while(getline(cin, Union), Union[0] != '*') {
            int A = charToInt(Union[1]);
            int B = charToInt(Union[3]);
            Unions.push_back(make_pair(A,B));
        }
        string Node;
        vector<int> Nodes;
        getline(cin, Node);
        for (int i=0; i<Node.length(); i++) {
            if (Node[i] != ',') {
                Nodes.push_back(charToInt(Node[i]));
            }
        }
        UnionFind UF = UnionFind(Nodes);
        for (int i=0; i<Unions.size(); i++) {
            UF.Union(Unions[i].first, Unions[i].second);
        }
        pair<int,int> p = UF.ParentsAndAloneParents();
        cout<<"There are "<<p.first<<" tree(s) and "<<p.second<<" acorn(s)."<<endl;
    }
    return (0);
}
