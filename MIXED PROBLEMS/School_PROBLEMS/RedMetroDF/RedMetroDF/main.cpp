//
//  main.cpp
//  RedMetroDF
//
//
//
//
#include <iostream>
#include <stdlib.h>     /* atoi */
#include <map>
#include <queue>
#include <vector>
#include <fstream>
#include <stack>
#define MAX 200
#define INF 1<<30

using namespace std;

//Definicion de estructura
typedef struct{
    int v,p;
}Nodo;

//Sobrecarga del operador
bool operator < (Nodo a, Nodo b){
    return a.p > b.p;
}

//Lista Adyacente:
vector<Nodo> Ady[MAX];

//Mapa de lineas del metro
map<string, int> MetrosMap;

//Camino de estaciones:
stack<string> Camino;

string Inicio;
string Final;

bool CargarRedesMetro(string Ruta){
    
    int Contador = 0;
    if (!MetrosMap.empty()) {
        MetrosMap.clear();
    }
    ifstream fileRead(Ruta.c_str(),ios_base::in);
    
    if (fileRead.good()) {
        while (!fileRead.eof()) {
            
            string Cadena;
            fileRead>>Cadena;
            
            string EstacionA,EstacionB;
            
            EstacionA = Cadena.substr(0,Cadena.find('-'));
            Cadena.erase(0,Cadena.find('-')+1);
            
            EstacionB = Cadena.substr(0,Cadena.find('='));
            Cadena.erase(0,Cadena.find('=')+1);
            
            Cadena.clear();
            
            if ( !MetrosMap.count(EstacionA) ) {
                MetrosMap[EstacionA] = Contador;
                Contador++;
            }
            if ( !MetrosMap.count(EstacionB)) {
                MetrosMap[EstacionB] = Contador;
                Contador++;
            }
        }
    }else{
        cout<<"Ocurrio un error al abrir su archivo."<<endl;
        return 0;
    }
    
    return 1;
}

void RellenarListaAdyacencia(string Ruta){
    
    ifstream fileRead(Ruta.c_str(),ios_base::in);
    
    Nodo Estacion;
    
    if (fileRead.good()) {
        
        while (!fileRead.eof()) {
            
            string Cadena;
            fileRead>>Cadena;
            
            string EstacionA,EstacionB,Dis;
            int Distancia;
            
            EstacionA = Cadena.substr(0,Cadena.find('-'));
            Cadena.erase(0,Cadena.find('-')+1);
            
            EstacionB = Cadena.substr(0,Cadena.find('='));
            Cadena.erase(0,Cadena.find('=')+1);
            
            Dis = Cadena.substr(0,Cadena.find('\n'));
            Cadena.erase(0,Cadena.find('\n')+1);
            
            Distancia = atoi( Dis.c_str() );
            
            Cadena.clear();
            
            //Insertar los valores en la Lista de Adyacencia:
            int u,v;
            
            u=MetrosMap.find(EstacionA)->second;
            v=MetrosMap.find(EstacionB)->second;
            
            Estacion.v=v;
            Estacion.p=Distancia;
            Ady[u].push_back(Estacion);
            
            Estacion.v=u;
            Ady[v].push_back(Estacion);
            
        }
    }else{
        cout<<"Ocurrio un error al abrir su archivo."<<endl;
    }
}


void BuscarRuta(int inicial, int fin){
    
    bool vis[MAX];
    int dis[MAX];
    int cam[MAX];
    int u,v,p;
    priority_queue <Nodo> Q;
    Nodo x = {inicial,0};
    Q.push(x);
    for(int i=0;i<MAX;i++) {
        dis[i]=INF;
        vis[i]=false;
    }
    dis[inicial]=0;
    while(!Q.empty()) {
        x = Q.top();
        Q.pop();
        u=x.v;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0;i<Ady[u].size();i++) {
            v=Ady[u][i].v;
            p=Ady[u][i].p;
            if(!vis[v]) {
                if(dis[u]+p<dis[v]) {
                    //paso de relajacion
                    dis[v]=dis[u]+p;
                    cam[v]=u;
                    Nodo tmp = {v,dis[v]};
                    Q.push(tmp);
                }
            }
        }
        
    }
    
    cout<<"Recorrido: "<< dis[fin]<<" Metros."<<endl;
    
    int A = cam[fin];
    
    Camino.push(Final);
    
    while (A != inicial) {
        
        map<string,int>::const_iterator it;
        for (it = MetrosMap.begin(); it != MetrosMap.end(); ++it)
        {
            if (it->second == A)
            {
                Camino.push(it->first);
                break;
            }
        }
        
        A=cam[A];
        
    }
    
    Camino.push(Inicio);
    
}

int main(int argc, const char * argv[]) {
    
    string Ruta;
    int S,T;
    char seleccion = 's';

    cout<<"Escriba La ruta del archivo:  ";
    cin>>Ruta;
    
    if (CargarRedesMetro(Ruta)){
        
        RellenarListaAdyacencia(Ruta);
        
        do {
            
            //limpiar variables:
            while(!Camino.empty()) Camino.pop();
            
            cout<<"De que estacion Inicia?: ";
            cin>>Inicio;
            cout<<"A que estacion Quiere ir?: ";
            cin>>Final;
            
            //Manejar Errores:
            if (Inicio != Final) {
                
                if (MetrosMap.count(Inicio)) {
                    
                    if (MetrosMap.count(Final)) {
                        
                        S = MetrosMap.find(Inicio)->second;
                        T = MetrosMap.find(Final)->second;
                        
                        BuscarRuta(S, T);
                        
                        while (!Camino.empty()) {
                            
                            cout<<"-"<<Camino.top()<<endl;
                            Camino.pop();
                            
                        }
                        
                        cout<<endl<<"Desea Trazar otra ruta? s/n : ";
                        cin>>seleccion;
                        
                        
                    }else{
                        cout<<"Metro Final No Existe"<<endl;
                    }
                }else{
                    cout<<"Metro Inicial No existe"<<endl;
                }
            }else{
                cout<<"No puedes trazar una ruta desde la misma estacion."<<endl;
            }
            
        } while (seleccion != 'n');

    }
    
    return 0;
}
