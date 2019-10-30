#include <cstdio>
#include <iostream>

using namespace std;

int multiplicapor7(int x) {
    return x * 7;
}

void resuelve() {
    for (int i=0; i<3; i++) {
        int numero;
        cin>>numero;
        cout<<multiplicapor7(numero)<<endl;
    }
}

int main() {

    int a,b,c;
    
    cin>>a>>b>>c;
    cin>>a;
    cin>>b;
    cin>>c;

    scanf("%d %d %d",&a, &b, &c);
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    
    cout<<a*7<<endl<<b*7<<endl<<c*7<<endl;

    // for (int i=0; i<3; i++) {
    //     int numero;
    //     cin>>numero;
    //     cout<<numero * 7 <<endl;
    // }

    //resuelve();
    return (0);
}
