//
//  main.cpp
//  Oxxo_Sistema
//
//
//
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>     /* atoi */


using namespace std;


template <typename T>
string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

class Producto{
private:
    string CodBarras;
    string Nombre;
    string Presentacion;
    int Stock;
    float Precio;
    
public:
    
    Producto(string = "Sin CodigoBarras", string = "Sin Nombre", string = "Sin Presentacion" ,int = 0, float = 0.0 );
    void Leer();
    void Imprimir();
    bool ModificarStock(int A);
    string ReturnCodigo();
    float ReturnPrecio();
    string ReturnNombre();
    string ReturnForSave();
    
};

Producto::Producto(string C,string N,string Pr,int S,float P):CodBarras(C),Nombre(N),Presentacion(Pr),Stock(S),Precio(P)
{
    
}

void Producto::Leer(){
    
    cout<<endl<<"***************LECTURA DE PRODUCTO**************"<<endl;
    cout<<"Codigo De barras: ";
    cin>>CodBarras;
    cout<<"Nombre Del Producto: ";
    cin>>Nombre;
    cout<<"Presentacion Del Producto: ";
    cin>>Presentacion;
    cout<<"Productos en Existencia: ";
    cin>>Stock;
    cout<<"Precio Del Producto: ";
    cin>>Precio;
    cout<<endl;
    
}

void Producto::Imprimir(){
    
    cout<<endl<<"******PRODUCTO*******"<<endl;
    cout<<"Codigo De barras: "<<CodBarras<<endl;
    cout<<"Nombre Del Producto: "<<Nombre<<endl;
    cout<<"Presentacion Del Producto: "<<Presentacion<<endl;
    cout<<"Productos en Existencia: "<<Stock<<endl;
    cout<<"Precio Del Producto: $"<<Precio<<endl;
    cout<<endl;
    
}

string Producto::ReturnCodigo(){
    return CodBarras;
}
float Producto::ReturnPrecio(){
    return Precio;
}
string Producto::ReturnNombre(){
    return Nombre;
}
bool Producto::ModificarStock(int A){

    if ((Stock - A) < 0) {
        return false;
    }else{
        Stock = Stock-A;
    }
    return true;
}
string Producto::ReturnForSave(){
    return CodBarras + "-" + Nombre + "-" + Presentacion + "-" + NumberToString(Stock) + "-" + NumberToString(Precio) + "\n";
}

vector<Producto>Lista_Productos;


class ProdVenta{
    Producto Item;
    int Cantidad;
public:
    ProdVenta(Producto P , int C){
        Item = P;
        Cantidad = C;
    }
    float PrecioItem(){
        return Item.ReturnPrecio();
    };
    string NombreItem(){
        return Item.ReturnNombre();
    }
    int CantidadItem(){
        return Cantidad;
    }
    void ImprimirItem(){
        cout<<"Cant. "<<Cantidad<<" - "<<"Producto: "<<Item.ReturnNombre()<<endl;
    }
    string ReturnItem(){
        return "Cant." + NumberToString(Cantidad) + "-Producto:" + Item.ReturnNombre() + "\n";
    }
};


class Venta{
private:
    
    vector<ProdVenta>Items;
    string Fecha;
    string Empleado;
    float Total;
    
public:
    
    Venta(string ="Sin Fecha", string = "Sin Empleado",float = 0.0);
    void LeerVenta(string F, string E);
    void ImprimirVenta();
    float ReturnTotalV();
    string ReturnForSave();
    
};

Venta::Venta(string F,string E,float T):Fecha(F),Empleado(E),Total(T){

}

void Venta::LeerVenta(string F, string E){
    
    Fecha = F;
    Empleado = E;
    string Cod;
    bool Encontrado = false;
    char seleccion = 's';
    do {
        cout<<"*****Agregar Producto*****"<<endl;
        cout<<"Codigo Barras Producto: ";
        cin>>Cod;
        
        //busqueda de producto:
        
        for (int i = 0; i<Lista_Productos.size(); i++) {
            
            if (Lista_Productos[i].ReturnCodigo() == Cod) {
                //producto encontrado:
                Encontrado = true;
                //se inserta el producto en el vector de la venta:
                int cantidad = 0;
                
                cout<<"Cuantas unidades? : ";
                cin>>cantidad;
                
                if (cantidad > 0) {
                    
                    if (Lista_Productos[i].ModificarStock(cantidad)) {
                        
                        ProdVenta NuevoProducto(Lista_Productos[i],cantidad);
                        Items.push_back(NuevoProducto);
                        
                    }else{
                        cout<<"Stock Insuficiente para surtir la venta."<<endl;
                    }

                }else{
                    cout<<"La cantidad no puede ser < 0"<<endl;
                }

                
            }
        }
        
        if (Encontrado == false) {
            cout<<"Producto No encontrado en la base de datos."<<endl<<"Desea intentar de nuevo? s/n : ";
        }else{
            
            cout<<"********Productos En Venta: *********"<<endl;
            Total = 0;
            
            for (int i = 0; i<Items.size(); i++) {
                cout<<i+1<<".- "<<Items[i].NombreItem()<<"  ("<<Items[i].CantidadItem()<<") "<<endl;
                Total = Total + (Items[i].PrecioItem() * Items[i].CantidadItem());
            }
            
            
            cout<<"Total: $"<<Total<<endl;
            cout<<"Desea Agregar otro producto a la venta?  s/n: "<<endl;
            cin>>seleccion;
        }
        
        
    } while (seleccion != 'n');
    
    
    
}

