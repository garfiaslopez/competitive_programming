//
//  main.cpp
//  Programa5_ETSFundamentos
//
//  Created by Jose De Jesus Garfias Lopez on 14/03/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

//se usa recursividad para calcular el factorial de n
long double CalcularFacto(int N)
{
    if (N==0)
        return 1;
    else
        return N*CalcularFacto(N-1);
}

float CalcularFx(float X, int N){
    
    float Anterior=0; //variable auxiliar para almacenar el resultado anterior....
    bool Signo=false;   //false = negativo     True = Positivo
    
    float FX=0;
    //se empieza el ciclo en 2... hasta N
    for (int i=2; i<=N; i++) {
        
        float Resultado = powf(X, i) / CalcularFacto(i);  //powf saca el exponente de dos flotantes: (float,int).
        
        //si no es la primera operacion:
        if (i != 2) {
            
            if (Signo == true) { //Se suma:
                
                FX = Anterior + Resultado;
                Signo = false;   // se invierte la bandera para la siguiente vez que pase...
                
            }else{   //se resta
            
                FX = Anterior - Resultado;
                Signo = true;

            }
            
        }else{
            FX=Resultado;
        }
        
        //el resultado actual se pasa al anterior
        Anterior = FX;
        
    }
    
    
    return FX;
}

void Leer(float &X, int &N){
    cout<<"Valor de X: ";
    cin>>X;
    cout<<"Valor de N: ";
    cin>>N;
}

void Imprimir(float Res){
    cout<<"Resultado de F(x): "<<Res;
}

int main() {
    
    float X;
    int N;
    
    Leer(X,N);

    if (N >= 2) {
        
        float Resultado = CalcularFx(X, N);
        Imprimir(Resultado);
        
    }else{
        cout<<"N tiene que ser mayor o igual a 2"<<endl;
    }
 
    
    return 0;
}
