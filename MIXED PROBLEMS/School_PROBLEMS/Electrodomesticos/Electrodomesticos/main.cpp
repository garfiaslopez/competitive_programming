//
//  main.cpp
//  Electrodomesticos
//
//

#include <iostream>
#include <vector>


using namespace std;

class Electrodomestico{
    
private:
    string Tipo;
    string Marca;
    string Modelo;
    string Serie;
    string Color;
    
public:
    
    Electrodomestico(string Ti="Sin Tipo",string Ma="Sin Marca",string Mo = "Sin Modelo",string Se="Sin Serie",string Co="Sin Color");
    void LeerElectrodomestico ();
    void ImprimirElectrodomestico();
};

class Venta{
    
private:
    int Folio;
    string Empleado;
    string Cliente;
    string FechaEntrada;
    string FechaSalida;
    string Falla;
    float Total;
    Electrodomestico ElectReparado;
    
public:
    
    Venta(int Fo=0000,string Em = "Sin Empleado",string Cli = "Sin Cliente",string FeE = "00/00/0000",string FeS = "00/00/000",string Fa="Falla Sin Especificar",float To = 0.00);
    
    void RecibirElectrodomestico(int F);
    void LeerVenta();
    void ImprimirVenta();
    int ReturnFolio();
};

Electrodomestico::Electrodomestico(string Ti,string Ma, string Mo, string Se, string Co):Tipo(Ti),Marca(Ma),Modelo(Mo),Serie(Se),Color(Co){
}

void Electrodomestico::LeerElectrodomestico(){
    
    cout<<"Tipo de electrodomestico:   ";
    getline(cin, Tipo);
    cout<<"Marca de "<<Tipo<<":   ";
    getline(cin, Marca);
    cout<<"Modelo de "<<Tipo<<":   ";
    getline(cin, Modelo);
    cout<<"Numero de Serie de "<<Tipo<<":   ";
    getline(cin, Serie);
    cout<<"Color de "<<Tipo<<":   ";
    getline(cin, Color);
    
}

void Electrodomestico::ImprimirElectrodomestico(){

    cout<<"Tipo:   "<<Tipo<<endl;
    cout<<"Marca:   "<<Tipo<<endl;
    cout<<"Modelo:   "<<Tipo<<endl;
    cout<<"No. Serie:   "<<Tipo<<endl;
    cout<<"Color:   "<<Tipo<<endl<<endl;
    
}

Venta::Venta(int Fo,string Em,string Cli,string FeE,string FeS,string Fa,float To):Folio(Fo),Empleado(Em),Cliente(Cli),FechaEntrada(FeE),FechaSalida(FeS),Falla(Fa),Total(To){
    
}


void Venta::RecibirElectrodomestico(int F){

    Folio = F;
    cout<<"Fecha de hoy:   ";
    cin.ignore();
    getline(cin, FechaEntrada);
    cout<<"Cliente:   ";
    getline(cin, Cliente);
    
    ElectReparado.LeerElectrodomestico();
    
}

void Venta::LeerVenta(){
    
    cin.ignore();

    cout<<"Fecha Entrega:   ";
    getline(cin, FechaSalida);
    cout<<"Empleado:   ";
    getline(cin, Empleado);
    cout<<"Falla Del Equipo:   ";
    getline(cin, Falla);
    cout<<"Total:   ";
    cin>>Total;
    cin.ignore();

}



void Venta::ImprimirVenta(){
    
    cout<<endl<<"---------------------------------------------------"<<endl;

    cout<<"Folio: #"<<Folio<<endl;
    cout<<"Emleado: "<<Empleado<<endl;
    cout<<"Cliente: "<<Cliente<<endl;
    cout<<"Fecha De Entrada: "<<FechaEntrada<<endl;
    cout<<"Fecha De Salida: "<<FechaSalida<<endl;
    cout<<"Falla: "<<Falla<<endl<<endl;
    cout<<"Detalle de Equipo: "<<endl;
    ElectReparado.ImprimirElectrodomestico();
    cout<<"Total: "<<Total<<endl;
    cout<<"+IVA: "<<Total + (Total * 0.16)<<endl;
    
    cout<<endl<<"---------------------------------------------------"<<endl;

}

int Venta::ReturnFolio(){
    return Folio;
}


vector<Venta*>ArregloVentas;
int FolioActual = 1;


int BuscarIndice(int folio){

    int indice=0;
    bool bandera = false;
    
    for (int i = 0; i<ArregloVentas.size(); i++) {
        
        if (ArregloVentas[i]->ReturnFolio() == folio) {
            
            bandera = true;
            indice = i;
            
        }
    }
    
    if (bandera == false) {
        
        return -1;
        
    }else{

        return indice;
    }
    
    return -1;

}


void RecibirElectro(Venta* Ventatmp){
    
    cout<<endl<<"---------------------------------------------------"<<endl;

    cout<<"RECIBO NUMERO: "<<FolioActual<<" (FOLIO)"<<endl;
    
    Ventatmp->RecibirElectrodomestico(FolioActual);
    
    FolioActual++;
    
    ArregloVentas.push_back(Ventatmp);
    
}



void RealizarVenta(Venta* Ventatmp){


    Ventatmp->LeerVenta();
    
}





void Menu(){
    
    
    int seleccion=0;
    cout<<endl<<"--------------REPARACIONES MARCO---------------------"<<endl;
    cout<<"--------------Ventas Del Dia: "<<FolioActual-1<<"----------------------"<<endl;
    cout<<"--------------------MENU:----------------------------"<<endl;

    
    cout<<"1.- Recibir Electrodomestico."<<endl<<"2.- Realizar Venta."<<endl<<"3.-Imprimir Factura"<<endl<<"4.-Historial De Ventas"<<endl;
    cin>>seleccion;
    
    switch (seleccion) {
        case 1:
        {
            
            Venta* AptnewVenta = new Venta;
            RecibirElectro(AptnewVenta);
            
        }
            break;
        case 2:
        {
            
            
            cout<<endl<<"---------------------------------------------------"<<endl;
            int Folio;
            cout<<"Ingrese el No. Folio: ";
            cin>>Folio;
            int Index = BuscarIndice(Folio);
            
            if (Index >= 0) {
                
                cout<<endl<<"---------------------------------------------------"<<endl;
                cout<<"VENTA NUMERO: "<<Folio<<" (FOLIO)"<<endl;
                RealizarVenta(ArregloVentas[Index]);
                
            }else{
                
                cout<<"No se encontro Folio Solicitado.";
           
            }
            
            
        }
            break;
        case 3:
        {
            cout<<endl<<"---------------------------------------------------"<<endl;

            int Folio;
            cout<<"Ingrese el No. Folio: ";
            cin>>Folio;

            int Index = BuscarIndice(Folio);
            
            if (Index >= 0) {
                
                
                ArregloVentas[Index]->ImprimirVenta();
                
            }else{
                
                cout<<"No se encontro Folio Solicitado.";
                
            }
        
        }
            break;
        case 4:
        {
            
            cout<<endl<<"---------------------------------------------------"<<endl;
            cout<<"----------HISTORIAL DE VENTAS---------------"<<endl;
            
            for (int i = 0; i<ArregloVentas.size(); i++) {
                
                ArregloVentas[i]->ImprimirVenta();

            }
            
            cout<<endl<<"---------------------------------------------------"<<endl;

        
        }
            break;
            
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {

    char loop='s';
    
    while (loop == 's'  || loop == 'S' ) {
        
        Menu();
        
        cout<<endl<<"Desea realizar Alguna otra accion? s/n : ";
        cin>>loop;
    }
    
    
    return 0;
}