void Venta::ImprimirVenta(){
    
    cout <<"Fecha de Venta : "<<Fecha<<endl;
    cout<<"Empleado: "<<Empleado<<endl;
    for (int j = 0; j<Items.size(); j++) {
        Items[j].ImprimirItem();
    }
    cout<<"TOTAL: $"<<Total<<endl;
}

float Venta::ReturnTotalV(){
    return Total;
}

string Venta::ReturnForSave(){
    
    string cad;
    
    for (int j = 0; j<Items.size(); j++) {
        cad = cad + Items[j].ReturnItem();
    }
    cad = cad + "TOTAL:$" + NumberToString(Total) + "\n";
    
    return cad;
}

vector<Venta>Lista_Ventas;


bool CargarProductos(){
    
    //Leer Productos.txt y cargarlos en Lista_Productos.
    string Ruta = "Productos.txt";
    
    if (!Lista_Productos.empty()) {
        Lista_Productos.clear();
    }
    
    ifstream fileRead(Ruta.c_str(),ios_base::in);
    
    if (fileRead.good()) {
        while (!fileRead.eof()) {
            
            string Cadena;
            fileRead>>Cadena;
            
            if (Cadena != "") {
                
                string Codigo,Nombre,Descrip,Stock,Precio;
                
                
                Codigo = Cadena.substr(0,Cadena.find('-'));
                Cadena.erase(0,Cadena.find('-')+1);
                
                Nombre = Cadena.substr(0,Cadena.find('-'));
                Cadena.erase(0,Cadena.find('-')+1);
                
                Descrip = Cadena.substr(0,Cadena.find('-'));
                Cadena.erase(0,Cadena.find('-')+1);
                
                Stock = Cadena.substr(0,Cadena.find('-'));
                Cadena.erase(0,Cadena.find('-')+1);
                
                Precio = Cadena.substr(0,Cadena.find('\n'));
                Cadena.erase(0,Cadena.find('\n')+1);
                
                Cadena.clear();
                
                int S = atoi(Precio.c_str());
                int P = atof(Precio.c_str());
                
                
                //Agregar a la lista:
                Producto NewProducto(Codigo,Nombre,Descrip,S,P);
                Lista_Productos.push_back(NewProducto);
                
            }
            
        }
    }else{
        cout<<"Ocurrio un error al abrir su archivo."<<endl;
        return 0;
    }
    
    return 1;

}

bool GuardarProductos(){
    
    ofstream myfile ("Productos.txt");
    
    if (myfile.is_open())
    {
        for (int i = 0; i<Lista_Productos.size(); i++) {
            myfile<<Lista_Productos[i].ReturnForSave();
        }
        
        myfile.close();
        
    }else {
        return 0;
    }
    return 1;
}

bool GuardarVentas(string F){

    //leer archivo, luego actualizar y guardar...
    //Leer Productos.txt y cargarlos en Lista_Productos.
    string Ruta = "Ventas.txt";
    vector<string>Ventastmp;
    
    if (!Lista_Ventas.empty()) {

        ifstream fileRead(Ruta.c_str(),ios_base::in);
        
        if (fileRead.good()) {
            while (!fileRead.eof()) {
                
                string Cadena;
                fileRead>>Cadena;
                Ventastmp.push_back(Cadena);
            }
        }else{
            return 0;
        }
        
        ofstream myfile ("Ventas.txt");
        
        if (myfile.is_open())
        {
            //Se agregan las ventas pasadas:
            for (int i = 0; i<Ventastmp.size(); i++) {
                myfile<<Ventastmp[i]<<"\n";
            }
            //se agregan las ventas del dia.
            myfile<<"*************FECHA:"<<F<<"*******************\n";
            
            for (int i = 0; i<Lista_Ventas.size(); i++) {
                myfile<<"------------Venta#"<<i+1<<"----------\n";
                myfile<<Lista_Ventas[i].ReturnForSave();
            }
            
            myfile.close();
            
        }else {
            return 0;
        }

    }else{
        return 0;
    }
    
    return 1;
}


