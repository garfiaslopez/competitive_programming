
#include <iostream>
#include <fstream>

using namespace std;


class Informacion
{
protected:
    
    string Nombre;
    long long int NumCuenta;
    float Saldo;
    
public:
    
    Informacion(string = "Sin Nombre", int = 0, float = 0 );
    
    void LeerInformacion(void);
    
    string RetornarNombre(void);
    long long int RetornarCuenta(void);
    float RetornarSaldo(void);
    void NuevoSaldo(float);
    
    void Imprimir (void);
    
    
};


Informacion::Informacion(string N,int C,float S):Nombre(N),NumCuenta(C),Saldo(S)
{
    
}



void Informacion::LeerInformacion(void)
{
    cout<<"Introduzca su Numero de cuenta por favor: ";
    cin>>NumCuenta;
    cout<<"Introduzca su nombre por favor: ";
    cin.ignore();
    getline(cin, Nombre);
    cout<<"Introduzca su saldo por favor: ";
    cin>>Saldo;
}

string Informacion::RetornarNombre(void)
{
    return Nombre;
}

long long int Informacion:: RetornarCuenta(void)
{
    return NumCuenta;
    
}

float Informacion::RetornarSaldo(void)
{
    
    return Saldo;
}

void Informacion::NuevoSaldo(float NewSaldo){
    
    Saldo = NewSaldo;
    
}

void Informacion::Imprimir(void)
{
    
    cout<<"Nombre Del Cliente: "<<Nombre<<endl<<"No. Cuenta: "<<NumCuenta<<endl<<"Saldo Actual: "<<Saldo<<endl;
    
}



class Deudas
{
protected:
    int opcion;
    float Telcel;
    float Telmex;
    float CFE;
    float Dish;
    float SKY;
    float Agua;
    float Sears;
    float Movistar;
    
public:
    Deudas(int = 0, float = 0, float =0, float =0 ,float = 0,float = 0,float = 0,float =0,float = 0);
    bool SumarPago(void);
    float TotalDeudas(void);
    void OpcionElegida(int opc);
    void ImprimirPagos(void);
    void LimpiarDeudas(void);
    
    
};

Deudas::Deudas(int Opc,float Telc,float Telm,float cfe, float dis,float sk,float ag,float sea,float mov):opcion(Opc),Telcel(Telc),Telmex(Telm),CFE(cfe),Dish(dis),SKY(sk),Agua(ag),Sears(sea),Movistar(mov)
{
    
}

