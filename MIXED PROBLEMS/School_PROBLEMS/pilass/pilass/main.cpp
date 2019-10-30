//
//  main.cpp
//  pilass
//
//  Created by Jose De Jesus Garfias Lopez on 20/02/15.
//  Copyright (c) 2015 Jose De Jesus Garfias Lopez. All rights reserved.
//

// ListaAll.cpp Programa de prueba de la clase Lista con estructura Nodo.

#include <iostream>
#include <iomanip>
using namespace std;

struct Nodo
{ //Nodo
    
    string Nombre; // datos
    Nodo *siguiente; // siguiente nodo en la lista
    
}; // fin de la estructura Nodo

class Lista
{
    
private:
    
    Nodo *primero; // apuntador al primer nodo
    Nodo *ultimo; // apuntador al ˙ltimo nodo
    
public:
    
    Lista(); // constructor
    ~Lista(); // destructor
    bool estaVacia() const;
    void insertarAlFinal( string );
    bool eliminarDelFinal( string );
    void imprimir() const;
    
    // funciÛn utilitaria para asignar un nuevo nodo
    
    Nodo *obtenerNuevoNodo( string );
    
}; // fin de la clase Lista

// constructor predeterminado

Lista::Lista() : primero( 0 ), ultimo( 0 )
{
    
} // fin del constructor de Lista

Lista::~Lista()
{ // destructor
    
    if ( !estaVacia() ) // la Lista no est· vacÌa
    {
        
        cout << "Destruyendo nodos ...\n";
        Nodo *actual = primero;
        Nodo *temp;
        
        while ( actual != 0 ) // elimina los nodos restantes
        {
            
            temp = actual;
            cout << temp->Nombre << '\n';
            actual = actual->siguiente;
            
            delete temp;
            
        } // fin de while
        
    } // fin de if
    
    cout << "Se destruyeron todos los nodos\n\n";
    
} // fin del destructor de Lista


// inserta un nodo al final de la lista

void Lista::insertarAlFinal( string nombre )
{
    Nodo *nuevo = obtenerNuevoNodo( nombre ); // nuevo nodo
    
    if ( estaVacia() ) // la Lista est· vacÌa
        
        primero = ultimo = nuevo; // la nueva lista sÛlo tiene un nodo
    
    else // la Lista no est· vacÌa
    {
        
        ultimo->siguiente = nuevo; // actualiza el nodo que antes era el ˙ltimo
        
        ultimo = nuevo; // nuevo ˙ltimo nodo
        
    } // fin de else
    
} // fin de la funciÛn insertarAlFinal

// elimina un nodo de la parte final de la lista

bool Lista::eliminarDelFinal( string nombre )
{
    
    if ( estaVacia() ) // la Lista est· vacÌa
        return false; // la eliminaciÛn no tuvo Èxito
    
    else
    {
        
        Nodo *temp = ultimo; // contiene tempPtr a eliminar
        
        if ( primero == ultimo ) // la Lista tiene un elemento
            primero = ultimo = 0; // no hay nodos despuÈs de la eliminaciÛn
        
        else
            
        {
            
            Nodo *actual = primero;
            
            // localiza el pen˙ltimo elemento
            
            while ( actual->siguiente != ultimo )
                
                actual = actual->siguiente; // se desplaza al siguiente nodo
            
            ultimo = actual; // elimina el ˙ltimo nodo
            
            actual->siguiente = 0; // ahora Èste es el ˙ltimo nodo
            
        } // fin de else
        
        nombre = temp->Nombre; // devuelve el valor del nodo que antes era el ˙ltimo
        
        delete temp; // reclama el nodo que antes era el ˙ltimo
        
        return true; // la eliminaciÛn tuvo Èxito
        
    } // fin de else
    
} // fin de la funciÛn eliminarDelFinal

// øest· la Lista vacÌa?

bool Lista::estaVacia() const
{
    
    return primero == 0;
    
} // fin de la funciÛn estaVacia

// devuelve el apuntador al nodo reciÈn asignado

Nodo *Lista::obtenerNuevoNodo( string nombre )
{
    
    Nodo *Nuevo = new Nodo;
    
    Nuevo->Nombre = nombre;
    
    Nuevo->siguiente = 0;
    
    return Nuevo;
    
} // fin de la funciÛn obtenerNuevoNodo

// muestra el contenido de la Lista

void Lista::imprimir() const
{
    
    if ( estaVacia() ) // la Lista est· vacÌa
    {
        cout << "La lista esta vacia\n\n";
        
        return;
    } // fin de if
    
    Nodo *actual = primero;
    
    cout << "La lista es: ";
    
    while ( actual != 0 ) // obtiene los datos del elemento
    {
        cout << actual->Nombre << ' ';
        actual = actual->siguiente;
        
    } // fin de while
    
    cout << "\n\n";
    
} // fin de la funciÛn imprimir

// muestra las instrucciones del programa al usuario

void instrucciones()
{
    cout << "Escriba una de las siguentes opciones:\n"
    << " 1 Insertar al final de la lista\n"
    << " 2 Eliminar del final de la lista\n"
    << " 3 Terminar el procesamiento de la lista\n"
    << endl;
    
} // fin de la funciÛn instrucciones

// funciÛn para evaluar una Lista

void probarLista( Lista &objetoLista )
{
    cout << "Prueba de una Lista de valores enteros \n" << endl;
    
    int opcion; // almacena la opciÛn del usuario
    
    string Nombre; // almacena el valor de entrada
    
    do // realiza las acciones seleccionadas por el usuario
    {
        instrucciones(); // muestra las instrucciones
        cout << "Opcion: ";
        cin >> opcion;
        
        switch ( opcion )
        {
                
            case 1: // inserta al final
                
                cout << "Escriba Nombre: " << ": ";
                cin.ignore();
                getline(cin, Nombre);
                objetoLista.insertarAlFinal( Nombre );
                objetoLista.imprimir();
                
                break;
                
            case 2: // elimina del final
                
                if ( objetoLista.eliminarDelFinal( Nombre ) )
                    cout << Nombre << " se elimino de la lista\n";
                objetoLista.imprimir();
                
                break;
                
        } // fin de switch
        
        system("PAUSE");
        system("CLS");
        
    } while ( opcion != 3 ); // fin de do...while
    
    cout << "Fin de la prueba de la lista\n\n";
    
} // fin de la funciÛn probarLista

int main()
{
    // prueba Lista de valores int
    Lista listaEnteros;
    
    probarLista( listaEnteros ); 
    
    return 0;
    
} // fin de main
