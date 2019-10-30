//
//  main.cpp
//  Matrices
//
//  Created by Jose De Jesus Garfias Lopez on 25/02/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;

struct Matriz
{
    int Filas;
    int Columnas;
    
    double ** AptMatriz;
};


Matriz* operator +(Matriz M1, Matriz*AptM2);
Matriz* operator -(Matriz M1, Matriz*AptM2);
Matriz* operator /(Matriz M1, Matriz*AptM2);
Matriz* operator *(Matriz M1, Matriz*AptM2);


void leer(int &RefFilas, int &RefColumnas);
void Inicializar(const int Filas, const int Columnas, Matriz* AptM);
void leerMatriz(Matriz* AptM);
void Imprimir(Matriz* AptM);


double Mayor(const Matriz*AptM);
void Normalizar(Matriz* AptM, const double Mayor);
Matriz* Invertir(Matriz* AptM);
void Librerar(Matriz* AptM);


int main()
{
    
    int Filas;
    int Columnas;
    int Filas2;
    int Columnas2;
    
    double MayorResultado;
    
    Matriz M1;
    
    Matriz* AptM;
    AptM = new Matriz;
    
    Matriz* AptMR;
    AptMR = new Matriz;
    
    
    bool bandera = false;
    int seleccion=0;
    
    do {
        
        cout<<"¿QUE DESEA REALIZAR?"<<endl
        <<"1.- SUMAR"<<endl
        <<"2.- RESTAR"<<endl
        <<"3.- DIVIDIR"<<endl
        <<"4.- MULTIPLICAR"<<endl
        <<"5.- INVERSA (GAUSS)"<<endl;
        
        cin>>seleccion;
        
        //Pedir e inicializar dependiendo si se requiere una o dos matrices:
        
        if(seleccion == 1 || seleccion == 2 || seleccion == 3 || seleccion == 4){
            
            cout<<"LECTURA DE FILAS COLUMNAS DE PRIMERA MATRIZ: "<<endl;
            leer(Filas, Columnas);
            
            cout<<"LECTURA DE FILAS COLUMNAS DE SEGUNDA MATRIZ: "<<endl;
            leer(Filas2, Columnas2);
            
            Inicializar(Filas, Columnas, &M1);
            Inicializar(Filas2, Columnas2, AptM);
            
        }else if(seleccion == 5){
            
            cout<<"LECTURA DE FILAS COLUMNAS DE PRIMERA MATRIZ: "<<endl;
            leer(Filas, Columnas);
            
            
        }else{
            cout<<"Seleccion invalida"<<endl;
        }
        
        switch (seleccion) {
            case 1:
                
                if (M1.Filas == AptM->Filas && M1.Columnas == AptM->Columnas) {
                    
                    Inicializar(M1.Filas, M1.Columnas, AptMR);
                    leerMatriz(&M1);
                    leerMatriz(AptM);
                    AptMR = M1 + AptM;
                    
                    bandera = true;
                }
                else
                    cout<<"LA SUMA DE SUS MATRICES NO PUEDE REALIZARSE"<<endl<<endl;
                
                break;
            case 2:
                
                if (M1.Filas == AptM->Filas && M1.Columnas == AptM->Columnas) {
                    
                    Inicializar(M1.Filas, M1.Columnas, AptMR);
                    leerMatriz(&M1);
                    leerMatriz(AptM);
                    AptMR = M1 - AptM;
                    
                    bandera = true;
                }
                else
                    cout<<"LA RESTA DE SUS MATRICES NO PUEDE REALIZARSE"<<endl<<endl;
                
                break;
            case 3:
                
                if (M1.Filas == AptM->Filas && M1.Columnas == AptM->Columnas) {
                    
                    Inicializar(M1.Filas, M1.Columnas, AptMR);
                    leerMatriz(&M1);
                    leerMatriz(AptM);
                    AptMR = M1 / AptM;
                    
                    bandera = true;
                    
                }
                else
                    cout<<"LA DIVICION DE SUS MATRICES NO PUEDE REALIZARSE"<<endl<<endl;
                
                break;
            case 4:
                
                Inicializar(Filas2, Columnas, AptMR);
                
                leerMatriz(&M1);
                leerMatriz(AptM);
                
                AptMR = M1*AptM;
                bandera = true;
                
                break;
            case 5:
                
                Inicializar(Filas, Columnas, AptM);
                leerMatriz(AptM);
                
                AptMR = Invertir(AptM);
                bandera = true;
                
                break;
            default:
                break;
        }
        
    } while (bandera == false);
    
    
    Imprimir(AptMR);
    
    
    /*
     cout<<endl<<"Despues de Normalizar"<<endl;
     
     MayorResultado = Mayor(AptMR);
     
     cout<<"Numero mas grande:   "<<MayorResultado<<endl;
     
     Normalizar(AptMR, MayorResultado);
     
     Imprimir(AptMR);
     */
}



