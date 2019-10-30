#include <iostream>
#include<iomanip>
#include <fstream>
#include <sstream>



using namespace std;


template <typename T>
string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}


class Prestacion;//Prototipo de clase


//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨Clase Fecha en amistada con Prestacion para calcular bonos¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
class Fecha
{
    friend class Prestacion;
private:
    int Dia;
    int Mes;
    int Anhio;
	   char D;
public:
    Fecha (int dia=1, int mes=1, int anhio=2000);
    void Leer (void);
    int Compara(Fecha &F2);
    bool ValCom(int Comp);
    Fecha Gesta(void);
    void Imprimir (void);
};
//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨Constructor Fecha¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
Fecha ::Fecha (int dia, int mes, int anhio): Dia(dia),Mes(mes),Anhio(anhio)
{
}
//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨Leer¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
void Fecha ::Leer (void)
{
    static string K="actual";
    cout<<"  Ingrese la fecha (DD/MM/AA) "<<K<<endl;
    cout<<"  ";
    cin>>Dia>>D>>Mes>>D>>Anhio;
    
    K="de Ingreso";
}
//¨¨¨¨¨¨¨¨¨¨¨¨¨Valida las fechas a comparar¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
bool Fecha:: ValCom(int Comparacion)
{
    bool Bal=false;
    
    if(Comparacion>=1)
    {
        Bal=true;
    }
    else
    {
        cout<<"Error alguna fecha es invalida "<<endl;
        
        cout<<endl<<"Ingrese nuevamente las fechas "<<endl;
        
        static string K="actual";
        
        cout<<"  ";
        
        cout<<"Ingrese la fecha (DD/MM/AA) "<<K<<endl;
        cin>>Dia>>D>>Mes>>D>>Anhio;
        
        K="de Ingreso";
    }
    
    return Bal;
}

//¨¨¨¨¨¨¨¨¨¨¨¨¨Funcion comparar Fechas¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
int Fecha::Compara(Fecha &F2)
{
    int Com=0;
    
    bool Ban=false;
    
    Com=F2.Anhio-Anhio;
    
    Ban=ValCom(Com);
    
    if(Ban==true)
    {
        if (Com>=1)
        {
            if(F2.Mes>=Mes)
            {
                if(F2.Dia>=Dia)
                {
                    Com=F2.Anhio-Anhio;
                }
                
            }
            else
            {
                Com=(F2.Anhio-Anhio)-1;
            }
        }
    }
    return Com;
}
//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨Funcion calcula fechas de descanso para embarazadas¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
Fecha Fecha :: Gesta(void)
{
    Fecha FPP,FUM;
    
    cout<<"  Ingrese la fecha (DD/MM/AA) "<<endl;
    cout<<"  ";
    
    cin>>FUM.Dia>>D>>FUM.Mes>>D>>FUM.Anhio;
    
    FPP.Dia=FUM.Dia+7;
    FPP.Mes=FUM.Mes-3;
    FPP.Anhio=FUM.Anhio+1;
    
    
    return(FPP);
}


//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨Imprime Fecha¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
void Fecha :: Imprimir (void)
{
    cout<<"La fecha es: "<<setfill('0')<<setw(2)<<Dia<<"/"
    <<setw(2)<<Mes<<"/"<<setw(4)<<Anhio<<endl;
}
//************************Clase Prestacion************************************

class Prestacion
{
private:
    char Sexo;
    string Seguro;
    Fecha FI,FA,FC;
    int DiaEx;
    int Anti;
    
    
    
public:
    Prestacion(string seguro=" ",char Sexo=' ',int DiaEx=0,int Anti=0);
    void Leer (void);
    void Bonos(void);
    void Vacaciones(void);
    
    void Imprimir (void);
    void RetornaPrestacion();
};

//***************************constructor***************************************
Prestacion::Prestacion(string seguro,char sexo,int diaex,int anti):Seguro(seguro),Sexo(sexo),DiaEx(diaex),Anti(anti)
{
}
//***************************leer***************************************
void Prestacion:: Leer (void)
{
    cout<<"Ingrese sexo (f/m)"<<endl;
    cout<<"  ";
    cin>>Sexo;
    cin.ignore();
    cout<<"Ingrese el seguro"<<endl;
    cout<<"  ";
    getline(cin,Seguro);
    cout<<endl;
    system("pause");
    system("cls");
    FA.Leer();
    FI.Leer();
}

