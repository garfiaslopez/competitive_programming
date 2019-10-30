//
//  main.cpp
//  MetodosNumericos
//
//  Created by Jose De Jesus Garfias Lopez on 25/06/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<string> Functions_List;
vector<string> Methods_List;

void Initizalize(){

    //Para Agregar una nueva funcion o metodo.... se tiene que registrar en los vectores,
    //Crear su Clase, y Agregarlo AL SWITCH correspondiente.

    //Agrega las funciones disponibles:
    Functions_List.push_back("1.- log(X ^2).");
    Functions_List.push_back("2.- (X^2) -3.");
    Functions_List.push_back("3.- log(X^2).");
    Functions_List.push_back("4.- (X^2) -3.");
    Functions_List.push_back("5.- log(X^2).");


    //Agrega los metodos disponibles:
    Methods_List.push_back("1.- Biseccion.");
    Methods_List.push_back("2.- Regla Falsa.");
    Methods_List.push_back("3.- Newton-Raphson.");
    Methods_List.push_back("4.- Secante.");

}


//Funcion que retorna el valor de algun tipo de funcion especificada y tambien su derivada en caso de requerirla:
double Function(bool isDerivate,int type,double X){

    switch (type) {

        case 1:

            if(!isDerivate){
                return log(X*X);
            }else{
                return log(X);
            }

            break;


        case 2:

            if(!isDerivate){
                return (X*X) - 3;
            }else{
                return 2 * X;
            }
            break;


        default:
            break;
    }

    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//CLASES DE LOS METODOS:
////////////////////////////////////////////////////////////////////////////////////////////////////


class Biseccion {

private:

    int FunctionType;
    float Ed,Xi,Xs;
    int IterMax;

public:
    void Read();
    void DoMagic();
    void SetFunctionType(int type);

};
void Biseccion::Read(){
    cout<<"Lectura de datos: [Biseccion] :"<<endl<<endl;

    cout<<"Ingrese valor Incial (Xi): "<<endl;
    cin>>Xi;
    cout<<"Ingrese valor Final (Xs): "<<endl;
    cin>>Xs;
    cout<<"Ingrese el error deseado (Ed) :"<<endl;
    cin>>Ed;

}
void Biseccion::DoMagic(){

    float Ea,Xm,Fm,Fi;
    int Iter = 0;

    Fi = Function(false,FunctionType,Xi);

    while( Ed<Ea || Iter < IterMax){

        cout<<endl<<"Iteracion: "<<Iter<<endl;
        Iter++;

        cout<<"Xi : "<<Xi<<endl;
        cout<<"Xs : "<<Xs<<endl;
        float Xant = Xm;
        Xm = (Xi+Xs)/2;
        cout<<"Xm: "<<Xm<<endl;

        Fm = Function(false,FunctionType,Xm);

        cout<<"F(Xi): "<<Fi<<endl;
        cout<<"F(Xm): "<<Fm<<endl;
        cout<<"F(Xm): "<<Fm<<endl;

        if(Xi != 0){
            Ea = fabs(((Xm-Xant)/Xm) *100 );
            cout<<"Ea: "<<Ea<<endl;

        }
        float Prueba = Fi * Fm ;

        if(Prueba < 0){
            Xs=Xm;
        }else if(Prueba > 0){
            Xi=Xm;
            Fi=Fm;
        }else{
            Ea=0;
        }

    }

    cout<<"Resultado: "<<Xm<<endl;

}


void Biseccion::SetFunctionType(int type){
    FunctionType = type;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTIONS:
////////////////////////////////////////////////////////////////////////////////////////////////////

int DoFunctionMenu(){

    int selection = 0;

    while (selection <=0 || selection > Functions_List.size()){

        cout<<"Elija La Funcion Que Desee Calcular: "<<endl;

        for (int i = 0; i<Functions_List.size(); i++) {
            cout<<Functions_List[i]<<endl;
        }

        cin>>selection;
    }
    return selection;
}


int DoMethodMenu(){

    int selection = 0;

    while (selection <=0  || selection > Methods_List.size()){

        cout<<"Elija El Metodo Que Desea Implementar: "<<endl;

        for (int i = 0; i<Methods_List.size(); i++) {
            cout<<Methods_List[i]<<endl;
        }

        cin>>selection;
    }
    return selection;
}


void DoMethod(int FType, int Method){

    switch (Method) {

        case 1:

            //BISECCION:
            Biseccion Bis;
            Bis.SetFunctionType(FType);
            Bis.Read();
            Bis.DoMagic();

            break;

    }


}



int main(int argc, const char * argv[]) {

    //Inicializar los vectores:
    Initizalize();

    cout<<"Programa que calcular raices con diferentes metodos numericos: "<<endl<<endl;

    char end;
    do{
        char next;

        int FunctionType = DoFunctionMenu();

        do{

            int MethodType = DoMethodMenu();

            DoMethod(FunctionType, MethodType);

            cout<<"Desea Seleccionar Otro Metodo? (s/n)"<<endl;
            cin>>next;

        }while (next == 's' || next == 'S');

        cout<<"Desea Seleccionar Otra Funcion? (s/n)"<<endl;
        cin>>end;

    }while (end == 's' || end == 'S');


    cout<<"GoodBye"<<endl;
    return 0;
}