bool Deudas::SumarPago()
{
    switch (opcion)
    {
        case 1:
            
            if (Telcel == 0)
            {
                float x=1.15;
                float y=0.85;
                float a,b;
                cout<<"cuantas llamadas pagara?"<<endl;
                cin>>a;
                cout<<"cuantos mensajes pagara"<<endl;
                cin>>b;
                Telcel=((a*x)+(b*y));
                
                cout<<"USTED PAGARA"<<" "<<Telcel<<endl<<endl<<endl;
                
            }
            else
                return false;
            break;
        case 2:
            if (Telmex == 0)
            {
                
                int l, j=187,k,o;
                float m=317.15,a=1.77;
                do{
                    cout<<"øQUE PAGARA? \n"<<endl;
                    cout<<"1.SOLO TELEFONO \n"<<endl;
                    cout<<"2.SOLO INTERNET \n"<<endl;
                    cout<<"3.AMBOS \n"<<endl;
                    cout<<"4.SALIR \n"<<endl;
                    cin>>l;
                    
                    switch(l){
                        case 1:
                            cout<<"øCUANTOSMESES PAGARA?"<<endl;
                            cin>>k;
                            cout<<"øcuantas llamadas adicionales?"<<endl;
                            cin>>o;
                            if(o>=1){
                                Telmex=((o*a)+(j*k));
                                cout<<"SU PAGO ES DE:"<<" "<<Telmex<<endl<<endl;
                            }
                            else{
                                Telmex= j*k;
                                cout<<"SU PAGO ES DE:"<<" "<<Telmex<<endl<<endl;
                            }
                            break;
                            
                        case 2:
                            cout<<"øCUANTOS MESES PAGARA?"<<endl;
                            cin>>k;
                            Telmex=m*k;
                            cout<<"SU PAGO ES DE:"<<" "<<Telmex<<endl<<endl;
                            break;
                            
                        case 3:
                            cout<<"øCUANTOS MESES PAGARA?"<<endl;
                            cin>>k;
                            cout<<"øcuantas llamadas adicionales?"<<endl;
                            cin>>o;
                            if(o>=1){
                                Telmex=((o*a)+((j+m)*k));
                                cout<<"SU PAGO ES DE:"<<" "<<Telmex<<endl<<endl;
                            }
                            else{
                                Telmex= ((j+m)*k);
                                cout<<"SU PAGO ES DE:"<<" "<<Telmex<<endl<<endl;
                            }
                            break;
                            
                        case 4:
                            cout<<"\n SALIENDO BYE \n";
                            break;
                    }
                }
                
                while(l<4);
                
            }
            else
                return false;
            break;
            
            
        case 3:
            if (CFE == 0)
            {
                int f;
                float u=0.617;
                cout<<"øcuantos kilowatts gasto?"<<endl;
                cin>>f;
                CFE=f*u;
                cout<<"SU PAGO ES DE:"<<" "<<CFE<<endl<<endl<<endl;
                
            }
            else
                return false;
            break;
        case 4:
            if (Dish == 0)
            {
                cout<<"CUANTO DESEA PAGAR?"<<endl;
                cin>>Dish;
                
            }
            else
                return false;
            break;
        case 5:
            if (SKY == 0)
            {
                int g,a,e,b=299,h=615,f=415,u=719,c=75,y=125;
                float z;
                
                do{
                    cout<<"QUE SERVICIO TIENE? \n"<<endl;
                    cout<<"1. BASICO \n"<<endl;
                    cout<<"2.BASICO+HBO \n"<<endl;
                    cout<<"3.Basico+FUN \n"<<endl;
                    cout<<"4.BASICO+UNIVERSE \n"<<endl;
                    cout<<"5.SALIR \n"<<endl;
                    cin>>a;
                    
                    switch(a){
                        case 1:
                            cout<<"øCUANTOSMESES PAGARA?"<<endl;
                            cin>>e;
                            cout<<"øcuantos equipos adicionales tiene"<<endl;
                            cin>>g;
                            if(g==1){
                                SKY=(e*b)+y;
                                cout<<"SU PAGO ES DE:"<<z<<endl<<endl;
                                return z;
                            }
                            if(g>1){
                                SKY=((e*b)+(c*g));
                                cout<<"SU PAGO ES DE:"<<SKY<<endl<<endl;
                            }
                            break;
                            
                        case 2:
                            cout<<"øCUANTOSMESES PAGARA?"<<endl;
                            cin>>e;
                            cout<<"øcuantos equipos adicionales tiene"<<endl;
                            cin>>g;
                            if(g==1){
                                SKY=(e*h)+y;
                                cout<<"SU PAGO ES DE:"<<SKY<<endl<<endl;
                            }
                            if(g>1){
                                SKY=((e*h)+(c*g));
                                cout<<"SU PAGO ES DE:"<<SKY<<endl<<endl;
                            }
                            break;
                            
                        case 3:
                            cout<<"øCUANTOSMESES PAGARA?"<<endl;
                            cin>>e;
                            cout<<"øcuantos equipos adicionales tiene"<<endl;
                            cin>>g;
                            if(g==1){
                                SKY=(e*f)+y;
                                cout<<"SU PAGO ES DE:"<<SKY<<endl<<endl;
                            }
                            if(g>1){
                                SKY=((e*f)+(c*g));
                                cout<<"SU PAGO ES DE:"<<SKY<<endl<<endl;
                            }
                            break;
                            
                        case 4:
                            cout<<"øCUANTOSMESES PAGARA?"<<endl;
                            cin>>e;
                            cout<<"øcuantos equipos adicionales tiene"<<endl;
                            cin>>g;
                            if(g==1){
                                SKY=(e*u)+y;
                                cout<<"SU PAGO ES DE:"<<SKY<<endl<<endl;
                            }
                            if(g>1){
                                SKY=((e*u)+(c*g));
                                cout<<"SU PAGO ES DE:"<<SKY<<endl<<endl;
                            }
                            break;
                            
                        case 5:
                            cout<<"\n SALIENDO BYE \n";
                            //system("pause");
                            break;
                    }
                }
                while(a<5);
            }
            else
                return false;
            break;
            
        case 6:
            if (Agua == 0)
            {
                cout<<"CUANTO DESEA PAGAR?"<<endl;
                cin>>Agua;
            }
            else
                return false;
            break;
        case 7:
            if (Sears == 0)
            {
                cout<<"CUANTO DESEA PAGAR?"<<endl;
                cin>>Sears;            }
            else
                return false;
            break;
        case 8:
            if (Movistar == 0)
            {
                cout<<"CUANTO DESEA PAGAR?"<<endl;
                cin>>Movistar;
            }
            else
                return false;
            break;
            
        default:
            break;
    }
    
    return true;
}