//***************************Bonos***************************************
void Prestacion:: Bonos (void)
{
    
    bool Com=false;
    double Sal=0;
    int Dias=0;
    
    Anti=FI.Compara(FA)*12;
    
    
    Com=FI.ValCom(Anti/12);
    
    if (Com==true)
    {
        cout<<"Bonos"<<endl;
        
        do
        {
            if (Anti==(60)|| Anti==(120)||Anti==(180)|| Anti==(240))
            {
                cout<<"  Pago de prima por Antiguedad "<<endl;
            }
            else
            {
                cout<<"  No cumple para el premio de Antiguedad";
                cout<<"  Tu antiguedad es: "<<(Anti/12)<<" anhios "<<endl;
            }
            
        }while (Anti==(300));
        system("pause");
        system("cls");
        
        Dias=(Anti/12)*20;
        
        cout<<endl<<"\n  Te corresponden "<<Dias<<" dias de descanso por laborar "<<Anti/12<<"anhios"<<endl;
        
        cout<<"  Ingresa nuevamente tu sueldo en pesos"<<endl;
        cout<<"  ";
        cin>>Sal;
        
        if (Anti>=12)
        {
            cout<<"  Recibiras "<<(Sal/15)*40<<" pesos de aguinaldo"<<endl;
        }
        
        cout<<"  Cuantos domingos trabajaste?"<<endl;
        cout<<"  ";
        cin>>DiaEx;
        
        if (DiaEx>=1)
	       {
               cout<<"  Recibiras "<<(Sal*0.25)<<" pesos extras por laborar en domingo"<<endl;
           }
        
    }
    
}

//***************************Vacaciones***************************************

void Prestacion :: Vacaciones (void)
{
    char E=' ';
    int part=0;
    Fecha Ges;
    string Mes=" ";
    
    
    if (Sexo=='f'||Sexo=='F')
    {
        cout<<endl<<"  øEsta embarazada?(s/n)"<<endl;
        cout<<"  ";
        cin>>E;
        
        if(E=='s'||E=='S')
        {
            cout<<"\n  ingrese FUM (Fecha Ultima de Menstruacion)\n";
            
            Ges=Ges.Gesta();
            cout<<"\n  La FPP (fecha de probable parto) es ";
            Ges.Imprimir();
            
            part=Ges.Mes;
            
            
            if((part-1)<=0)
            {
                cout<<"\n  Por lo tanto descansaras desde "<<(part*12)-1<<" hasta "<<part+1<<endl;
            }
            else
            {
                cout<<"\n  Por lo tanto descansaras desde "<<part-1<<" hasta "<<part+1<<endl;
            }
            
        }
        
    }
    
    
}

//***************************Imprimir***************************************
void Prestacion:: Imprimir (void)
{
    Bonos();
    Vacaciones();
}


//*************Clase Persona****************************************************
class Persona
{
private:
    string Nom;
    int Edad;
    string RFC;
    
public:
    Persona(string nom=" ",string rfc=" ",int edad=0);
    void Leer (void);
    void Imprimir (void);
    string RetornaDatos(void);
    
};

//***************************constructor***************************************

Persona::Persona(string nom,string rfc,int edad):Nom(nom),RFC(rfc),Edad(edad)
{
}

//***************************leer***************************************

void Persona::Leer (void)
{
    cout<<"DATOS PERSONALES: \n\n\n"<<endl;
    system("pause");
    system("cls");
    cin.ignore();
    cout<<"Ingrese el Nombre del empleado: "<<endl;
    cout<<"  ";
    getline (cin,Nom);
    cout<<"Ingrese RFC:"<<endl;
    cout<<"  ";
    getline(cin,RFC);
    cout<<"Ingrese la edad:"<<endl;
    cout<<"  ";
    cin>>Edad;
    system("pause");
    system("cls");
    
}

//***************************Imprimir***************************************
void Persona:: Imprimir (void)
{
    system("pause");
    system("cls");
    cout<<"El Nombre es: "<<Nom<<endl;
    cout<<"RFC: "<<RFC<<endl;
    cout<<"La edad es: "<<Edad<<endl;
}


string Persona::RetornaDatos(void){
    
    string S_Edad = NumberToString(Edad);

    return "El Nombre Es: " + Nom + " \nRFC: " + RFC + "\nEdad: " + S_Edad + "\n";

}
//∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞Empleado principal∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞

struct Empleado
{
    Persona P;
    double Sal;
    double Imp;
    int NumEmpleado;
    Prestacion Pres;
    
    Empleado *sig;
    Empleado *ant;
    
    void LeerEmpleado();
    void ImprimirEmpleado();
    string RetornaDatosEm();

};


void Empleado::LeerEmpleado(){
    
    P.Leer();
    Pres.Leer();

    cout<<"DATOS EMPRESARIALES \n\n\n"<<endl;
    system("pause");
    system("cls");
    cout<<"Salario del Empleado en pesos: ";
    cout<<"  ";
    cin>>Sal;
    cout<<"Numero de Empleado: ";
    cout<<"  ";
    cin>>NumEmpleado;
    cout<<"Tasa de interes del Empleado: ";
    cout<<"  ";
    cin>>Imp;
    cout<<endl;
    
}

void Empleado::ImprimirEmpleado(){

    P.Imprimir();
    cout<<"No. Empleado: "<<endl<<NumEmpleado<<endl;
    cout<<"El salario del empleado es"<<Sal<<" pesos"<<endl;
    system("pause");
    system("cls");
    Pres.Imprimir();
    
}

