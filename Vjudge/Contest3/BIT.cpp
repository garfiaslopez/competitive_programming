#include <bits/stdc++.h> //Importa todas las bibliotecas estandar
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie //Mejora la velocidad de cin y cout
using namespace std;
int N,Q; //Numero de elementos y numero de Querys
int L,R; //Se usan en cada query para tener el inicio y el fin
int A[100002]; //Arreglo de numeros
int B[100002]; //BIT
void Update(int pos,int val){ //Actualizamos
	while(pos <= N){
		//Se puede cambiar por la función que queramos adaptar
		B[pos] += val;
		pos += (pos&-pos);
	}
}
int Query(int pos){ //Query
	int ret = 0;
	while(pos > 0){
		//Se puede cambiar por la función que queramos adaptar
		ret += B[pos];
		pos -= (pos&-pos);
	}
	return ret;
}
int main(){
	optimizar_io(0);
	cin >> N ;
	for(int i = 1; i <= N; i ++){
		cin >> A[i];
		Update(i,A[i]);
	}
	cin >> Q;
	for(int i = 0; i < Q; i ++){
		cin >> L >> R;
		cout << Query(R) - Query(L-1)  << '\n';	//Usamos la Query como ya se había visto
		//Se puede cambiar por la función que queramos adaptar, cambiando la resta
		//por lo que sea necesario
	}
	return 0;
}
