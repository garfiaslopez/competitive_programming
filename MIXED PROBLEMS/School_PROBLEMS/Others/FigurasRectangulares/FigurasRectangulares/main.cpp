//
//  main.cpp
//  FigurasRectangulares
//
//  Created by Jose De Jesus Garfias Lopez on 02/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//


#include <iostream>
#include <math.h>

using namespace std;


int square_check (int x)
{
    float z= sqrt((float)(x));
    
    cout<<"raiz:"<<z;
    
    if (z ==(int)z)
        return 1;
    else 
        return 0;
    
}


int main() {

    int Area;
    
    cin>>Area;
    
    if (square_check(Area)) {
        
        //isCuadrado:
        int root = (int)sqrt((double)Area);
  
        for (int i = 2; i<root; i++) {
            
            if (!(Area%i)) {
                
                cout<<"ambos";
                return 0;
            }
            
        }
        
        cout<<"cuadrado";
        
    }else{
        
        cout<<"rectangulo";
    }
    
    
    return 0;
}
