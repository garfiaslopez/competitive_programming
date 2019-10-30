//
//  main.cpp
//  MatrizCuadrada
//
//  Created by Jose De Jesus Garfias Lopez on 03/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>


using namespace std;


int main(int argc, const char * argv[]) {

    
    
    int F,C =0;
    int consultas;
    cin>>F;
    cin>>C;
    cin>>consultas;
    
    for (int i=0; i<consultas; i++) {
        
        
        int x,y=0;
        cin>>x;
        cin>>y;
        
        cout<<((x-1)*C)+y<<" ";
    }
    
    return 0;
}
