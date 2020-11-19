//
//  main.cpp
//  prefix&postfix
//
//  Created by Jose De Jesus Garfias Lopez on 10/02/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

string VoltearArreglo(string Arreglo)
{

    string ArregloNew;
    
    for (int i = (int)Arreglo.size(); i >=0 ; i--)
        ArregloNew += Arreglo[i];
    
    return ArregloNew;
}

bool isNumber(char &n)
{
    if(!isdigit(n)){
        return false;
    }else
        return true;
}

int main()
{

    stack<int> Pila;
    string Expresion;
    
    cout<<"Favor de insertar su expresion prefija:  ";
    getline(cin, Expresion);
    
    Expresion = VoltearArreglo(Expresion);
    
    for (int i = 0; i<Expresion.size(); i++) {
        
        if (isNumber(Expresion[i])==true) {
            
            cout<<"Metio en pila"<<(int)Expresion[i]-'0'<<endl;
            Pila.push((int)Expresion[i] - '0');
            
        }else{
        
            
            if (Expresion[i]=='+' ||
                Expresion[i]=='-' ||
                Expresion[i]=='/' ||
                Expresion[i]=='*'
                ) {
                
                int a = Pila.top();
                Pila.pop();
                int b = Pila.top();
                Pila.pop();
                
                switch (Expresion[i]) {
                    case '+':
                        Pila.push(a+b);
                        break;
                    case '-':
                        Pila.push(b-a);
                        break;
                    case '/':
                        Pila.push(b/a);
                        break;
                    case '*':
                        Pila.push(a*b);
                        break;
                }
            }
        }
    }
    
    cout<<"RESULTADO: "<<Pila.top();//result should be 17...
    return 0;
}
