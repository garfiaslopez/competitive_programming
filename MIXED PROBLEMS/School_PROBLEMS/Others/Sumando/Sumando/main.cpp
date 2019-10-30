//
//  main.cpp
//  Sumando
//
//  Created by Jose De Jesus Garfias Lopez on 03/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {

    int Tam;
    
    cin>>Tam;
    
    int Matriz[Tam][Tam];
    
    for (int i=0; i<Tam; i++) {
        for (int j=0; j<Tam; j++) {
            
            cin>>Matriz[i][j];
        }
    }
    
    for (int i= 0; i<Tam; i++) {
        
        int suma=0;
        
        for (int j=0; j<Tam; j++) {
            
            suma=suma+Matriz[j][i];
            
        }
        
        cout<<suma<<" ";
    }
    

    return 0;
}