float Deudas::TotalDeudas(void)
{
    return Telcel+Telmex+CFE+Dish+SKY+Agua+Sears+Movistar;
}

void Deudas::OpcionElegida(int Opc)
{
    opcion = Opc;
}

void Deudas::ImprimirPagos(void)
{
    cout<<"PAGOS: "<<endl;
    cout<<"Telcel:   "<<Telcel<<endl
    <<"Telmex:   "<<Telmex<<endl
    <<"CFE:   "<<CFE<<endl
    <<"Dish:   "<<Dish<<endl
    <<"Sky:   "<<SKY<<endl
    <<"Agua:   "<<Agua<<endl
    <<"Sears:   "<<Sears<<endl
    <<"Movistar:   "<<Movistar<<endl<<endl
    <<"Total de pagos:   "<<TotalDeudas()<<endl<<endl;
}

void Deudas::LimpiarDeudas(){
    
    Telcel = 0.0;
    Telmex = 0.0;
    CFE = 0.0;
    Dish = 0.0;
    SKY = 0.0;
    Agua = 0.0;
    Sears = 0.0;
    Movistar = 0.0;
    
}

struct Cliente: public Informacion, public Deudas
{
    
    struct Cliente *sig;
    struct Cliente *ant;
    
    float CalcularIVA(void);
    float CalcularCargo(void);
};

float Cliente::CalcularIVA(void)
{
    return TotalDeudas()*0.16;
}
float Cliente::CalcularCargo(void)
{
    return TotalDeudas()*0.03;
}






class Lista_doble{
private:
    struct Cliente *cab;
    struct Cliente *crear_nodo();
    
public:
    Lista_doble(){
        cab = NULL;
    }
    void insertar_inicio();
    void insertar_final();
    void recorrer_lista();
    void eliminar_nodo();
    void actualizar_nodo();
    Cliente* BuscarUsuario(long long int);
};

void Lista_doble::insertar_inicio(){
    struct Cliente *p;
    if(cab == NULL){
        cab = crear_nodo();
    }else{
        p = crear_nodo();
        p->sig = cab;
        cab->ant = p;
        cab = p;
    }
    cout << endl << "Nodo insertado" << endl << endl;
}


