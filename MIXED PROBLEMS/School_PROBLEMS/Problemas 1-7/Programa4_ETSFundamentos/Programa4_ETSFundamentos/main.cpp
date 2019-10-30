//
//  main.cpp
//  Programa4_ETSFundamentos
//
//  Created by Jose De Jesus Garfias Lopez on 14/03/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

void Leer(float *Cajas){

    for (int i = 0; i<18; i++) {
        
        cout<<"Ingrese Cantidad de caja #"<<i+1<<" : ";
        cin>>Cajas[i];
        
    }
    
}

void Calcular(float *Cajas){
    
    //TOTAL Y PROMEDIO DE DINERO
    
    float suma = 0;
    
    for (int i = 0; i<18; i++) {
        suma = suma + Cajas[i];
    }
    
    cout<<"Total en Cajas: $"<<suma<<endl;
    cout<<"Promedio en Cajas: "<<suma/18<<endl;
    
    float Mayor = 0;
    float Menor = 0;
    int CajaMayor = 0;
    int CajaMenor = 0;
    int MenoresProm=0;
    
    //se inicializa nuestra variable auxiliar menor para saber cual es el menor, sino siempre seria 0.
    Menor = Cajas[0];
    
    for ( int i = 0; i<18; i++) {
        
        //se va comparando cuales son menores al promedio y se suma un contador:
        if (Cajas[i] < (suma/18) ) {
            MenoresProm++;
        }
        //se compara si es mayor a una variable auxiliar para contabilizar cual es el mas grande
        if (Cajas[i] > Mayor) {
            Mayor = Cajas[i];
            CajaMayor = i+1;
        }
        //se compara si es menor a una variable auxiliar para contabilizar cual es el mas pequeño.
        if (Cajas[i] < Menor) {
            Menor = Cajas[i];
            CajaMenor = i+1;
        }
    }
    
    cout<<"Cajas debajo del promedio : "<<MenoresProm<<endl;
    cout<<"Caja con mayor dinero : #"<<CajaMayor<<" Dinero : $"<<Mayor<<endl;
    cout<<"Caja con menor dinero : #"<<CajaMenor<<" Dinero : $"<<Menor<<endl;
    

}


int main(int argc, const char * argv[]) {
    
    float *Cajas = new float[18];
    
    Leer(Cajas);
    Calcular(Cajas);
    
    return 0;
}
