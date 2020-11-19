#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Gauus{
private:
    int TAM;
    double **Matriz;
public:
    void Inicializar();
    void ImprimirMatriz();
    void Calcular();
    void Leer();
    bool Validar();
    void LeerTAM();
};


void Gauus::ImprimirMatriz(){
    cout<<endl<<endl;
    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM+1; j++) {
            cout << Matriz[i][j] << "\t";
            if (j == TAM-1) {
                cout << "| ";
            }
        }
        cout << "\n";
    }
    cout << endl<<endl;
}

bool Gauus::Validar(){
    bool flag = false;
    for (int i=0; i<TAM; i++){
        double MaxValue = abs(Matriz[i][i]);
        for (int j=0; j<TAM; j++) {
            double temp = abs(Matriz[i][j]);
            if(MaxValue != temp){
                if(MaxValue > temp){
                    flag = true;
                }else{
                    flag = false;
                }
            }
        }
    }
    if(flag){
        return true;
    }
    return false;
}

void Gauus::Calcular(){
    
    for (int i=0; i<TAM; i++) {
        
        // Buscando el Maximo de la columna
        double maxEl = abs(Matriz[i][i]);
        int maxRow = i;
        for (int k=i+1; k<TAM; k++) {
            if (abs(Matriz[k][i]) > maxEl) {
                maxEl = abs(Matriz[k][i]);
                maxRow = k;
            }
        }
        
        // Cambiar maxima fila con la fila actual.
        for (int k=i; k<TAM+1;k++) {
            double tmp = Matriz[maxRow][k];
            Matriz[maxRow][k] = Matriz[i][k];
            Matriz[i][k] = tmp;
        }
        
        // Todas las filas hacia abajo 0 en la columna
        for (int k=i+1; k<TAM; k++) {
            double c = -Matriz[k][i]/Matriz[i][i];
            for (int j=i; j<TAM+1; j++) {
                if (i==j) {
                    Matriz[k][j] = 0;
                } else {
                    Matriz[k][j] += c * Matriz[i][j];
                }
            }
        }
    }
    
    // Resolver Ax=b para la matriz triangular
    double* Res = new double[TAM];
    
    for (int i=TAM-1; i>=0; i--) {
        Res[i] = Matriz[i][TAM]/Matriz[i][i];
        for (int k=i-1;k>=0; k--) {
            Matriz[k][TAM] -= Matriz[k][i] * Res[i];
        }
    }
    
    //Imprimir:
    cout<<"RESULTADO: \t"<<endl;
    for (int i=0; i<TAM; i++){
        cout<<"Incognita "<<i+1<<": "<<Res[i]<<endl;
    }
}

void Gauus::Leer(){
    
    cout<<"Favor de ingresar las variables "<<endl;
    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            cin >> Matriz[i][j];
        }
    }
    
    
    cout<<endl<<"Favor de ingresar las respuestas "<<endl;
    for (int i=0; i<TAM; i++) {
        cin >> Matriz[i][TAM];
        
    }
    cout<<endl;
}
void Gauus::LeerTAM(){
    cout<<"De cuantas incognitas es su sistema?: ";
    cin>>TAM;
    cout<<endl;
}

void Gauus::Inicializar(){
    
    Matriz = new double*[TAM+1];
    
    for (int i =0; i<TAM+1; i++) {
        Matriz[i]= new double[TAM];
    }
    
}


int main() {
    
    system("pause");
    system("cls");
    char r;
    do{
        
        Gauus SistemaEc;
        //   system("pause");
        SistemaEc.LeerTAM();
        SistemaEc.Inicializar();
        SistemaEc.Leer();
        SistemaEc.ImprimirMatriz();
        if(SistemaEc.Validar()){
            SistemaEc.Calcular();
        }else{
            cout<<"No es diagonalmente dominante.";
        }
        
        
        cout<<"Desea Salir s o n: ";
        cin>>r;
        system("CLS");
    }while(r=='n');
}
