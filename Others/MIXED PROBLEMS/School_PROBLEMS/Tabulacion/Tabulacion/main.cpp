#include <iostream>
#include <math.h>
#include <iomanip>     


using namespace std;

double GetW(int m, double Angle){
    return 1/(m + (1/(sin(m * Angle))));
}

int main() {
    
    char seleccion;
    do {
        
        double Angle;

        cout<<"Introducir Θ: ";
        cin>>Angle;
        
        cout<<setw(5)<<"m"<<setw(15)<<"W"<<endl<<endl;
        
        for (int m=-10; m<=10; m++){
            cout<<setw(5)<<m<<setw(20)<<GetW(m,Angle)<<endl;
        }
        
        cout<<"Desea realizar otra operacion? (S/N): "<<endl;
    } while (seleccion == 'S' || seleccion == 's');
    
    return 0;
}
