//
//  main.cpp
//  Frecuencias
//
//  Created by Jose De Jesus Garfias Lopez on 03/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <string.h>


using namespace std;


int main() {

    int Prof;
    int Tam;
    
    cin>>Prof;
    cin>>Tam;
    
    int Frecuencia[Prof];
    
    for (int i = 0; i<Prof+1; i++) {
        Frecuencia[i]=0;
    }
    
    for (int i = 0; i<Tam; i++) {
        
        int number;
        
        cin>>number;
        
        
        Frecuencia[number]=Frecuencia[number]+1;
        
    }
    
    for (int i=1; i<=Prof; i++) {
        cout<<i<<"-"<<Frecuencia[i]<<endl;
    }
    
    
    
    
    return 0;
}
