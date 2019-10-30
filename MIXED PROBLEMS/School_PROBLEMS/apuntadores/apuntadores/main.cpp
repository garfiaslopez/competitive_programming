//
//  main.cpp
//  apuntadores
//
//  Created by Jose De Jesus Garfias Lopez on 28/01/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int *apuntador;
    for (int i=0; i<3; i++) {
        cout<<"Dame el valor del "<<i+1<<" Numero: ";
        cin >> apuntador[i];
    }
    for (int i=0; i<3; i++) {
        cout<< apuntador[i]<< ", ";
    }

//    int i;
//    int arreglo[4] = {10,20,30,40};
//    int *apuntador;
//    
//    apuntador = arreglo;
//
//    for (int i = 0; i<4; i++) {
//        cout<< *apuntador++ <<endl;
//    }
    
//    int TAM = 0;
//    
//    cout<<"DAME EL TAMANO DEL ARREGLO: ";
//    cin>>TAM;
//    
//    float Arreglo[TAM];
//    
//    for (int i=0; i<TAM; i++) {
//        cout<<"Dame el valor del "<<i+1<<" Numero: ";
//        cin>>Arreglo[i];
//    }
//    
//    cout<<"MUCHAS GRACIAS"<<endl;
//    
//    for (int i=0; i<TAM; i++) {
//        cout<< "indice: "<< i <<endl;
//        cout<< "valor: "<< Arreglo[i] <<endl;
//    }
//
//    
    
    return 0;
}
