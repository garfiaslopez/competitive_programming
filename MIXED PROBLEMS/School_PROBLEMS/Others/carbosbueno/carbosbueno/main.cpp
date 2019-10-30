//
//  main.cpp
//  carbohidratos
//
//  Created by Jose De Jesus Garfias Lopez on 09/01/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <vector>
 #include<algorithm>
using namespace std;

vector<int>VectorP;
vector<int>VectorC;
vector<int>VectorF;


bool Encontrado = false;
int Casos, Foods,GP,GC,GF,casoscopy;

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


bool recursiva(vector<int>Arreglo, int valor,int veces){
    
    
    cout<<"ENTRO A RECURSIVA:"<<endl;
    //imprimir para verificar
    
    
    for (int i = 0; i<Arreglo.size(); i++) {
        cout<<Arreglo[i]<<"  ";
    }
    cout<<endl;
    
    
    
    int sum = Arreglo[0];
    
    if (sum == valor) {
        return true;
    }else{
        
        cout<<"ENTRO A NO EL PRIMER ELEMENTO NO ES VALOR :"<<endl;
        
        for (int i = 1; i<Arreglo.size(); i++) {
            
            //empiezo en la posicion uno... y
            
            int resul = sum + Arreglo[i];
            
            if (resul == valor) {
                return true;
            }
            
            if (resul < valor) {
                
                sum = resul;
                
                //BUSQUEDA DE SUM CONTRA TODO LO QUE QUEDA DEL ARREGLO:
                
                for (int j = i+1; j<Arreglo.size(); j++) {
                    
                    if (sum + Arreglo[j] == valor) {

                        return true;
                    }
                    
                }
                
            }
            if (resul > valor) {
                
                //NADA...
            }
            
        }
        
        //si llego hasta este punto quiere decir que no encontro el valor y que hay que iterar:
        
        //pasar el primer elemento al final;
        
        /*
        int first = Arreglo[0];
        
        Arreglo.erase(Arreglo.begin());
        
        //meter el primer elemento al final :c
        Arreglo.push_back(first);
        */
        next_permutation(Arreglo.begin(), Arreglo.end());
       
        
        if(recursiva(Arreglo,valor,veces)){
            return true;
        }
        
        /*
        //llamar de nuevo la recursividad;
        veces++;
        cout<<"VECES: "<<veces<<endl;
        if (veces == Arreglo.size()) {
            return false;
        }else{
            

            
        }
        */
        
        
    }
    
    cout<<"ESTA RETORNANDO EL FALSE?"<<endl;
    
    return false;
}

void Procesa(){
    
    //ORDENAR:
    sort(VectorP.begin(), VectorP.end());
    sort(VectorC.begin(), VectorC.end());
    sort(VectorF.begin(), VectorF.end());
    
    
    
    if (recursiva(VectorP, GP, 0)) {
        
        cout<<"PASO EL PRIMEROP"<<endl;
        
        
        if (recursiva(VectorC, GC, 0)) {
            
            cout<<"PASO EL SEGUNDOC"<<endl;
            
            if (recursiva(VectorF, GF, 0)) {
                
                cout<<"PASO EL TERCEROF"<<endl;
                cout<<"Case #"<<casoscopy-Casos<<": yes";
                
                
                
                
            }
            
            
            
        }
        
        
        
        
    }
    
    
    cout<<"TERMINO EL CASO:"<<endl;
    
    //clean all data;
    
    VectorP.clear();
    VectorC.clear();
    VectorF.clear();
    
}

void Imprimir(){
    
    for (int i = 0; i<VectorP.size(); i++) {
        
        cout<<VectorP[i]<<" "<<VectorC[i]<<"  "<<VectorF[i]<<endl;
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    
    cin>>Casos;
    casoscopy = Casos;
    
    while (Casos--) {
        
        Leer();
        Procesa();
        //Imprimir();
        
        
    }
    
    
    
}
