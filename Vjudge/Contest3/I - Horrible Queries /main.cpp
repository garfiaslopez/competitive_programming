// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
#include <cstdio>
#include <iostream>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
const int INF = INT_MAX; //Definimos nuestro infinito

int N;	// Numero de elementos
int Q;  // Numero de querys
int L,R;// Para el incio y fin de querys, respectivamente

int Arr[100004]; //Arreglo de numeros iniciales
int C[100004]; //Arreglo de cambios
int ST[400004];//Se lleva el segment Tree


//Lazy update
int valor;

/*
	IMPORTANTE :

	Por la forma del árbol, el tamaño del arreglo ST debe ser 4 veces del tamaño arreglo
	original, es decir, 4*N.

	De igual forma, funciona con valores de N que no sean potencias de 2. Por ejemplo,
	para 7, se partiría en 2 pedazos, uno de 4 y uno de 3. Después el de 4 en dos de tamaño 2.
	Y el de 3, en dos pedazos, uno de tamaño 2 y otro de tamaño 1.

*/


//Va calculando los rangos y sus respuestas
//ini es el inicio del rango a guardar, y fin el final.
//pos es el índice del nodo en el que nos encontramos.
void Crea(int ini,int fin,int pos){

	//Si ini == fin, entonces es porque ya es una hoja del árbol.
	if(ini == fin){
		//Arr la hoja le asignamos el valor de Arr[ini]
		ST[pos] = Arr[ini];
		return;
	}

	//Si no es hoja, debemos calcular sus hijos.
	int mitad = (ini+fin)/2;
	Crea(ini,mitad,pos*2+1);
	Crea(mitad+1,fin,pos*2+2);

	//Ya que tenemos la respuesta de nuestros hijos
	//Podemos calcular la respuesta para el nodo actual de la siguiente forma
	//Se puede cambiar por la función que queramos adaptar
	ST[pos] = (ST[pos*2+1] + ST[pos*2+2]);

}

/*

IMPORTANTE:

No es necesario, para cada nodo, a que rango corresponde,
ya que, cada vez que hagamos un recorrido, necesitamos empezar en la raiz.
En la raiz sabemos que el rango es [0,N-1]. Por lo tanto, el inicio y fin los podemos
llevar siempre en los parámetros y nos ahorramos espacio en memoria.

*/

void Propagation(int ini, int fin, int pos) {
    if (C[pos] == 0) {
        return;
    } else {
        ST[pos] = (fin - ini + 1) * C[pos];
        C[2*pos] = C[pos];
        C[2*pos+1] = C[pos];
        C[pos] = 0;
    }
}


//Preguntar por el menor entre inir y finr.
//pos indica el índice del nodo en el que estamos
//ini es el inicio del rango correspondiente al nodo con índice 'pos'
//fin es el final del rango correspondiente al nodo con índice 'pos'

int Query(int ini,int fin,int pos, int a, int b){

	if ((a<ini && b<fin) || (a>ini && b>fin)) {
        Propagation(ini,fin,pos);
        return 0;
    }


	//Pregunta si el rango actual está completamente contenido en la Query
	//Es decir, si es un segmento fundamental
	if(a>=ini && b<= fin) return ST[pos];

	//Esto es para el tercer caso

	int izq = Query(ini,(ini+fin)/2,pos*2+1,a,b);
	int der = Query((ini+fin)/2+1,fin,pos*2+1,a,b);

	//Se puede cambiar por la función que
	//queramos adaptar
	return (izq + der);

}

//Actualiza el ST, cambiando el valor del elemento en la posición 'posu', por el valor 'val'
//pos indica el índice del nodo en el que estamos
//ini es el inicio del rango correspondiente al nodo con índice 'pos'
//fin es el final del rango correspondiente al nodo con índice 'pos'

void Update(int ini,int fin,int pos,int posu, int val){
	//Si el rango correspondiente a 'pos' no contiene a 'posu'
	if(fin < posu || posu < ini) return;
	//Si el rango correspondiente al nodo pos va de 'posu' a 'posu'
	if(ini == posu && fin == posu){
		//Si esto sucede, es porque estamos en la hoja correspondiente
		//a la posicion 'posu' del arreglo original
		ST[pos] = val;
		do{
			//Una vez modificado, nos iremos al padre del nodo actual
			//y después actualizamos su valor comparando a sus hijos
			pos = (pos-1)/2;
			//Se puede cambiar por la función que
			//queramos adaptar
			ST[pos] = (ST[pos*2+1] + ST[pos*2+2]);
		}while(pos != 0); //Repetir hasta no llegar a la raiz
		return;
	}
	//Si aun no llegamos a la hoja, buscar entre sus 2 hijos.
	int mitad = (ini+fin)/2;
	Update(ini,mitad,pos*2+1,posu,val);
	Update(mitad+1,fin,pos*2+2,posu,val);
}


void LazyUpdate(int pos,int ini, int fin, int a, int b){
	Propagation(ini,fin,pos);
    if (a>=ini && b<=fin) { // totalmente contenido
        ST[pos] = valor * (fin - ini + 1);
        C[2*pos] = 1;
        C[2*pos+1] = 1;
        return;
    }
    if ((a<ini && b<fin) || (a>ini && b>fin)) {
        LazyUpdate(2*pos, ini, (ini + fin)/ 2, a, b);
        LazyUpdate(2*pos+1,(ini+fin)/2+1,fin, a, b);
        ST[pos]=ST[pos*2] + ST[pos*2+1];
    }
}

int main(){
	optimizar_io(0);
    int CasesGeneral;
    cin >> CasesGeneral;

    while (CasesGeneral--) {
    	cin >> N;
        cin >> Q;
        for(int i=0; i<=N; i++) {
            Arr[i] = 0;
            C[i] = 0;
        }


        //Siempre es necesario antes de usar las funciones Query y Update
    	Crea(0,N,0);
    	for(int i=0; i<Q; i++) {
            int typeQ;
            cin >> typeQ;
            if (typeQ == 0) { // ADD:
                int p,q,v;
                cin >> p >> q >> v;
                valor=v;
                for (int pos=p; pos<=q; pos++) {
                    LazyUpdate(0, N, pos, p, q);
                }
            } else { // FIND:
                cin >> L >> R;
                cout << Query(0,N,0, L, R) << '\n';
            }
        }
    }

	return 0;
}
