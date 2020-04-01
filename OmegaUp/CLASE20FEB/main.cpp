#include <iostream>

using namespace std;

int main() {
    int alumnos, profesores;
    cin>>profesores>>alumnos;

    int respuestas[alumnos];
    // for desde 0 hasta el numero total de alumnos
    for (int i=0; i<alumnos; i++) {
        cin>>respuestas[i]; // leer y guardar en el arreglo las respuestas
    }

    //inicializar arreglo de frecuencias con el tamaño de los profesores
    int frecuencias[profesores + 4];
    for (int i=1; i<=profesores; i++) {
        frecuencias[i] = 0;
    }

    // recorrer las respuestas y contabilizar las apariciones de los profesores
    for (int i=0; i<alumnos; i++) {
        int profesor = respuestas[i]; // recuperando que profesor es;
        frecuencias[profesor] = frecuencias[profesor] + 1;
    }

    // imprimir frecuencias como respuesta
    for (int i=1; i<=profesores; i++) {
        cout<<i<<"-"<<frecuencias[i]<<endl;
    }
    return (0);
}