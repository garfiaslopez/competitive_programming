//
//  main.cpp
//  Programa6_ETSFundamentos
//
//  Created by Jose De Jesus Garfias Lopez on 14/03/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void LeerArreglos(int *A ,int *B,int m,int n){

    cout<<"Lectura del primer Arreglo: "<<endl;
    for (int i = 0; i<m; i++) {
        cin>>A[i];
    }
    
    cout<<"Lectura del Segundo Arreglo: "<<endl;
    for (int i = 0; i<n; i++) {
        cin>>B[i];
    }

}

void Combinar(int *A, int *B, int *C,int m, int n){
    
    int indice = 0;
    int indB=0;
    
    //Recorro sobre A
    for (int i = 0; i<m; i++) {
        
        
        while (B[indB] < A[i] && indB < n) {
            
            C[indice] = B[indB];
            indice++;
            indB++;
            
        }
        
        C[indice] = A[i];
        indice++;
    }

}

void Imprimir(int *C,int m, int n){
    
    cout<<"Arreglo Combinado:"<<endl;
    for ( int i = 0; i< (m+n); i++) {
        cout<<C[i]<<"   ";
    }
}

int main() {
    
    int m,n;
    
    cout<<"Tam Primer Arreglo: ";
    cin>>m;
    cout<<"Tam Segundo Arreglo: ";
    cin>>n;
    
    int* ArregloA = new int [m];
    int* ArregloB = new int [n];
    int* ArregloC = new int [m+n];
    
    LeerArreglos(ArregloA, ArregloB,m,n);
    if (m>=n) {
        Combinar(ArregloA,ArregloB,ArregloC,m,n);
    }else{
        Combinar(ArregloB,ArregloA,ArregloC,n,m);
    }
    Imprimir(ArregloC,m,n);
    
    
    return 0;
}
