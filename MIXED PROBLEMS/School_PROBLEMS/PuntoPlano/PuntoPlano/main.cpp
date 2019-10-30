//
//  main.cpp
//  PuntoPlano
//
//  Created by Jose De Jesus Garfias Lopez & Fernando Jimenez Vaca on 20/01/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

struct Punto{
    float X;
    float Y;
    
    void LeerPunto(){
        cout<<"Coordenada X:";
        cin>>X;
        cout<<"Coordenada Y:";
        cin>>Y;
        
    }
};

float Distancia(struct Punto Point1, struct Punto Point2){
    
    return sqrt( pow((Point2.X - Point1.X), 2) + (pow((Point2.Y - Point1.Y), 2)) );
    
};

string EcuacionRecta(struct Punto Point1, struct Punto Point2){

    if (Point1.X == Point2.X) {
         return "X=" + to_string(Point1.X);
    }else if (Point1.Y == Point2.Y){
        
        return "Y=" + to_string(Point1.Y);
    }else{
        float m = (Point2.Y - Point1.Y) / (Point2.X - Point1.X);
        
        return "Y=" + to_string(m) + " X+(" + to_string( -m*Point1.X+Point1.Y) + ")";
        
    }
    
    return "No existe ecuacion de la recta.";
};






float AreaTriangulo(struct Punto Point1, struct Punto Point2, struct Punto Point3){

    float AB = Distancia(Point1, Point2);
    float BC = Distancia( Point2, Point3);
    float CA = Distancia(Point3, Point1);
    float p = (AB + BC + CA)/2;
    
    return sqrt( ( p * (p - AB) * (p - BC) * (p-CA)) );
    
};

int main(int argc, const char * argv[]) {
    
    struct Punto P1;
    struct Punto P2;
    struct Punto P3;
    
    float dist;
    string EcRecta;
    float AreaT;

    cout<<"Lectura primer punto :"<<endl;
    P1.LeerPunto();
    
    cout<<"Lectura Segundo punto :"<<endl;
    P2.LeerPunto();
    
    cout<<"Lectura Tercer punto :"<<endl;
    P3.LeerPunto();
    
    dist = Distancia(P1, P2);
    EcRecta = EcuacionRecta(P1, P2);
    AreaT = AreaTriangulo(P1, P2, P3);

    cout<<"Distancia entre P1 y P2: "<<dist<<endl;
    cout<<"La ecuacion de la recta entre P1 y P2 es: "<<EcRecta<<endl;
    cout<<"El area del traingulo dado P1,P2 y P3 es:"<<AreaT<<endl;
    
    
}
