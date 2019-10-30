//
//  main.cpp
//  String_Permutation
//
//  Created by Jose De Jesus Garfias Lopez on 15/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string cadena;
    int permutaciones=0;
    
    cin>>cadena;
    
    sort(cadena.begin(), cadena.end());
    
    cout<<cadena<<endl;

    do {
        cout<<cadena<<endl;
        permutaciones++;
    } while (next_permutation(cadena.begin(), cadena.end()));
    cout<<"NUMERO DE PERMUTACIONES: "<<permutaciones<<endl;
    return 0;
}
