// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://omegaup.com/arena/problem/diametroarbol#problems
//
// © Jose Garfias Lopez
//


#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) { 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

int DFSUtil(int u, vector<int> adj[], vector<bool> &visited) { 
    visited[u] = true; 
    int crossed = 1;
    for (int i=0; i<adj[u].size(); i++) {
        if (visited[adj[u][i]] == false) {
            crossed++;
            DFSUtil(adj[u][i], adj, visited);
        }
    }
    return crossed;
} 

void DFS(vector<int> adj[], int V) { 
    vector<bool> visited(V, false);
    int max = -1;
    for (int u=1; u<=V; u++) {
        if (visited[u] == false){
            int crossedVertex = DFSUtil(u, adj, visited);
            if (crossedVertex > max){
                max = crossedVertex;
            }
        }
    }
    cout<<max<<endl;
} 

int main() { 
    int V;
    cin>>V;
    vector<int> adj[V+1]; // vector<int> *adj = new vector<int>[V]; 
    
    for (int i=0; i<V - 1; i++) {
        int a,b;
        cin>>a>>b;
        addEdge(adj, a, b);
    }
    
    DFS(adj, V);
    return 0; 
} 