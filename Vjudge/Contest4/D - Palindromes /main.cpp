#include<cstdio>
#include<iostream>
#include<math.h>
#include<map>

using namespace std;
//Cálculo de hash polinomial para cadenas

//Para usar la palabra Long como long long int
typedef long long int Long;

//Seleccionamos un módulo P, de preferencia primo.
const Long P = 1000000033LL;

//Sugerencia : Si el módulo entre en un int, almacenarlo en un long long int, así como todas
//las variables involucradas en el hash. Si el módulo cabe en un long long int, entoces almacenarlo
//en un __int128, asi como todas las variables que tengan que ver con el hash.

//Seleccionamos una base. Debe ser mayora la cantidad de letras en el alfabeto a usar.
//Si usamos solo letras minúsculas, entonces debe ser mayor a 26, también se sugiere que sea primo
const Long B = 29LL;

//La cadena de la cuál queremos saber los hash
string s;
string s2;

//Una arreglo para guardar los hash de los prefijos de s
//H[i] contiene el hash del i-ésimo prefijo de s.
Long H[100002];
//Para llevar las potencias de B y conocerlas en contrante.
Long ExpB[100002];

//Una arreglo para guardar los hash de los prefijos de s
//H[i] contiene el hash del i-ésimo prefijo de s.
Long HInversa[100002];
//Para llevar las potencias de B y conocerlas en contrante.
Long ExpBInversa[100002];



//A cada caracter debemos asignarle un valor diferente
//Debe ser diferente a 0. Con el siguiente ejemplo, si trabajamos con solo letras
//minúsculas, asignamos a = 1, b = 2, ... , z = 26.
int valor(char c){
	return c - 'a' + 1;
}

//Calculamos los hashes de todos los prefijos de s.
//Ya que es un número constante de operaciones por cada caracter de s,
//entonces su complejidad es O(|s|)
//Adicionalmente calcularemos (B^0)%P, (B^1)%P, (B^2)%P, ..., (B^(|s|-1))
void Hashes(){
	H[0] = valor(s[0])%P; //Este es el Hash de s[0] solito
	ExpB[0] = 1; //ExpB[i] da el valor de (B^i)%P. B^0 = 1.
	for(int i = 1; i < s.size(); i++){
		//Sabemos que H[i] = H[i-1]*B + valor(s[i]), pero procedemos
		//con cuidado para no desbordar el resultado.
		H[i] = (B * H[i-1])%P;
		H[i] = (H[i] + valor(s[i]))%P;
		//Calculamos B^i como B^(i-1) * B
		ExpB[i] = (ExpB[i-1]*B)%P;
	}
}

void HashesInversa(){
	HInversa[0] = valor(s2[0])%P; //Este es el Hash de s[0] solito
	ExpBInversa[0] = 1; //ExpB[i] da el valor de (B^i)%P. B^0 = 1.
	for(int i = 1; i < s2.size(); i++){
		//Sabemos que H[i] = H[i-1]*B + valor(s[i]), pero procedemos
		//con cuidado para no desbordar el resultado.
		HInversa[i] = (B * HInversa[i-1])%P;
		HInversa[i] = (HInversa[i] + valor(s2[i]))%P;
		//Calculamos B^i como B^(i-1) * B
		ExpBInversa[i] = (ExpBInversa[i-1]*B)%P;
	}
}

//Da el hash de la subcadena de s que esté contenida entre las posición l y r ( l <= r ).
//Ya que solo son un par de sumas y restas, es constante: O(1)
//Hashes() debe llamarse antes.
Long Rango(int l, int r){
	if(l == 0) return H[r]; //Como sucedía en las sumas acumuladas.
	Long resta = (H[l-1]*ExpB[r-l+1])%P; // Calculamos lo que vamos a restar.
	// Ya que resta puede ser mayor que H[r], pero H[r], resta < P , entonces su resta R cumple con:
	// |R| < P => 0 <= P + H[r] - resta < P. Adicionalmentes a + P = a (mód P). Por lo tanto, así
	// debemos restar para evitar números negativos.
	Long ret = ( P + H[r] - resta)%P;
	return ret;
}

Long RangoInversa(int l, int r){
	if(l == 0) return HInversa[r]; //Como sucedía en las sumas acumuladas.
	Long resta = (HInversa[l-1]*ExpBInversa[r-l+1])%P; // Calculamos lo que vamos a restar.
	// Ya que resta puede ser mayor que H[r], pero H[r], resta < P , entonces su resta R cumple con:
	// |R| < P => 0 <= P + H[r] - resta < P. Adicionalmentes a + P = a (mód P). Por lo tanto, así
	// debemos restar para evitar números negativos.
	Long ret = ( P + HInversa[r] - resta)%P;
	return ret;
}

//Funciona como la función Hashes(), solo que no calcula todos los prefijos,
//solo la cadena completa, y tampoco calcula las potencias de B.
//Al pasar por todos los caractéres, es lineal : O(|s|)
Long unico(){
	Long ret = 0;
	for(int i = 0; i < s.size(); i++) {
		ret = (ret*B)%P;
		ret = (ret + valor(s[i]))%P;
	}
	return ret;
}

void reverseStr(string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}


int main() {
	// Read:
	int k;
    string originalS;
    cin>>k>>originalS;
	int len = originalS.length();

	// rellenar los hashes con el string original:
	s = originalS;
	s2 = originalS;
	reverseStr(s2);

	Hashes();
	HashesInversa();

	//ababab
	// 0 - 4
	// 1 - 5
	//bababa
	// 1 - 5
	// 0 - 4

    int palindromes = 0;
    for (int i=0; i <= len-k; i++) {
        s = originalS.substr(i,k); // get substring:
		if(Rango(i,i+k-1) == RangoInversa((len-i)-k,len-1-i)) {
            palindromes++;
        }
    }
    cout<<palindromes<<endl;
}
