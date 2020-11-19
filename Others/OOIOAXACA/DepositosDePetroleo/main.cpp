// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=513
//
// © Jose Garfias Lopez
// Oil Deposits

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

queue < pair<int,int> > Cola; // pair <int,int> -> pair<char,int>
int Matriz[105][105];
int Filas;
int Columnas;
int FILS[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int COLS[8] = {1, -1, 1, 0, -1, 1, -1, 0};

void LeerMatriz() {
    for (int i = 1; i <= Filas; i++) { // for de FILAS
        char line[Columnas]; // arreglo char[COLUMAS]
        fflush(stdin);
        scanf("%s\n", line);
        for (int j=0; j<Columnas; j++) {
            if (line[j] == '@') {
                Matriz[i][j+1] = 1;
            } else {
                Matriz[i][j+1] = 0;
            }
        }
    }
}
void Bordeado() {
    for (int i = 0; i <= Filas + 1; i++) {
        Matriz[i][0] = -1;
        Matriz[i][Columnas + 1] = -1;
    }
    for (int i = 0; i <= Columnas + 1; i++) {
        Matriz[0][i] = -1;
        Matriz[Filas + 1][i] = -1;
    }
}

void BFS(pair<int,int> P) {
    Matriz[P.first][P.second] = 2; // ya la estamos procesando;
    Cola.push(P); // insertar coordenadas;
    while(!Cola.empty()) {
        pair<int, int> UltimoElemento = Cola.front();
        Cola.pop();
        for (int m=0; m<8; m++) {
            int f = UltimoElemento.first + FILS[m];
            int c = UltimoElemento.second + COLS[m];
            if (Matriz[f][c] == 1) {
                Matriz[f][c] = 2;
                pair<int,int> P = make_pair(f,c);
                Cola.push(P);
            }
        }
    }
}

int Procesar() {
    int DepositosEncontrados = 0;
    for (int i=1; i<=Filas; i++) {
        for (int j=1; j<=Columnas; j++) {
            if (Matriz[i][j] == 1) { // pocket
                pair<int,int> p = make_pair(i,j);
                BFS(p);
                DepositosEncontrados++;
            }
        }
    }
    return DepositosEncontrados;
}

int main() {

    while(cin>>Filas>>Columnas, Filas > 0) {
        LeerMatriz();
        Bordeado();
        int Depositos = Procesar();
        cout<<Depositos<<endl;
    }
    return (0);
}
