#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void Calcular(double* Array, int Tam, double t){
    
    if(t >= -1 && t <= 2){
        
        if(t != 1){
            
            
        }else{
            cout<<"La t presenta singularidad"<<endl;
        }
        
    
    }else if(t >= 3 && t<= 8){

        if(t != 5){
            
            
            
        }else{
            cout<<"La t presenta singularidad"<<endl;
        }
    
    }else{
        cout<<"t no se encuentra en los rangos establecidos."<<endl;
    }
    
}

void LecturaArray(double* Array, int Tam){
    for (int i=0;i<Tam;i++){
        cout<<"Valor "<<i+1<<": ";
        cin>>Array[i];
    }
}

int main() {
    
    char seleccion;
    do {
        
        int Tam;
        double t;
        double* Array = new double[Tam];
        
        cout<<"Numero de valores (m): ";
        cin>>Tam;
        
        LecturaArray(Array, Tam);
        
        cout<<"Ingrese el valor de (t): ";
        cin>>t;
        
        Calcular(Array,Tam,t);
        
        delete Array;
        
        cout<<"Desea realizar otra operacion? (S/N): "<<endl;
    } while (seleccion == 'S' || seleccion == 's');
    
    return 0;
}
