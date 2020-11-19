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

void Procesa(){
    
    //ORDENAR:
    sort(VectorP.begin(), VectorP.end());
    sort(VectorC.begin(), VectorC.end());
    sort(VectorF.begin(), VectorF.end());
    
    do {
        
        
        for (int i = 0; i<VectorP.size(); i++) {
            cout<<VectorP[i]<<"  ";
        }
        cout<<endl;
        
        
        
    } while (next_permutation(VectorP.begin(), VectorP.end()));
    
    
    
    
    
    
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
