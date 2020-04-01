#include <iostream>
#include <vector>

using namespace std;

vector<int> numeros;

bool esPrimo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i=2; i<n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool estaEnArreglo(int n) {
    for (int i=0; i<numeros.size(); i++) {
        if (numeros[i] == n) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        int num;
        cin>>num;
        numeros.push_back(num);
    }
    int inicio,fin;
    cin>>inicio>>fin;

    int primos = 0;
    for (int i=inicio; i<=fin; i++) {
        if(estaEnArreglo(i) && esPrimo(i)) {
            primos++;
        }
    }

    cout<<primos<<endl;

    return 0;
}