//
//  main.cpp
//  Bardeando
//
//  Created by Jose De Jesus Garfias Lopez on 03/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    
    int perimetro=0;
    int bardas=0;
    
    cin>>perimetro;
    cin>>bardas;
    
    int sumabardas=0;
    
    for (int i=0; i<bardas; i++) {
        
        int x;
        cin>>x;
        
        sumabardas=sumabardas+x;
    }
    
    int restante = perimetro-sumabardas;
    
    if (restante<=0) {
        cout<<"0";
    }else{
        cout<<restante;
    }
    
    
    return 0;
}
