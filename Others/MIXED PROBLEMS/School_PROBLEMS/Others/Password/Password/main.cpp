//
//  main.cpp
//  Password
//
//  Created by Jose De Jesus Garfias Lopez on 03/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace::std;


int main() {

    
    int Tam= 0;
    cin>>Tam;
    
    bool flagNum=false;
    bool flagVocal=false;
    bool flagNoRepeat=true;
    bool flagtam=false;
    

    char Arreglo[Tam];
        
    for (int i=0; i<Tam; i++) {
            
        cin>>Arreglo[i];
        
        if (Tam>=12) {
            flagtam = true;
        }
            
        if (isdigit(Arreglo[i])) {
            
            flagNum=true;
        
        }else if (  Arreglo[i] == 'A' ||
                    Arreglo[i] == 'E' ||
                    Arreglo[i] == 'I' ||
                    Arreglo[i] == 'O' ||
                    Arreglo[i] == 'U' ||
                    Arreglo[i] == 'a' ||
                    Arreglo[i] == 'e' ||
                    Arreglo[i] == 'i' ||
                    Arreglo[i] == 'o' ||
                    Arreglo[i] == 'u'
                  ){
            
                flagVocal=true;
        }
            
            
        if ( i >= 1) {
                
            if (Arreglo[i-1] == Arreglo[i]) {
                flagNoRepeat = false;
            }
                
        }
            
            
    }

    if (flagNum && flagVocal && flagNoRepeat && flagtam) {
        cout<<"SEGURO";
    }else{
        cout<<"INSEGURO";
    }
        
        
    
    
    return 0;
}