string Empleado::RetornaDatosEm(){
    
    
    string S_Sal = NumberToString(Sal);

    return "Salario: " + S_Sal +" \n";

}

//∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞CLASE DE LA LISTA ∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞

class Lista_doble{
    
private:
    struct Empleado *cab;
    struct Empleado *crear_nodo();
    
public:
    Lista_doble(){
        cab = NULL;
    }
    void insertar_inicio();
    void insertar_final();
    void recorrer_lista();
    void eliminar_nodo();
    void actualizar_nodo();
    void exportar_lista();

    Empleado* BuscarUsuario(int);
};

void Lista_doble::insertar_inicio(){
    struct Empleado *p;
    if(cab == NULL){
        cab = crear_nodo();
    }else{
        p = crear_nodo();
        p->sig = cab;
        cab->ant = p;
        cab = p;
    }
    cout << endl << "Empleado Agregado Exitosamente" << endl << endl;
}


void Lista_doble::insertar_final(){
    struct Empleado *p;
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
    cout << endl << "Empleado Agregado Exitosamente " << endl << endl;
}


struct Empleado *Lista_doble::crear_nodo(){
    
    struct Empleado *n = new Empleado();
    
    n->LeerEmpleado();
    
    n->sig = NULL;
    n->ant = NULL;
    return(n);
}


void Lista_doble::recorrer_lista(){
    
    struct Empleado *p = cab;
    if (p != NULL){
        while(p != NULL){
            
            p->ImprimirEmpleado();
            p = p->sig;
            
        }
    }else{
        cout << "Lista vacia" << endl << endl;
    }
}

Empleado* Lista_doble::BuscarUsuario(int NewNumEmpleado){
    
    struct Empleado *p = cab;
    
    if (p != NULL){
        while(p != NULL){
            
            if (p->NumEmpleado == NewNumEmpleado) {
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
    
    
    int NewNumEmpleado;
    
    bool   encontrado = false;
    struct Empleado *p = cab;
    
    cout << "Escriba el Numero de empleado:\n";
    cin >> NewNumEmpleado;
    
    
    while(p != NULL && encontrado != true){
        
        if(p->NumEmpleado == NewNumEmpleado){
            
            encontrado = true;
            
        }else{
            p = p->sig;
        }
    }
    if(encontrado == false){
        cout << "Empleado no registrado en la lista\n\n";
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
        cout << "Empleado eliminado\n\n";
    }
}


void Lista_doble::actualizar_nodo(){
    
    int NewNumEmpleado;
    
    struct Empleado *p = cab;
    bool   encontrado = false;
    cout << "Escriba el numero de empleado:\n";
    cin >> NewNumEmpleado;
    
    while(p != NULL && encontrado != true){
        
        if(p->NumEmpleado == NewNumEmpleado){
            
            encontrado = true;
            
            p->LeerEmpleado();
            
            
        }else{
            p = p->sig;
        }
    }
    if(encontrado == false){
        cout << "Empleado no registrado en la lista"<<endl<<endl;
    }
}

//∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞EXPORTACION DE LA LISTA ∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞

void Lista_doble::exportar_lista(){
    
    struct Empleado *p = cab;
    if (p != NULL){
        
        
        ofstream myfile ("Empleados.txt");
        
        if (myfile.is_open())
        {
            while(p != NULL){
            
                myfile<<"*************************************************** "<<endl;
                myfile << p->P.RetornaDatos();
                myfile << p->RetornaDatosEm();
                
                p = p->sig;
            
            }
            
            myfile.close();
            
            cout<<"Se exporto su txt. exitosamente, revise sus archivos con el nombre Empleados.txt"<<endl;
            
        }
        else cout << "NO SE PUEDE ABRIR ARCHIVO";
        
    }else{
        cout << "Lista vacia" << endl << endl;
    }
}



int main() {

    
    Lista_doble Lista;
    
    int opcion;
    
    do{
        cout<<"Lista  De  Empleados: "<<endl;
        cout<<"1.-Insertar Empleado"<<endl;
        cout<<"2.-Eliminar Empleado"<<endl;
        cout<<"3.-Imprimir"<<endl;
        cout<<"4.-Exportar Lista (TXT)"<<endl;
        cout<<"5.-Salir."<<endl;
        
        cout<<"Ingrese opcion"<<endl;  cin>>opcion;
        
        switch(opcion)
        {
                
            case 1:
                Lista.insertar_inicio();
                break;
                
            case 2:
                Lista.eliminar_nodo();
                break;
                
            case 3:
                Lista.recorrer_lista();
                break;
            case 4:
                Lista.exportar_lista();
                break;
                
            case 5:
                cout<<"Hasta Luego"<<endl;
                break;
                
                
            default:
                cout<<"Opcion invalida."<<endl;
                break;
                
                
        }
        system("cls");
    }while(opcion!=5);

    
    
    return 0;
}