void leer(int &RefFilas, int &RefColumnas)
{
    
    cout<<"Dame las filas de tu Matriz: ";
    cin>>RefFilas;
    
    cout<<"Dame las Columnas de tu Matriz: ";
    cin>>RefColumnas;
    
    cout<<endl;
    
}


void Inicializar(const int Filas, const int Columnas, Matriz* AptM)
{
    AptM->Filas = Filas;
    AptM->Columnas = Columnas;
    AptM -> AptMatriz = new double* [AptM -> Filas] ;
    
    for( int i = 0; i < AptM -> Filas; i++)
    {
        AptM -> AptMatriz[i] =  new double [ AptM -> Columnas];
    }
}



void leerMatriz(Matriz* AptM)
{
    cout<<"Ingrese los numeros de su matriz"<<endl;
    
    for (int i =0; i<AptM->Filas; i++) {
        for (int j=0; j<AptM->Columnas; j++) {
            cin>>AptM->AptMatriz[i][j];
        }
    }
    cout<<endl<<"Lectura Finalizada"<<endl;
    
}

void Imprimir(Matriz* AptM){
    
    cout<<endl;
    
    for (int i =0; i<AptM->Filas; i++) {
        for (int j=0; j<AptM->Columnas; j++) {
            cout<<setw(9)<<AptM->AptMatriz[i][j];
        }
        cout<<endl;
    }
}


Matriz* operator +(Matriz M1, Matriz*AptM2)
{
    Matriz* AptMTmp = new Matriz;
    Inicializar(M1.Filas, M1.Columnas, AptMTmp);
    
    for (int i = 0; i<AptM2->Filas; i++)
    {
        for (int j=0; j<AptM2->Columnas; j++) {
            AptMTmp->AptMatriz[i][j] = M1.AptMatriz[i][j] + AptM2->AptMatriz[i][j];
        }
    }
    
    return AptMTmp;
    
}


double Mayor(const Matriz*AptM)
{
    double Resultado = fabs(AptM->AptMatriz[0][0]);
    
    for (int i =0; i<AptM->Filas; i++)
    {
        for (int j=0; j<AptM->Columnas; j++)
        {
            
            if (fabs(AptM->AptMatriz[i][j]>Resultado))
            {
                Resultado = fabs(AptM->AptMatriz[i][j]);
            }
            
        }
    }
    return Resultado;
}


void Normalizar(Matriz* AptM, const double Mayor)
{
    for (int i =0; i<AptM->Filas; i++)
    {
        for (int j=0; j<AptM->Columnas; j++)
        {
            AptM->AptMatriz[i][j] = AptM->AptMatriz[i][j]/Mayor;
        }
    }
}


