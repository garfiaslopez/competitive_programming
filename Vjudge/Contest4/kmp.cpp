string s,t;
//Saber en que posiciones t es subcadena de s
//La complejidad de su funcionamiento es O(|s| + |t|)
//Arreglo de la Función de Error. Debemos cuidar que el tamaño sea igual al peor tamaño de T , más 5.
//Si |T| <= 10⁵ , entonces :
int FE[100002];
//Calculamos la función de error
void FuncionError(){
	//Ya vimos que para la 0, su Fe es -1
	FE[0] = -1;
	//Vamos ir caracter por caracter
	for(int i = 0; i < t.size();){
		//Tomamos el caracter i para resolver la solución para la posición i+1.
		//Ya que queremos saber para i+1, el anterior es i, por lo tanto nos vamos
		//a su función de error.
		int pos = FE[i];
		//Iteramos mientras que la letra siguiente no sea igual a la siguiente de la función
		//de error. Adicionalmente, si pos se vuelve negativo, o sea -1, deja de moverse
		//hacia atras.
		while(pos >= 0 && t[pos] != t[i])
			pos = FE[pos]; //Usa la función de error para moverse hacia atras
		//Como s[pos] == s[i] , es como si los dos se movieran en el automata.
		//Y como el prefijo que termina en 'pos' es sufijo del prefijo que termina en i.
		//Y como s[pos] == s[i], entonces el prefijo que termina en 'pos+1' es sufijo
		//del que termina en i+1.
		FE[++i] = ++pos;
	}
}
//Imprime las posiciones en las que t se encuentra en s.
//Debimos haber calculado la función de error desde antes de llamar esta función.
void Aparece(){
	//Ya que no hemos matcheado nada, empezamos en el estado inicial
	int pos = 0;
	//Vamos caracter por caracter
	for(int i = 0; i < s.size(); i++){
		//Buscamos sobre 't' el primer caracter que sea igual al siguiente de 's'
		//Aplica la misma regla de cuando llegamos a -1, es decir, dejamos de movernos
		//hacia atrás.
		while(pos >= 0 && s[i] != t[pos] )
			pos = FE[pos]; //De nuevo usamos la función de error
		//Ya que encontramos un caracter igual, o llegamos a -1, avanzamos sobre
		//el "autómata", que en sí es un arreglo
		pos++;
		//Preguntamos si ya procesamos todos los caracteres de t
		if(pos == t.size()){
			//Si es así, es porque en i hemos pasados por todos los caracteres
			//Por lo tanto t termina en la posición i.
			//Así, si termina en i , entonces inicio en i - |t| + 1.
			cout << i - t.size() + 1 << '\n';
			//Al estar en el último estado, no habrá nada que acepte el "autómata",
			//entonces, eventualmente se moverá con la función de errro. Por lo tanto
			//no hay problema con moverse desde este punto.
			pos = FE[pos];
		}
	}
}
