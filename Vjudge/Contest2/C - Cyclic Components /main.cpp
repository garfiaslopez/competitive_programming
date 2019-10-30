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
        void addEdge(int v, int w);
        int countCyclics();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::dfs(int v, bool visited[], int parent) {
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            if (dfs(*i, visited, v)) {
                return true;
            }
        } else if (*i != parent) {
            if (!visited[parent]) {
                return false;
            }
            return true;
        }
    }
    return false;
}

int Graph::countCyclics() {
    int cyclicsCount = 0;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            if (dfs(u, visited, -1)) {
                cyclicsCount++;
            }
        }
    }

    return cyclicsCount;
}

int main() {
    Graph G(200001);
    int E1,E2;
    while (scanf("%d%d", &E1,&E2) == 2) {
        G.addEdge(E1,E2);
    }
    int res = G.countCyclics();
    printf("%d\n", res);
    return 0;
}
