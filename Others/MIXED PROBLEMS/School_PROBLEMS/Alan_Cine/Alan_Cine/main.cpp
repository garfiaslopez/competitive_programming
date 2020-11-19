//proyecto final
/* "Venta de Boletos"
 Alumno:alan andres luna gutierrez
 Boleta:  2014301054
 alumna:janeth berenice godinez reyes
 Boleta:2014302202
 */
#include<iostream>
using namespace std;

int Compara(int y);
void MenuPrincipal(void);


class Asiento
{
    friend class Sala;
private:
    char Columna;
    int Fila;
    bool Estado; //true vacio, false ocupado
    int Numero;
public:
    Asiento(char columna=' ',int fila=0,bool estado=true,int numero=0);
    
    
};

Asiento:: Asiento(char columna,int fila,bool estado,int numero):Columna(columna),Fila(fila),Estado(estado),Numero(numero)
{
}

/*************************************Clase Sala******************************/
class Sala
{
    friend class Pelicula;
private:
    Asiento *ApAs;
    int NumSala;
    string Pelicula;
    string Horario;
    int Disponibles;
    int Ocupados;
    int Totales;
public:
    Sala(Asiento *apas=NULL, int numsala=0,string pelicula=" ",string horario=" ",int disponibles=0,int ocupados=0,int totales=0);
    void CrearAs(int numsala, string pelicula,string horario);
    void Dibujar(void);
    void Comprar(void);
    char ValCol(char columna);
    void Ocupar (char columna,int fila);
    void Imprimir(void);

    
    ~Sala(void);
};

Sala:: Sala(Asiento *apas,int numsala,string pelicula,string horario,int disponibles,int ocupados,int totales):ApAs(apas),NumSala(numsala),Pelicula(pelicula),Horario(horario),Disponibles(disponibles),Ocupados(ocupados),Totales(totales)
{
}

Sala:: ~Sala(void)
{
    delete []ApAs;
}

void Sala:: CrearAs(int numsala, string pelicula,string horario)
{
    int Num=1,fila=1,j=0;
    char columna[6]={'A','B','C','D','E','F'}; //identificador para la columna
    
    ApAs=new Asiento[42]; //arreglo de asientos con 42 elementos
    
    NumSala=numsala;
    Pelicula=pelicula;
    Horario=horario;
    
    for(int i=0;i<42;i++) //Columna
    {
        ApAs[i].Columna=columna[j]; //asignacion de columna
        ApAs[i].Estado=true; //el asiento esta vacio
        ApAs[i].Numero=Num;
        ApAs[i].Fila=fila;
        Num++;
        j++;
        
        if(i==5||i==11||i==17||i==23||i==29||i==35)
        {
            fila++;
            j=0;
        } //fin If
        
    }// fin del for
    
}//fin Crear Asientos


void Sala:: Dibujar (void)
{
    char AsVacio=219,AsOcupado=176;
    int fila=1,num=0;
    Disponibles=0;
    Ocupados=0;
    Totales=0;
    
    //informacion de la sala
    
    gotoxy(30,4);cout<<Pelicula;
    gotoxy(30,6);cout<<Horario;
    gotoxy(13,1);cout<<"Sala "<<NumSala;
    
    gotoxy(5,3);cout<<"A   B   C   D   E   F"; //Letras de la columna
    
    for(int j=0;j<14;j+=2)
    {
        gotoxy(3,5+j);cout<<fila++; //Numeracion de las filas
        
        for(int i=0;i<24;i+=4)
        {
            gotoxy(5+i,5+j);
            
            if(ApAs[num].Estado) //Si el asiento esta vacio
            {
                cout<<AsVacio<<AsVacio;
                Disponibles++;
            }
            
            else //Si el asiento ya esta ocupado
            {
                cout<<AsOcupado<<AsOcupado;
                Ocupados++;
            }
            
            num++; //indice del asiento
            
        } //fin de for para columnas
        
    }//fin de for para filas
    
    Totales=Ocupados+Disponibles;
    
}


void Sala:: Comprar(void)
{
    char Opc='s',coma,columna;
    int fila;
    
    do
    {
        
        system("cls");
        Dibujar();
        
        cin>>Opc;
        
    } while(Opc=='n'||Opc=='N');
    
    switch(Opc)
    {
        case 's':
        case 'S': Ocupar(columna,fila); break;
    }
    
    Dibujar();

fin:;
    
}

char Sala:: ValCol(char columna)
{
    switch(columna)
    {
        case 'a': columna='A'; break;
        case 'b': columna='B'; break;
        case 'c': columna='C'; break;
        case 'd': columna='D'; break;
        case 'e': columna='E'; break;
        case 'f': columna='F'; break;
    }
    
    return columna;
    
}