void Lista_doble::insertar_final(){
    struct Cliente *p;
    if(cab == NULL){
        cab = crear_nodo();
    }else{
        p = cab;
        while(p->sig != NULL){
            p = p->sig;
        }
   	    p->sig = crear_nodo();
   	    p->sig->ant = p;
    }
    cout << endl << "Nodo insertado" << endl << endl;
}


struct Cliente *Lista_doble::crear_nodo(){
    
    struct Cliente *n = new Cliente();
    
    n->LeerInformacion();

    n->sig = NULL;
    n->ant = NULL;
    return(n);
}


void Lista_doble::recorrer_lista(){
    
    struct Cliente *p = cab;
    if (p != NULL){
        while(p != NULL){
            
            p->Imprimir();
            p = p->sig;
            
        }
    }else{
        cout << "Lista vacia" << endl << endl;
    }
}

Cliente* Lista_doble::BuscarUsuario(long long int NewNumCuenta){

    struct Cliente *p = cab;
    
    if (p != NULL){
        while(p != NULL){
            
            if (p->RetornarCuenta() == NewNumCuenta) {
                return p;
            }
            p = p->sig;
            
        }
    }else{
        return NULL;
    }
    
    return NULL;
}


void Lista_doble::eliminar_nodo(){
    
    
   long long int NewNumCuenta;
    
    bool   encontrado = false;
    struct Cliente *p = cab;
    
    cout << "Escriba el Numero de Cuenta del contacto:\n";
    cin >> NewNumCuenta;
   
    
    while(p != NULL && encontrado != true){
        
        if(p->RetornarCuenta() == NewNumCuenta){
            
            encontrado = true;
            
        }else{
            p = p->sig;
        }
    }
    if(encontrado == false){
        cout << "Cuenta no registrado en la lista\n\n";
    }else{
        if(p == cab){
            cab = p->sig;
        }else if (p->sig == NULL){
            p->ant->sig = NULL;
            p->ant = NULL;
        }else{
            p->ant->sig = p->sig;
            p->sig->ant = p->ant;
        }
        delete p;
        cout << "Cuenta eliminada\n\n";
    }
}


void Lista_doble::actualizar_nodo(){
    
    long long int NewNumCuenta;
    
    struct Cliente *p = cab;
    bool   encontrado = false;
    cout << "Escriba la cuenta del contacto:\n";
    cin >> NewNumCuenta;
 
    while(p != NULL && encontrado != true){
   
        if(p->RetornarCuenta() == NewNumCuenta){
            
            encontrado = true;
            
            p->LeerInformacion();

            
        }else{
            p = p->sig;
        }
    }
    if(encontrado == false){
        cout << "Cuenta no registrada en la lista"<<endl<<endl;
    }
}




