#include <iostream>
#include <vector>

using namespace std;

int main() {

    int perimetro = 0;
    int trozosDeMalla = 0;
    vector<int> cantidadesDeMalla; // arreglo de metros de malla 

    // Lectura de datos  
    cin>>perimetro>>trozosDeMalla;
    // Lectura de cada trozo de malla
    for (int i=0; i<trozosDeMalla; i++) {
        int cantidad; 
        cin>>cantidad; // leer la cantidad que vale en metros la malla
        cantidadesDeMalla.push_back(cantidad);  // insertar la cantidad en el vector.
    }

    // Sumar las cantidades de los trozos de malla para obtener el total que tenemos de malla
    int totalDeMalla = 0;
    // cantidadesDeMalla.size() regresa el tamaño del vector
    for (int i=0; i<cantidadesDeMalla.size(); i++) {
        totalDeMalla = totalDeMalla + cantidadesDeMalla[i]; // acumulamos la sumatoria de las cantidades;
    }

    int faltante = perimetro - totalDeMalla;

    if (faltante > 0) {
        cout<<faltante<<endl;
    } else {
        cout<<0<<endl;
    }
    
    return (0);
}