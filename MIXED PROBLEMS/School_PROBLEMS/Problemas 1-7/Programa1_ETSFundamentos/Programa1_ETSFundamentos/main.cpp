//
//  main.cpp
//  Programa1_ETSFundamentos
//
//  Created by Jose De Jesus Garfias Lopez on 14/03/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

//A las funciones solo se le pasa la matriz y procesa los datos:

void Leer(int **Velocidades,int F, int C){

    for (int i = 0; i<F; i++) {
        cout<<"Lectura de carril "<<i+1<<endl;
        for (int j = 0; j<C; j++) {
        
            cout<<"Ingrese Lectura #"<<j+1<<" : ";
            cin>>Velocidades[i][j];
            
        }
    }
    
}

void Imprimir(int **Velocidades,int F, int C,int May, int Min){
    
    cout<<endl<<"TABLA DE VELOCIDADES: "<<endl;
    
    for (int i = 0; i<F; i++) {
        for (int j = 0; j<C; j++) {
            cout<<Velocidades[i][j]<<"   ";
        }
        cout<<endl;
    }
    
    cout<<endl<<"Resultados:"<<endl;
    cout<<"Velocidades Menores: "<<Min<<endl;
    cout<<"Velocidades Mayores: "<<May<<endl;
    
}


void Contar(int **Velocidades,int F, int C){
    
    int Menores=0;
    int Mayores=0;
    
    for (int i = 0; i<F; i++) {
        for (int j = 0; j<C; j++) {
            if (Velocidades[i][j] > 100) {
                Mayores++;
            }else if (Velocidades[i][j] < 40){
                Menores++;
            }
        }
    }
    
    Imprimir(Velocidades, F, C, Mayores, Menores);
}


int main() {
    
    int Columnas;
    int Filas = 3;
    
    cout<<"Muestras por carril: ";
    cin>>Columnas;
    
    //matriz de muestras: (Matriz de apuntadores
    int **Velocidades = new int*[3];
    for (int i = 0; i<Columnas; i++) {
        Velocidades[i] = new int[Columnas];
    }
    
    Leer(Velocidades,Filas,Columnas);
    Contar(Velocidades, Filas, Columnas);
    
    return 0;
}
