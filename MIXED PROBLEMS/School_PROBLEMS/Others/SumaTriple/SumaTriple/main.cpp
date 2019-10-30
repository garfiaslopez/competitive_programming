//
//  main.cpp
//  SumaTriple
//
//  Created by Jose De Jesus Garfias Lopez on 03/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <stdint.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int Tam;
    cin>>Tam;
    
    int64_t Arreglo[Tam];
    
    for (int i = 0; i<Tam; i++) {
        
        if (i==0) {
            Arreglo[i]=1;
        }else if (i==1){
            Arreglo[i]=1;
        }else if (i==2){
            Arreglo[i]=2;
        }else{
            Arreglo[i]= Arreglo[i-1]+Arreglo[i-2]+Arreglo[i-3];
        }
    }
    
    for (int i=0; i<Tam; i++) {
        cout<<Arreglo[i]<<" ";
    }
    
    return 0;
}
