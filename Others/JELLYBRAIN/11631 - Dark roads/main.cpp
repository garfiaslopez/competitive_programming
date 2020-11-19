// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 200005  // max Nodes

struct Edge {
    int origin;
    int destiny;
    int weight;
    Edge(){};
    Edge(int init_origin, int init_destiny, int init_weight){
        origin = init_origin;
        destiny = init_destiny;
        weight = init_weight;
    }
    bool operator<(const Edge &e) const {
        return weight < e.weight;
    }
}; // For kruskal

int MaxNodes, MaxEdges; // N of nodes and edges
vector<Edge> ArrayEdges;
vector<Edge> MST(MAX);     // MST founded

///  UNION-FIND CLASS
int padre[MAX];
void MakeSet(int n){
    for(int i=0; i<n; i++) padre[i] = i;
}
int Find(int x){
    return (x == padre[x]) ? x : padre[x] = Find(padre[x]);
}
void Union(int x , int y){
    padre[Find(x)] = Find(y);
}
bool sameComponent(int x , int y){
    if(Find(x) == Find(y)) return true;
    return false;
}

int Kruskal(){
    int origin , destiny;
    int weight;
    int total = 0;
    int numNodes = 0;

    MakeSet(MaxNodes);
    sort(ArrayEdges.begin(), ArrayEdges.end());

    // cout<<"sortered: "<<endl;
    // for(int i=0; i<MaxEdges; i++) {
    //     Edge e = ArrayEdges[i];
    //     printf("( %d , %d ) : %d\n" , e.origin , e.destiny , e.weight ); //( vertice u , vertice v ) : peso
    // }
    
    for(int i=0 ; i<MaxEdges; i++){
        origin = ArrayEdges[i].origin;
        destiny = ArrayEdges[i].destiny;
        weight = ArrayEdges[i].weight;

        if(!sameComponent(origin, destiny)){
            total += weight;
            MST[numNodes++] = ArrayEdges[i];
            Union(origin, destiny);
        }
    }
    // if( MaxNodes - 1 != numNodes ){
    //     return 0;
    // }

    // cout<<"result: "<<endl;
    // for(int i=0; i<numNodes; i++) {
    //     Edge e = MST[i];
    //     printf("( %d , %d ) : %d\n" , e.origin , e.destiny , e.weight ); //( vertice u , vertice v ) : peso
    // }
    
    return total;
}

int main() {
    int m,n;
    while(cin>>m>>n, m != 0 && n != 0) {
        MST.clear();
        ArrayEdges.clear();
        int total_energy = 0;
        for (int i=0; i<n; i++) {
            int x,y,z;
            cin>>x>>y>>z;
            total_energy += z;
            ArrayEdges.push_back(Edge(x,y,z));
        }
        
        MaxNodes = m;
        MaxEdges = ArrayEdges.size();
        //cout<<"MaxNodes: " <<MaxNodes<<"  MaxEdges:  "<<MaxEdges<<endl;
        cout<<total_energy - Kruskal()<<endl;
    }   
    return (0);
}
