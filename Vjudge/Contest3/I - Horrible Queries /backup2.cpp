
//Probado en problema: http://coj.uci.cu/24h/problem.xhtml?pid=3333

#include <cstdio>
#include <iostream>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie //Mejora la velocidad de cin y cout
using namespace std;

int N,Q; //Numero de elementos y numero de Querys
int L,R; //Se usan en cada query para tener el inicio y el fin

int A[100002]; //Arreglo de numeros
int B[100002]; //BIT

void Update(int pos, int fin, int val){ //Actualizamos
	while(pos <= N && pos <= fin){
		B[pos] = val;
		pos += (pos&-pos);
	}
}

int Query(int pos){ //Query
	int ret = 0;
	while(pos > 0){
		//Se puede cambiar por la función que queramos adaptar
		ret = B[pos];
		pos -= (pos&-pos);
	}
	return ret;
}

int main(){
	optimizar_io(0);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> N;
        cin >> Q;
    	for(int i = 1; i <= N; i ++){
    		cin >> A[i];
            Update(i,N,A[i]);
    	}
        for(int i=0; i<Q;i++) {
            int QType;
            cin >> QType;
            if (QType == 0) { // add
                int p,q,v;
                cin>>p>>q>>v;
                Update(p,q,v);
            } else { // query
                cin >> L >> R;
        		cout << Query(R) + Query(L-1)  << '\n';
            }
        }
    }
	return 0;
}
