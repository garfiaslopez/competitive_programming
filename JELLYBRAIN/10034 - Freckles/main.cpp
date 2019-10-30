// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

#define MAX 1005  // max Nodes

struct Edge {
    int origin;
    int destiny;
    double weight;
    Edge(){};
    Edge(int init_origin, int init_destiny, double init_weight){
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


double distance_between_points(pair<double,double> a, pair<double,double> b) {
    double distancex = (b.first - a.first) * (b.first - a.first);
    double distancey = (b.second - a.second) * (b.second - a.second);
    return sqrt(distancex + distancey);
}

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

double Kruskal(){
    int origin , destiny;
    double weight;
    double total = 0;
    int numNodes = 0;

    MakeSet(MaxNodes);
    sort(ArrayEdges.begin(), ArrayEdges.end());

    // cout<<"sortered: "<<endl;
    // for(int i=0; i<MaxEdges; i++) {
    //     Edge e = ArrayEdges[i];
    //     printf("( %d , %d ) : %f\n" , e.origin , e.destiny , e.weight ); //( vertice u , vertice v ) : peso
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

    return total;
}

int main() {
    int cases;
    cin>>cases;
    while(cases--) {
        // read the points
        int points;
        cin>>points;
        vector<pair<double,double> > coordinates;
        for(int i=0; i<points; i++) {
            double x,y;
            cin>>x>>y;
            coordinates.push_back(make_pair(x,y));
        }

        MST.clear();
        ArrayEdges.clear();

        //Create the graph with edges:
        for(int i=0; i<points; i++) { // i => the identifier of node.
            for(int j=i + 1; j<points; j++) {
                double distance = distance_between_points(coordinates[i], coordinates[j]);
                // one side
                //cout<<i<<" - "<<j<<" -> "<<distance<<endl;
                ArrayEdges.push_back(Edge(i,j,distance));
                // ArrayEdges.push_back(Edge(j,i,distance));
            }
        }

        MaxNodes = points;
        MaxEdges = ArrayEdges.size();

        // for(int i=0; i<MaxEdges; i++) {
        //     Edge e = ArrayEdges[i];
        //     printf("( %d , %d ) : %f\n" , e.origin , e.destiny , e.weight ); //( vertice u , vertice v ) : peso
        // }
        if (cases != 0) {
            cout<<fixed<<setprecision(2)<<Kruskal()<<endl<<endl;
        } else {
            cout<<fixed<<setprecision(2)<<Kruskal()<<endl;
        }

    }   
    return (0);
}
