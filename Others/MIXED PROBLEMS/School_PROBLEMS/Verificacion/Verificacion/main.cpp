//
//  main.cpp
//  Verificacion
//
//  Created by Jose De Jesus Garfias Lopez on 2/26/17.
//  Copyright © 2017 Karmapulse. All rights reserved.
//

#include <iostream>

using namespace std;


int dateDiff(string from, string to) {
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    string choice = "";
    string typeDate = "Compra";
    string Date = "00-00-0000";
    string Today = "00-00-0000";
    
    while (choice != "n" && choice != "y") {
        cout << "Vehiculo nuevo? (y/n): ";
        cin>>choice;
    }
    
    if(choice == "n") {
        typeDate = "Ultima verificación";
    }
    
    cout<< "Fecha de "<< typeDate <<" en formato (dd-mm-yyy): ";
    cin>>Date;
    
    cout<< "Fecha de hoy: ";
    cin>>Today;
    
    int Difference = dateDiff(Date, Today);
    
    cout<< "___RESULTADO: \n \n";
    if (choice == "y") {
        cout<< "Vehiculo nuevo \n";
        cout<< "Fecha de compra: "<<Date<<endl;
    }else{
        cout<< "Fecha de ultima verificación: "<<Date<<endl;
    }
    

    if (choice == "y" && Difference <= 60 ){
        cout<<"Pago : $460 \n";
    }else if(choice == "y" && Difference > 60) {
        cout<<"Pago : $"<< 460 + (12* (Difference - 60)) << endl;
    }else if(choice == "n" && Difference <= 15) {
        cout<<"Pago : $460 \n";
    }else if (choice == "n" && Difference > 15) {
        cout<<"Pago : $"<< 460 + (12* (Difference - 15)) << endl;
    }else{
        cout<<"Fechas invalidas. \n";
    }
    
    
    return 0;
}
