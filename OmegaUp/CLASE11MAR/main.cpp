#include <iostream>
#include <map>

using namespace std;

int main() {
    // LEER DATOS
    // N -> Numero de elementos comprados
    // K -> Numero de elementos que se pueden comprar
    int N,K;  // 1 < N.K < 10^5

    // MAPA: Para guardar la lista de elementos que se pueden comprar
    // KEY - VALUE    ELEMENTO - PRECIO   STRING - INT
    map<string, int> ListaDeElementos;

    // agregando valores dentro del mapa:
    // ListaDeElementos["Papel"] = 50;
    // ListaDeElementos["Pastadental"] = 500;
    // ListaDeElementos["Pastadental"] = 200;
    // cout<<ListaDeElementos["Papel"]<<endl;

    // Leer N y K
    cin>>N>>K;

    // Leer la lista de precios de los elementos
    for (int i=0; i<K;i++) { // iterar K veces
        string elemento = "";
        int precio = 0;
        cin>>elemento>>precio;
        ListaDeElementos[elemento] = precio;
    }

    int total = 0;
    for (int i=0; i<N;i++){ // iterar N veces
        string elemento = "";
        cin>>elemento;
        int precio = ListaDeElementos[elemento];
        total = total + precio;
    }

    cout<<total<<endl;

    return (0);
}