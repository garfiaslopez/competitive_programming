//
//  main.cpp
//  Equipos
//
//  Created by Jose De Jesus Garfias Lopez & Fernando Jimenez Vaca on 20/01/15.
//
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace::std;

struct Equipo{

    string Nombre;
    int Victorias;
    int Derrotas;
    
    void LeerEquipo(){
        cout<<"Nombre del equipo: ";
        cin>>Nombre;
        cout<<"Numero de victorias: ";
        cin>>Victorias;
        cout<<"Numero de derrotas: ";
        cin>>Derrotas;
        
    }
    
};

struct Baloncesto{
    struct Equipo Team;
    int PerdBalon;
    int ReboCog;
    string NomAnoTri;
    int NumAnoTri;
    
    void LeerBaloncesto(){
        
        Team.LeerEquipo();
        
        cout<<"Numero de perdidas de balon: ";
        cin>>PerdBalon;
        cout<<"Numero de rebotes cogidos: ";
        cin>>ReboCog;
        cout<<"Nombre del mejor anotador de triples: ";
        cin>>NomAnoTri;
        cout<<"Numero de triples del mejor anotador: ";
        cin>>NumAnoTri;
        
    }
};

struct Futbol{
    
    struct Equipo Team;
    int Empates;
    int GolesFav;
    string NomGoleador;
    int NumGoleador;
    
    void LeerFutbol(){
        
        Team.LeerEquipo();
        
        cout<<"Numero de empates: ";
        cin>>Empates;
        cout<<"Numero de goles a favor: ";
        cin>>GolesFav;
        cout<<"Numero del goleador del equipo: ";
        cin>>NomGoleador;
        cout<<"Numero de goles del goleador: ";
        cin>>NumGoleador;
        
    }
};

vector<Futbol>LigaFutbol;
vector<Baloncesto>LigaBaloncesto;


int main(int argc, const char * argv[]) {

    
    int InteFutbol;
    int InteBalonc;
    
    struct Futbol  EquipoFut;
    struct Baloncesto EquipoBalonc;
    
    cout<<"Numero de integrantes en la liga de futbol: ";
    cin>>InteFutbol;
    cout<<"Numero de integrantes en la liga de Baloncesto: ";
    cin>>InteBalonc;
    
    for (int i = 0; i<InteFutbol; i++) {
        
        EquipoFut.LeerFutbol();
        LigaFutbol.push_back(EquipoFut);
    }
    
    for (int i =0; i<InteBalonc; i++) {
        
        EquipoBalonc.LeerBaloncesto();
        LigaBaloncesto.push_back(EquipoBalonc);
    }
    return 0;
}