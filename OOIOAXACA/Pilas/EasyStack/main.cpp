// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<int> pila;

    int num_operaciones;
    cin>>num_operaciones;

    for (int i=0; i<num_operaciones; i++) {
        int tipo_operacion;
        cin>>tipo_operacion;
        
        if (tipo_operacion == 1) { // PUSH METER A LA PILA
            int elemento;
            cin>>elemento;
            pila.push(elemento);
        } else if (tipo_operacion == 2) { /// POP ELIMINAR DE LA PILA
            if (!pila.empty()) {
                pila.pop();
            }
        } else { // TOP IMPRIMIR
            if (pila.empty()) {
                cout<<"Empty!"<<endl;
            } else {
                int ultimo_elemento = pila.top();
                cout<< ultimo_elemento <<endl;
            }
        }
    }

    return (0);
}
