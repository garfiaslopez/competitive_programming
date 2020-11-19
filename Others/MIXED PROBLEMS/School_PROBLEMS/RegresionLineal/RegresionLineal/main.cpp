//
//  main.cpp
//  RegresionLineal
//
//  Created by Jose De Jesus Garfias Lopez on 01/07/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>      // std::setw

using namespace std;



class RegLineal{
private:
    
    int Tam;
    double A1, A0, Y, X, SumX, SumY, SumX2, SumXY;
    vector<double>ArregloX;
    vector<double>ArregloY;
    vector<double>ArregloX2;
    vector<double>ArregloXY;
public:
    void Leer();
    void Calcular();
    void Imprimir();
    double CalcularY(double X);
    
};


void RegLineal::Leer(){
    
    cout<<"Cuantas XY's vas a ingresar? "<<endl;
    cin>>Tam;
    
    for (int i = 0 ; i<Tam; i++) {
        
        double ValueX,ValueY;
        
        cout<<"Valor X"<<i+1<<": ";
        cin>>ValueX;
        
        ArregloX.push_back(ValueX);

        cout<<"Valor Y"<<i+1<<": ";
        cin>>ValueY;
        
        ArregloY.push_back(ValueY);

    }
    
}

void RegLineal::Calcular(){
     
    SumY=0.0;
    SumX=0.0;
    SumX2=0.0;
    SumXY=0.0;
    
    //Calculando SUMX  SUMY
    for (int i=0; i<Tam; i++) {
        
        SumX = SumX + ArregloX[i];
        SumY = SumY + ArregloY[i];
        
        //Calculando X^2
        ArregloX2.push_back(ArregloX[i]*ArregloX[i]);
        
        SumX2 = SumX2 + ArregloX2[i];
        
        //Calculanfo X.Y
        ArregloXY.push_back(ArregloX[i]*ArregloY[i]);
        
        SumXY = SumXY + ArregloXY[i];
    }
    
    X = SumX / Tam;
    Y = SumY / Tam;
    
    A1 = ((Tam*SumXY)-(SumX*SumY) ) / ( (Tam*SumX2) - (SumX*SumX) );
    A0 = Y - (A1 * X);
    
}

double RegLineal::CalcularY(double X){
       return A0 + (A1*X);       
}

void RegLineal::Imprimir(){
    

    cout<<"RESULTADOS EN TABLA: "<<endl<<endl;
    
    cout<<"X"<<std::setw(10)
        <<"Y"<<std::setw(10)
        <<"X^2"<<std::setw(10)
        <<"X*Y"<<endl<<endl;
    
    for (int i=0; i<Tam; i++) {

        cout<<ArregloX[i]<<std::setw(10)
            <<ArregloY[i]<<std::setw(10)
            <<ArregloX2[i]<<std::setw(10)
            <<ArregloXY[i]<<endl;
    }
    
    cout<<endl<<"RESULTADOS: "<<endl<<endl;
    
    cout<<"N:        "<<Tam<<endl
        <<"X:        "<<X<<endl
        <<"Y:        "<<Y<<endl
        <<"SUM X:    "<<SumX<<endl
        <<"SUM Y:    "<<SumY<<endl
        <<"SUM X^2:  "<<SumX2<<endl
        <<"SUM X*Y:  "<<SumXY<<endl
        <<"A1:       "<<A1<<endl
        <<"A0:       "<<A0<<endl
        <<"Y = "<<A0<<"  +  "<<A1<<" X "<<endl<<endl;
    
}


int main(int argc, const char * argv[]) {
    
    cout<<"Programa Regresion Lineal"<<endl;
    
    RegLineal Obj;
    
    Obj.Leer();
    Obj.Calcular();
    Obj.Imprimir();
    
    double x;
    cout<<"Ingrese El Valor De X:";
    cin>>x;
    
    cout<<" Y = "<<Obj.CalcularY(x)<<endl<<endl;
    
    
    
    
    system("pause");
    return 0;
}