int main(int argc, const char * argv[])
{
    
    
    Lista_doble Lista;
    int op;
    
    do{
        cout << "Seleccione una operacion:\n";
        cout << "1) Iniciar Sesion\n";
        cout << "2) Registrar usuario\n";
        cout << "3) Eliminar Usuario\n";
        cout << "4) Mostrar Usuarios\n";
        cout << "0) Salir\n";
        cin >> op;
        system("cls");
        if(op == 1){
            //Iniciar Sesion :D
            long long int NewNumCuenta;
            cout<<"Numero de cuenta: ";
            cin>>NewNumCuenta;
            struct Cliente *Usuario = Lista.BuscarUsuario(NewNumCuenta);
            
            if (Usuario == NULL) {
                cout<<"Usuario no encontrado."<<endl;
            }else{
                //Usuario encontradoo proceder con menu de pagos:
                
                cout<<"Bienvenido: "<<Usuario->RetornarNombre()<<endl;
                
                
                int opcion;
                char option;
                do {
                    
                    cout<<"QUE PAGOS DESEA REALIZAR?"<<endl
                    <<"1.- TELCEL"<<endl
                    <<"2.- TELMEX"<<endl
                    <<"3.- CFE"<<endl
                    <<"4.- DISH"<<endl
                    <<"5.- SKY"<<endl
                    <<"6.- AGUA"<<endl
                    <<"7.- SEARS"<<endl
                    <<"8.- MOVISTAR"<<endl<<endl;
                    
                    
                    cin>>opcion;
                    
                    if (opcion <= 8) {
                        
                        Usuario->OpcionElegida(opcion);
                        
                        if (Usuario->SumarPago())
                        {
                            if(Usuario->TotalDeudas()>Usuario->RetornarSaldo())
                            {
                                cout<<"NO TIENE SALDO SUFICIENTE PARA REALIZAR EL PAGO "<<endl;
                                //system("pause");
                                return 0;
                            }
                            else
                            {
                                //Actualiza el nuevo saldo del usuario;
                                Usuario->NuevoSaldo(Usuario->RetornarSaldo() - Usuario ->TotalDeudas());
                                
                                cout<<"PAGO EXITOSO"<<endl;
                            }
                            
                            
                        }
                        else
                        {
                            cout<<"USTED YA REALIZO ESTE PAGO"<<endl;
                        }
                        
                        cout<<"DESEA REALIZAR OTRO PAGO? s/n"<<endl;
                        cin>>option;
                        
                        if (option != 's') {
                            break;
                        }
                        
                        
                    }
                    else
                    {
                        opcion = 0;
                        cout<<"LA SELECCION NO ESTA EN EL MENU PORFAVOR SELECCIONE UNA VALIDA";
                    }
                    
                } while (opcion<=8);
                
                
                
                cout<<"*************************************************** "<<endl;
                
                
                cout<<"SubTotal de PAGOS:   "<<Usuario->TotalDeudas()<<endl;
                cout<<"IVA:   "<<Usuario->CalcularIVA()<<endl;
                cout<<"CARGO:   "<<Usuario->CalcularCargo()<<endl;
                cout<<"TOTAL:   "<<Usuario->TotalDeudas() + Usuario->CalcularCargo()<<endl;
                
                cout<<"*************************************************** "<<endl;
                
                cout<<"Desea Imprimir esta informacion en un TXT s/n?"<<endl;
                cin>>option;
                
                if (option == 's') {
                    
                    ofstream myfile ("Cuenta.txt");
                    
                    if (myfile.is_open())
                    {
                        string Nombre = Usuario->RetornarNombre();
                        long long int NumCuenta = Usuario->RetornarCuenta();
                       
                        
                        
                        myfile << "Nombre : "<<Nombre<<endl;
                        myfile << "No. Cuenta: "<<NumCuenta<<endl;
                        myfile << "Saldo Actual: "<<Usuario->RetornarSaldo()<<endl;
                        
                        myfile<<"*************************************************** "<<endl;
                        
                        
                        myfile<<"SubTotal de PAGOS:   "<<Usuario->TotalDeudas()<<endl;
                        myfile<<"IVA:   "<<Usuario->CalcularIVA()<<endl;
                        myfile<<"CARGO:   "<<Usuario->CalcularCargo()<<endl;
                        myfile<<"TOTAL:   "<<Usuario->TotalDeudas() + Usuario->CalcularCargo()<<endl;
                        
                        myfile<<"*************************************************** "<<endl;
                        
                        
                        myfile.close();
                        
                        cout<<"se imprimio su txt. exitosamente, revise sus archivos con el nombre cuenta.txt"<<endl;
                    }
                    else cout << "NO SE PUEDE ABRIR ARCHIVO";
                }
                
                
                Usuario->LimpiarDeudas();
                cout<<"HASTA LUEGO"<<endl;
            
            }

            
        }else if(op == 2){
            Lista.insertar_inicio();
        }else if(op == 3){
            Lista.eliminar_nodo();
        }else if(op == 4){
            Lista.recorrer_lista();
        }else if(op != 0){
            cout << "Opcion no valida";
        }
    }while(op != 0);
    
    
    
}


