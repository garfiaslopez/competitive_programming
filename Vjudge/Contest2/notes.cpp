
// unlocking the lock:
vector <string> aristas;
map <string, int> mapa;
queue <string> q;

q.push(S);
mapa[S]=0;
while (!q.empty()) {
    act = q.front();
    q.pop();
    for (auto v:aristas) {
        sy = apply(act,v);
        if (!mapa.count(sy)) {
            q.push(sy);
            mapa[sy] = mapa[act]
        }
    }
}

// ice cave
    //revisar vecinos



// Fire!:

// considerar que primero se mueve el fuego para determinar a donde se mueve JOE.
// primero resolver si salimos de la matriz
//

// Tirar una BFS sobre JOE para ver cuanto te tardas en llegar a la salida.
// Tirar una BFS sobre todos los fuegos para ver cuanto tardan en llegar los fuegos a cada punto.
// comparar sobre las orillas
// 2 bfs diferentes o una BFS con 1 struct.
//

//para el nodo:
struct node {
    int tipo, tiempo;
    int x,y;
}

queue <nodo> q;

for (auto it: Fuego) { // coordenadas de los fuegos
    q.push(nodo(i,j,1,0));
}
q.push(i,j,0,0); // cordenada de JOE;


// Almost Shortest Path:

// el camino casi mas corto no es lo  mismo que el segundo mas corto:

d[s][v] + p[u][v] + d[u][t] == d[s][t]


// BABEL: MODELAR EL GRAFO Y TIRAR UN DIJSKTRA
/*
      Español    Ingles   Frances
        a           a       a
        b           b       b
S       .           .       .           T
        .           .       .
        z           z       z
*/

// B - Ancient Messages:  (FINAL MUNDIAL) ( Algoritmo de deteccion de imagenes. );
// Contar los huecos que tiene la imagen, cada imagen tienen huecos de 0 a 5;
