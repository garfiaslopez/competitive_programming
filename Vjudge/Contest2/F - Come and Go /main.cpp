// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//

#include<iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    bool dfs(int v, bool visited[], int parent);
    public:
        Graph(int V);
        void addEdge(int v, int w, int p);
        int isAllConnected();
        void deleteG();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::deleteG() {
    adj.clear();
    delete adj;
}

void Graph::addEdge(int v, int w, int p) {
    if (p == 1) {
        adj[v].push_back(w);
    } else if (p == 2) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
}

bool Graph::dfs(int v, bool visited[], int parent) {
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            dfs(*i, visited, v);
        } else if (*i != parent) {
            return true;
        }
    }
    return false;
}

int Graph::isAllConnected() {
    int routes = 0;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    for (int u=0; u <V; u++) {
        if (!visited[u]) {
            if (dfs(u, visited, -1)) {
                routes++;
            }
        }
    }
    return routes;
}

int main() {
    int N,M;
    while (scanf("%d%d", &N,&M) == 2) {
        if (N>0 && M>0) {
            Graph G(N + 1);
            for (int i=0;i<M;i++) {
                int v,w,p;
                scanf("%d%d%d", &v,&w,&p);
                G.addEdge(v,w,p);
            }
            int res = G.isAllConnected();
            printf("%d\n", res);
            G.deleteG();
        }
    }
    return 0;
}
