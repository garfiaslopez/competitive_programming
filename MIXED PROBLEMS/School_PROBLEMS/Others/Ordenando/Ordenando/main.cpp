//
//  main.cpp
//  Ordenando
//
//  Created by Jose De Jesus Garfias Lopez on 02/12/14.
//  Copyright (c) 2014 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;



int main() {

    
    int N;
    
    cin>>N;
    
    vector<int> Arreglo(N);
    vector<int> Creciente(N);
    vector<int> Decreciente(N);

    for (int i = 0; i<N; i++) {
        int x;
        cin>>x;
        
        Arreglo[i]=x;
        Creciente[i] =x;
        Decreciente[i]=x;
    }
    
    std::sort(std::begin(Creciente),std::end(Creciente));
    std::sort(std::begin(Decreciente), std::end(Decreciente),std::greater<int>());

    
    if (Arreglo == Creciente) {
        cout<<"CRECIENTE";
    }else if (Arreglo == Decreciente){
        cout<<"DECRECIENTE";
    }else{
        cout<<"NO ORDENADA";
    }
    

    
    
    return 0;
}