Matriz* Invertir(Matriz* AptM){
    
    // Algoritmo para la eliminación simple de Gauss
    int i, j, k;
    
    int n = AptM->Filas;
    double **a = AptM->AptMatriz;
    double determ;
    double **MatrizInv;
    
    //Se reserva memoria para la matriz que se va a regresar.
    MatrizInv = new double* [n];
    for (int i=0; i<n; i++) {
        MatrizInv[i] = new double[n];
    }
    
    double factor;
    
    double **L, *D, *X;
    
    X = new double [n]; D = new double [n];
    
    L = new double* [n];
    
    for (j = 0; j < n; j++)
        
        L[j] = new double [n];
    
    for (k = 0; k < n - 1; k++) {
        
        for (i = k+1; i < n;  i++) {
            factor = a[i][k]/a[k][k];
            for (j = k+1; j < n + 1; j++) {
                a[i][j] = a[i][j] - factor * a[k][j];
            }
        }
    }
    
    // Cálculo del determinante
    determ = 1.;
    for (i = 0; i < n; i++) {
        
        determ = determ * a[i][i];
    }
    if (determ != 0) {
        
        // Rutina para determinar las matrices L (inferior) y U (superior) de la
        // descomposición LU
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i > j) {
                    L[i][j] = a[i][j]/a[j][j];
                    a[i][j] = 0;
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                L[j][j] = 1;
            }
        }
        // Implementación de la rutina para el cálculo de la inversa
        for (k = 0; k < n; k++) {
            // Esta rutina inicializa los L[i][n] para ser utilizados con la matriz L
            for (i = 0; i < n; i++) {
                if (i == k) L[i][n] = 1;
                else  L[i][n] = 0;
            }
            // Esta función implementa la sustitución hacia adelante con la matriz L y los L[i][n]
            // que produce la rutina anterior
            double sum;
            D[0] = L[0][n];
            for (i = 1; i < n; i++) {
                sum = 0;
                for (j = 0; j < i; j++) {
                    sum = sum + L[i][j]*D[j];
                }
                D[i] = L[i][n] - sum;
            }
            // Esta rutina asigna los D[i] que produce forward para ser utilizados con la matriz U
            for (i = 0; i < n; i++) {
                a[i][n] = D[i];
            }
            // Rutina que aplica la sustitución hacia atras
            X[n-1] = a[n-1][n]/a[n-1][n-1];
            // Determinación de las raíces restantes
            for (i = n - 2; i > -1; i--) {
                sum = 0;
                for (j = i+1; j < n; j++) {
                    sum = sum + a[i][j]*X[j];
                }
                X[i] = (a[i][n] - sum)/a[i][i];
            }
            // Esta rutina asigna los X[i] que produce Sustituir como los elementos de la matriz inversa
            for (i = 0; i < n; i++) {
                MatrizInv[i][k] = X[i];
            }
        }   // llave de cierre del for para k
    }   // cierre del if
    //Se crea el objeto matriz y se regresa
    Matriz* AptMatrizInv;
    AptMatrizInv = new Matriz;
    
    AptMatrizInv->AptMatriz = MatrizInv;
    AptMatrizInv->Filas = n;
    AptMatrizInv->Columnas = n;
    
    return AptMatrizInv;
}

void Librerar(Matriz* AptM){
    
}


Matriz* operator -(Matriz M1, Matriz*AptM2)
{
    
    Matriz* AptMTmp = new Matriz;
    Inicializar(M1.Filas, M1.Columnas, AptMTmp);
    
    
    for (int i = 0; i<AptM2->Filas; i++)
    {
        for (int j=0; j<AptM2->Columnas; j++) {
            AptMTmp->AptMatriz[i][j] = M1.AptMatriz[i][j] - AptM2->AptMatriz[i][j];
        }
    }
    return AptMTmp;
}


Matriz* operator /(Matriz M1, Matriz*AptM2)
{
    Matriz* AptMTmp = new Matriz;
    Inicializar(M1.Filas, M1.Columnas, AptMTmp);
    
    for (int i = 0; i<AptM2->Filas; i++)
    {
        for (int j=0; j<AptM2->Columnas; j++) {
            AptMTmp->AptMatriz[i][j] = M1.AptMatriz[i][j] / AptM2->AptMatriz[i][j];
        }
    }
    return AptMTmp;
}




Matriz* operator *(Matriz M1, Matriz*AptM2)
{
    double SumaTmp=0;
    
    Matriz* AptMTmp = new Matriz;
    Inicializar(M1.Filas, M1.Columnas, AptMTmp);
    
    for (int a=0; a<M1.Filas; a++) {
        for (int b=0; b<AptM2->Columnas; b++) {
            for (int c=0; c<M1.Columnas; c++) {
                SumaTmp = SumaTmp + M1.AptMatriz[a][c] * AptM2->AptMatriz[c][b];
            }
            AptMTmp->AptMatriz[a][b] = SumaTmp;
            SumaTmp =0;
        }
    }
    return AptMTmp;
}




