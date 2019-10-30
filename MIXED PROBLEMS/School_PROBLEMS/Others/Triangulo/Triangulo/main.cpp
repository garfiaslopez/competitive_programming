//
//  main.cpp
//  Triangulo
//
//  Created by Jose De Jesus Garfias Lopez on 03/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {

    
    
    vector<int> Arreglo(3);
    
    for (int i = 0; i<3; i++) {
        cin>>Arreglo[i];
    }
    
    std::sort(std::begin(Arreglo), std::end(Arreglo),std::greater<int>());
    
    if ( (pow((double)Arreglo[0], 2)) == (pow((double)Arreglo[1], 2)) +  (pow((double)Arreglo[2], 2))  ) {
        
        for (int i = 0; i<3; i++) {
            cout<<Arreglo[i]<<" ";
        }
    
    }else{
        cout<<"imposible";
    }
    return 0;
}
