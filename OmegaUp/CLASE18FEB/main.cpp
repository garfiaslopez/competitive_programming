#include <iostream>

using namespace std;

int main() {

    int a,b,x,y;
    int movimientos = 0;

    cin>>a>>b;
    x = a;
    y = b;

    bool hacerMovimientos = true;

    while(hacerMovimientos) {
        int nuevoValor = (x+y)%10;
        if (a == y && b == nuevoValor) {
            hacerMovimientos = false;
        }
        cout<<nuevoValor<<" ";

        x = y;
        y = nuevoValor;
        movimientos++;
    }

    cout<<endl<<movimientos<<endl;

    return (0);
}