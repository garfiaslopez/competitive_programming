#include <iostream>

using namespace std;

int main() {
    // 1.- LEER LA ENTRADA (N y N Palabras); // 3
    int numeroDePalabras = 0;
    cin>>numeroDePalabras;

    int minimoTamano = 501; // MINIMO
    string minimaPalabra = "";
    for (int i=0; i<numeroDePalabras; i++) { // se va a ejecutar N veces
        string palabra = "";
        cin>>palabra;

        int tamanoDePalabra = palabra.length(); // regresa el tamaño de la palabra 

        // Comparar para ver si es la palabra de menor tamaño o longitud
        if (tamanoDePalabra < minimoTamano) {
            minimoTamano = tamanoDePalabra;
            minimaPalabra = palabra;
        }
    }

    cout<<minimaPalabra<<endl<<minimoTamano<<endl;

    if (minimoTamano % 2 == 0) {
        cout<<"par"<<endl;
    }  else {
        cout<<"impar"<<endl;
    }

    return(0);
}