int main(int argc, const char * argv[]) {

    string FechaActual,EmpleadoActual;
    cout<<"Bienvenido"<<endl;
    cout<<"¿Cual es la fecha de hoy? (dd/mm/YYYY) : ";
    cin>>FechaActual;
    cout<<"¿Quien es el Empleado en Turno? : ";
    cin>>EmpleadoActual;

    if (CargarProductos()) {
        cout<<"Carga de productos exitosa!......"<<endl;
    }
    
    int seleccion;
    
    do {
        cout<<" ******SERVICIOS OXXO*******"<<endl;
        cout<<"1.- Realizar Venta."<<endl;
        cout<<"2.- Productos."<<endl;
        cout<<"3.- Reporte Del Dia"<<endl;
        cout<<"4.- Salir."<<endl;
        
        cin>>seleccion;
        
        switch (seleccion) {
            case 1:
                
                if (Lista_Productos.empty()) {
                    cout<<"Favor de insertar productos para poder realizar venta."<<endl;
                }else{
                    //realiza La venta:
                    
                    Venta NuevaVenta;
                    NuevaVenta.LeerVenta(FechaActual, EmpleadoActual);
                    Lista_Ventas.push_back(NuevaVenta);
                    
                    cout<<"Venta Agregada."<<endl;
                }
                
                break;
            case 2:
                
                int Option;
                
                do {
                    
                    cout<<"******** MENU PRODUCTOS *********"<<endl;
                    cout<<"1.- Agregar Producto."<<endl;
                    cout<<"2.- Actualizar Producto."<<endl;
                    cout<<"3.- Eliminar Producto."<<endl;
                    cout<<"4.- Ver productos existentes."<<endl;
                    cout<<"5.- Salir (Regresar Menu Principal)."<<endl;
                    
                    cin>>Option;
                    
                    switch (Option) {
                        case 1:
                        {
                            Producto NuevoP;
                            NuevoP.Leer();
                            Lista_Productos.push_back(NuevoP);
                            
                            cout<<"Producto Agregado"<<endl;
                        }
                            break;
                        case 2:
                        {
                            string cod;
                            bool Encontrado = false;
                            cout<<"Codigo de Barras: "<<endl;
                            cin>>cod;
                            
                            for (int i = 0; i<Lista_Productos.size(); i++) {
                                if (Lista_Productos[i].ReturnCodigo() == cod) {
                                    Encontrado = true;
                                    //Actualizar producto.
                                    Lista_Productos[i].Leer();
                                    cout<<"Producto Actualizado."<<endl;
                                }
                            }
                            
                            if (Encontrado == false) {
                                cout<<"Producto No encontrado."<<endl;
                            }
                        }
                            break;
                        case 3:
                        {
                            string cod;
                            bool Encontrado = false;
                            cout<<"Codigo de Barras: "<<endl;
                            cin>>cod;
                            
                            for (int i = 0; i<Lista_Productos.size(); i++) {
                                if (Lista_Productos[i].ReturnCodigo() == cod) {
                                    Encontrado = true;
                                    //Actualizar producto.
                                    Lista_Productos.erase(Lista_Productos.begin() + i);
                                    cout<<"Producto Eliminado."<<endl;
                                }
                            }
                            
                            if (Encontrado == false) {
                                cout<<"Producto No encontrado."<<endl;
                            }
                        
                        }
                            break;
                        case 4:
                        {
                            for (int i=0; i<Lista_Productos.size(); i++) {
                                Lista_Productos[i].Imprimir();
                            }
                            cout<<endl;
                        }
                            break;
                        case 5:
                        {
                            cout<<"Regresando al menu....Guardando Productos..."<<endl;
                            
                            if (GuardarProductos()) {
                                cout<<"Archivo de productos actualizado Correctamente."<<endl;
                            }else{
                                cout<<"Ocurrio un error al guardar tu archivo."<<endl;
                            }
                        }
                            break;
                            
                        default:
                            cout<<"Opcion Incorrecta."<<endl;
                            break;
                    }

                    
                } while (Option != 5);
                
                break;
            case 3:
            {
                float TotalActual=0.0;
                cout<<"***********REPORTE DEL DIA "<<FechaActual<<"*********"<<endl;
                
                cout<<"***********VENTAS DE HOY: "<<Lista_Ventas.size()<<"*******"<<endl;
                
                for (int i = 0; i<Lista_Ventas.size(); i++) {
                    
                    cout<<"*****VENTA ****"<<i+1<<"****"<<endl;
                    Lista_Ventas[i].ImprimirVenta();
                    cout<<endl;
                    TotalActual = TotalActual + Lista_Ventas[i].ReturnTotalV();
                }
                
                cout<<"TOTAL DE VENTAS DE HOY : "<<TotalActual<<endl;
            
            }
                
                break;
            case 4:
                cout<<"Hasta Luego! .....Guardando Datos. "<<endl;
                if (GuardarVentas(FechaActual)) {
                    GuardarProductos();
                    cout<<"Ventas Guardadas.."<<endl;
                }else{
                    cout<<"Error al guardar tus ventas."<<endl;
                }
                break;
                
            default:
                cout<<"Seleccion Incorrecta."<<endl;
                break;
        }

    } while (seleccion != 4);
    
    return 0;
}
