//
//  main.cpp
//  Problema7_ETSFundamentos
//
//  Created by Jose De Jesus Garfias Lopez on 14/03/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

//A las funciones solo se le pasa la matriz y procesa los datos:

void Leer(float **Matriz,int F, int C){
    cout<<"Lectura de Matriz: "<<endl;
    for (int i = 0; i<F; i++) {
        cout<<"Lectura de Fila "<<i+1<<endl;
        for (int j = 0; j<C; j++) {
            
            cout<<"Ingrese Lectura #"<<j+1<<" : ";
            cin>>Matriz[i][j];
            
        }
    }
    
}

void Transpuesta(float **Matriz,int F, int C){
    
    cout<<"Matriz Original:"<<endl;
    for (int i = 0; i<F; i++) {
        for (int j = 0; j<C; j++) {
            cout<<Matriz[i][j]<<"   ";
        }
        cout<<endl;
    }
 
    cout<<"Matriz Transpuesta:"<<endl;
    for (int i = 0; i<F; i++) {
        for (int j = 0; j<C; j++) {
            cout<<Matriz[j][i]<<"   ";
        }
        cout<<endl;
    }
    
}


int main() {
    
    int Filas = 0;
    int Columnas = 0;
    
    cout<<"Numero de filas: ";
    cin>>Filas;
    cout<<"Numero de Columnas: ";
    cin>>Columnas;
    
    
    //Matriz de apuntadores
    float **Matriz = new float*[Filas];
    for (int i = 0; i<Columnas; i++) {
        Matriz[i] = new float[Columnas];
    }
    
    Leer(Matriz,Filas,Columnas);
    Transpuesta(Matriz, Filas, Columnas);
    
    return 0;
}
