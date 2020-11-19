//
//  main.cpp
//  Sumando
//
//  Created by Jose De Jesus Garfias Lopez on 03/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    
    int Tam;
    
    cin>>Tam;
    
    int Matriz[Tam][Tam];
    
    int Tama=Tam*Tam;
    int Arreglo[Tama];
    
    for (int i=0; i<Tam; i++) {
    
        for (int j=0; j<Tam; j++) {
            
            cin>>Matriz[i][j];
        }
    }
    
    int indice=0;
    
    for (int j=0; j<Tam; j++) {
        
        for (int i=Tam-1; i>=0; i--) {
            
            Arreglo[indice] = Matriz[i][j];
            indice++;
        }
    }
    
    int contador=0;
    for (int i=0; i<Tama; i++) {
        
        if (contador==Tam-1) {
            
            contador=0;
            cout<<Arreglo[i]<<endl;
            
        }else{
            
            cout<<Arreglo[i]<<" ";
            contador++;

            
        }

    }
    
    
    return 0;
}