void Sala:: Ocupar(char columna,int fila)
{
    
    columna=ValCol(columna); //Regresa las columnas como mayuscula
    
    if((columna=='A'||columna=='B'||columna=='C'||columna=='D'||columna=='E'||columna=='F')&&(fila>0&&fila<8))//Entra si el asiento existe
    {
        
        for(int i=0;i<42;i++) //Mira todos los asientos
        {
            
            if((ApAs[i].Columna==columna)&&(ApAs[i].Fila==fila))//Busca el asiento con esa fila y columna
            {
                
                if(ApAs[i].Estado!=0)//Si el asiento esta libre
                {
                    ApAs[i].Estado=0;
                }
                
                else //Si el asiento ya esta vendido
                {
                    cout<<"Asiento ocupado";
                    cout<<"Intente con otro";
                }//fin de else asiento no disponible
                
            }//fin de if columna/fila
            
        }//fin de for de asientos
        
    }//Fin de if de asientos disponibles
    
    else //Si el asiento no exisite
    {
        cout<<"Asiento no existe";
        cout<<"Intente con otro";
    }//fin de else si el asiento no existe
    
}//fin de funcion Ocupar

/*************************Funcion Imprimir Sala******************************/

void Sala:: Imprimir(void)
{
    
    char Opc='s';
    
    system("cls");
    
    do
    {
        Comprar();
        
        cout<<"Deseas comprar otra localidad [s/n]: ";
        cin>>Opc;
        
    } while(Opc=='S'||Opc=='s');
    
}

/***********************Clase Pelicula****************************************/

class Pelicula
{
    friend class Cine;
private:
    Sala *ApSal;
    int Ocupados;
public:
    Pelicula(Sala *apsal=NULL,int ocupados=0);
    void CrearSal(int NumSala, string Nombre);
    int Menu(int NumSala,string Nombre);
    void Imprimir(int NumSala, string Nombre);

    
    ~Pelicula(void);
};

Pelicula:: Pelicula(Sala *apsal,int ocupados):ApSal(apsal),Ocupados(ocupados)
{
}

void Pelicula:: CrearSal(int NumSala, string Nombre)
{
    string Horarios[4]={"12:30","14:30","16:30","18:30"};
    ApSal=new Sala[4];
    
    for(int i=0;i<4;i++)
        ApSal[i].CrearAs(NumSala,Nombre,Horarios[i]);
    
}

int Pelicula:: Menu(int NumSala,string Nombre)
{
    char OPC=' ',select=219;
    int Opc, y=3;
    
    cout<<" Sala: "<<NumSala<<" "<<Nombre;
    cout<<"  "<<Nombre<<" 12:30";
    cout<<"  "<<Nombre<<" 14:30";
    cout<<"  "<<Nombre<<" 16:30";
   cout<<"  "<<Nombre<<" 18:30";
    cout<<"  Regresar al Menu principal";
    cout<<"Usa nuestro navegador. La (m): para ir abajo";
    cout<<"& (k):para a ir arriba";
    cout<<"Presiona (x) para seleccionar";
    
    while(OPC!='x')
    {
        
        
        switch(OPC)
        {
            case 'm':
            case 'M':
                if(y<7)//Delimita el limite inferior del menu
                    y++; break;
            case 'k':
            case 'K':
                if(y>3)//Delimita el limite superior del menu
                    y--; break;
            case 'X':
            case 'x': Opc=Compara(y);break;
        }
    }
    
    return(Opc);
}

void Pelicula:: Imprimir(int NumSala, string Nombre)
{
    int Opc;
    char opc=' ';
    
    do
    {
        system("cls");
        
        Opc=Menu(NumSala,Nombre);
        
        switch(Opc)
        {
            case 1: ApSal[Opc-1].Imprimir();
                break;
            case 2: ApSal[Opc-1].Imprimir();
                break;
            case 3: ApSal[Opc-1].Imprimir();
                break;
            case 4: ApSal[Opc-1].Imprimir();
                break;
        }
        
        system("cls");
        
        if(Opc!=5)
        {
            cout<<"Deseas permanecer en el menu de horarios: [s/n] ";
            cin>>opc;
        }
        
    } while(Opc!=5&&opc!='n');
    
    for(int i=0;i<4;i++)
        Ocupados+=ApSal[i].Ocupados;
}

Pelicula:: ~Pelicula(void)
{
    delete []ApSal;
}

/****************************Clase Cine***************************************/

class Cine
{
    friend class Comprador;//clase cine tiene derecho a usar areas privadas de clase comprador
private:
    Pelicula *ApP;
    string *ApT;
    int Comprados;
public:
    Cine(Pelicula *App,string *Apt,int comprados=0);
    void Crear(void);
    void Menu(void);
    void Imprimir(void);

    
    ~Cine(void);
};

Cine:: Cine (Pelicula *App=NULL,string *Apt=NULL,int comprados):ApP(App),ApT(Apt),Comprados(comprados)
{
}

void Cine:: Crear(void)
{
    
    ApP=new Pelicula[5];
    ApT=new string[5];
    
    ApT[0]="*** 50 sombras de Grey***";
    ApT[1]="*** Bob esponja***";
    ApT[2]="*** A la mala***";
    ApT[3]="*** Birdman***";
    ApT[4]="*** Juegos del hambre,sinzajo parte I ***";
    
    for(int i=0;i<5;i++)
        ApP[i].CrearSal(i+1,ApT[i]);
    
}

