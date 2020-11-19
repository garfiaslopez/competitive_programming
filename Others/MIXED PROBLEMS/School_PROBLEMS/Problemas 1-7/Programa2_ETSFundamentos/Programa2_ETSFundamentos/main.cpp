//
//  main.cpp
//  Programa2_ETSFundamentos
//
//  Created by Jose De Jesus Garfias Lopez on 14/03/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

void Leer(float* X,float* N){
    cout<<"Ingrese el valor de N: ";
    cin>>*N;
    cout<<"Ingrese el valor de X: ";
    cin>>*X;
}

float Sumar(float* X,float* N){
    
    float suma=0.0;
    //la sumatoria dice que i = 1 hasta el valor de N
    for (int i = 1; i<= *N; i++) {
        suma = suma + (i + *X);
    }
    
    return suma;
}

void Imprimir(float* R){
    cout<<"Resultado es :"<<*R;
}
int main() {
    
    //se crean los apuntadores de tipo flotante:
    float *N = new float;
    float *X = new float;
    
    //se leen:
    Leer(X, N);
    
    //se llama a la funcion a la vez que se guarda el resultado en un flotante
    float Resultado = Sumar(X, N);
    //se asigna el flotante resultado a un apuntador de tipo float para poder pasarlo a la funcion imprimir
    float *Res = &Resultado;
    
    Imprimir(Res);
    
    return 0;
}
