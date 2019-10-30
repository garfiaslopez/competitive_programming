//
//  main.cpp
//  Programa3_ETSFundamentos
//
//  Created by Jose De Jesus Garfias Lopez on 14/03/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

//A las funciones solo se le pasa la matriz y procesa los datos:

void Leer(float **Matriz,int F, int C){
    cout<<"(A) - Lectura de Matriz: "<<endl;
    for (int i = 0; i<F; i++) {
        cout<<"Lectura de Fila "<<i+1<<endl;
        for (int j = 0; j<C; j++) {
            
            cout<<"Ingrese Lectura #"<<j+1<<" : ";
            cin>>Matriz[i][j];
            
        }
    }
    
}

void Contar(float **Matriz,int F, int C){
    
    float PromedioFila2=0;
    int MenoresA15=0;
    //promedio de cada fila:
    cout<<"(B) - Promedios de cada fila: "<<endl<<endl;
    for (int i=0; i<F; i++) {
        
        float SumaFila=0;
        
        for (int j=0; j<C; j++) {
            //se hace la sumatoria de la fila: (B)
            SumaFila = SumaFila + Matriz[i][j];
            
            //si el numero en ese elemento es menor a 15 suma uno para llevar el conteo del punto (D)
            if (Matriz[i][j]<15) {
                MenoresA15++;
            }
        }
        
        //si estoy en la fila 2 (1 porque empieza en 0 la matriz) guardo el promedio en otra variable, ya que se ocupara adelante. Punto (C)
        if (i == 1) {
            PromedioFila2 = SumaFila/C;
        }
        
        cout<<"Promedio de fila "<<i+1<<" :"<<SumaFila/C<<endl;
    }
    
    //(C) Fila 2 mayores:
    int Mayores=0;
    
    for (int j = 0; j<C; j++) {
        if (Matriz[1][j] > PromedioFila2) {
            Mayores++;
        }
    }
    
    cout<<endl<<"(C) - Numeros Mayores al promedio en fila 2: "<<Mayores<<endl;
    
    cout<<endl<<"(D) - Numeros Menores a 15 : "<<MenoresA15<<endl;
    
    //(D) Columna con mayor SUMA:
    
    float MayorColumna=0;
    int NumColumna=0;
    //se recorre la matriz solo invirtiendo los indices para que haga el barrido de arriba hacia abajo

    for (int i=0; i<C; i++) {
        
        float SumaColumna=0;
        
        for (int j=0; j<F; j++) {
            SumaColumna = SumaColumna + Matriz[j][i];
        }
        
        //se compara si es la mayor hasta ese momento con nuestra variable auxiliar y se guarda que columna es.
        if (SumaColumna > MayorColumna) {
            MayorColumna = SumaColumna;
            NumColumna = i+1;
        }
    
    }
    
    cout<<endl<<"(E) - Mayor suma en columna #"<<NumColumna<<" - Suma: "<<MayorColumna<<endl;

}


int main() {
    
    int Filas = 3;
    int Columnas = 3;

    //Matriz de apuntadores
    float **Matriz = new float*[Filas];
    for (int i = 0; i<Columnas; i++) {
        Matriz[i] = new float[Columnas];
    }
    
    Leer(Matriz,Filas,Columnas);
    Contar(Matriz, Filas, Columnas);
    
    return 0;
}