void Cine:: Menu(void)
{
    cout<<" Mega Cinema Teatral";
    cout<<" Donde vive la magia del cine";
    cout<<"   Sala 1 "<<ApT[0];
    cout<<"   Sala 2 "<<ApT[1];
    cout<<"   Sala 3 "<<ApT[2];
    cout<<"   Sala 4 "<<ApT[3];
    cout<<"   Sala 5 "<<ApT[4];
    cout<<"   Salir";
    cout<<"Usa nuestro navegador. La (m): para ir abajo";
    cout<<"& (k):para a ir arriba";
    cout<<"Presiona (x) para seleccionar";
}


void Cine:: Imprimir(void)
{
    int y=3,Opc;
    char OPC=' ',opc,select=219;
    
    Menu();
    
    while(OPC!='x')
    {

        
        switch(OPC)
        {
            case 'm':
            case 'M':
                if(y<8)//Delimita el limite inferior del menu
                    y++; break;
            case 'k':
            case 'K':
                if(y>3)//Delimita el limite superior del menu
                    y--; break;
            case 'X':
            case 'x': Opc=Compara(y);break;
        }
    }
    
    while(Opc!=6)
    {
        
        switch(Opc)
        {
            case 1: ApP[Opc-1].Imprimir(1,ApT[0]);
                break;
            case 2: ApP[Opc-1].Imprimir(2,ApT[1]);
                break;
            case 3: ApP[Opc-1].Imprimir(3,ApT[2]);
                break;
            case 4: ApP[Opc-1].Imprimir(4,ApT[3]);
                break;
            case 5: ApP[Opc-1].Imprimir(5,ApT[4]);
                break;
        }
        
        system("cls");
        y=3;
        OPC=' ';
        
        Menu();
        
        while(OPC!='x')
        {
            
            
            
            switch(OPC)
            {
                case 'm':
                case 'M':
                    if(y<8)//Delimita el limite inferior del menu
                        y++; break;
                case 'k':
                case 'K':
                    if(y>3)//Delimita el limite superior del menu
                        y--; break;
                case 'X':
                case 'x': Opc=Compara(y); break;
            }//fin de switch(OPC)
        }//fin de while(OPC!='x')
    }//fin de while(Opc!=6)
    
    for(int i=0;i<5;i++)
        Comprados+=ApP[i].Ocupados;
    
}

Cine:: ~Cine(void)//destrucion de constructor
{
    delete []ApP;//eliminar memoria dinamica de app
    delete []ApT;//eliminar memoria dinamica de apt
}

/********************************Clase Comprador*******************************/

class Comprador
{
private:
    string Nombre;
    
public:
    Comprador(string nombre=" ");
    void Leer(void);
    void Factura(int Total);
    int CalTotal(Cine &RefCine);

    
};

Comprador:: Comprador(string nombre):Nombre(nombre)//constructor parametrizado
{
}

void Comprador:: Factura(int Total)
{
    gotoxy(2,2);cout<<"Gracias por usar nuestro Software de compra virtual";
    gotoxy(2,6);cout<<Nombre;
    gotoxy(2,8);cout<<"Usted Compro "<<Total<<" boletos";
    gotoxy(2,9);cout<<"Su total es de "<<Total*30<<"$";
    gotoxy(2,12);system("pause");
}

void Comprador:: Leer(void)
{
    fflush(stdin);
    gotoxy(16,10); cout<<"A nombre de quien deseas facturar: ";
    getline(cin,Nombre);
}


int Comprador:: CalTotal(Cine &RefCine)
{
    return(RefCine.Comprados);
}

/*******************************Funcion Principal*****************************/

int main (void)
{
    Comprador Cliente;//usa clase comprador
    Cine MegaCine;
    
    MegaCine.Crear();
    
    system("color 5B");
    system("cls");
    
    MenuPrincipal();
    
    Cliente.Leer();
    system("cls");
    
    MegaCine.Imprimir();
    
    system("cls");
    
    Cliente.Factura(Cliente.CalTotal(MegaCine));
    
    return 1;
    
}

/*****************************Funcion Compara**********************************/

int Compara(int y)
{
    switch(y)
    {
        case 3: return 1;break;
        case 4: return 2;break;
        case 5: return 3;break;
        case 6: return 4;break;
        case 7: return 5;break;
        case 8: return 6;break;
    }
}

/********************Funcion Menu Principal************************************/

void MenuPrincipal(void)
{
    char Carga=219;
    
    cout<<"Cargando base de datos";
    
    for(int i=0;i<21;i++)
    {
        gotoxy(25+i,4);cout<<Carga;
        Sleep(50);
    }
    
    system("cls");
    gotoxy(15,3);cout<<"Bienvenido a nuestro Software de compra virtual";
} 
