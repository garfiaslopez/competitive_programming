//
//  main.cpp
//  carbohidratos
//
//  Created by Jose De Jesus Garfias Lopez on 09/01/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int>VectorP;
vector<int>VectorC;
vector<int>VectorF;


bool Encontrado = false;
int Casos, Foods,GP,GC,GF;

void Leer(){
        
    cin>>GP;
    cin>>GC;
    cin>>GF;
    
    cin>>Foods;
    
    while (Foods--) {
        
        int x,y,z;
        
        cin>>x;
        cin>>y;
        cin>>z;
            
        VectorP.push_back(x);
        VectorC.push_back(y);
        VectorF.push_back(z);
            
    }
        
    
    
    
}

bool recursiva(vector<int>Arreglo, int valor){
    
    int sum = Arreglo[0];
    
    if (sum == valor) {
        return true;
    }else{
        
    
        for (int i = 1; i<Arreglo.size(); i++) {
            
            //empiezo en la posicion uno... y
            
            int resul = sum + Arreglo[i];
            
            if (resul == valor) {
                return true;
            }
            if (resul < valor) {
                
                sum = resul;
                
            }
            if (resul > valor) {
                
                //NADA...
            }
            
        }
        
        //si llego hasta este punto quiere decir que no encontro el valor y que hay que iterar:
        
        //pasar el primer elemento al final;
        
        int first = Arreglo[0];
        
        Arreglo.erase(Arreglo.begin());
        
        //meter el primer elemento al final :c
        Arreglo.push_back(first);
        
        
        cout<<"TAM: "<<Arreglo.size();
        //imprimir para verificar
        for (int i = 0; i<Arreglo.size(); i++) {
            cout<<Arreglo[i]<<"  ";
        }
        
        //llamar de nuevo la recursividad;
        
        
    
    
    }


    
    return false;
}

void Procesa(){

    //ORDENAR:
    sort(VectorP.begin(), VectorP.end());
    sort(VectorC.begin(), VectorC.end());
    sort(VectorF.begin(), VectorF.end());

    
    if (recursiva(VectorP,GP)) {
    
        
    }
    
    
    
}

void Imprimir(){

    for (int i = 0; i<VectorP.size(); i++) {
        
        cout<<VectorP[i]<<" "<<VectorC[i]<<"  "<<VectorF[i]<<endl;
        
    }
    
    
}

int main(int argc, const char * argv[]) {

    
    cin>>Casos;
    
    while (Casos--) {
    
        Leer();
        Procesa();
        //Imprimir();
        
        
    }

    
    
}
