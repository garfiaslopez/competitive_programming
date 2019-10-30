

/*
  La idea es recorrer la cadena y mientras la pila este vacia y diferente a ( insertar al arreglo a regresar.
  si nos encontramos con un ( u otro caracter tenemos que insertarlo a la pila.
  si nos encontramos con un ) comenzamos el proceso de recuperar de la pila los caracteres hasta ) y verificamos si la pila esta vacia para
  poder concatenarlos al string que vamos a regresar, sino esta vacia, reinsertamos en la pila pero ya reverseada esa cadena, y seguimos con el recorrido.
*/

function getLastString(stack) { // recuperar los caracteres hasta '(' de la pila.
  let partialString = [];
  let charStack = stack.pop();
  while (charStack !== '(') {
    partialString.push(charStack);
    charStack = stack.pop();
  }
  return partialString;
}

function reverseString(input) {
  let stack = [];
  let returnString = [];
  input.split('').forEach((letter, index) => {
    if (stack.length === 0 && letter !== '(') { // si la pila esta vacia insertamos al string a retornar.
        returnString.push(letter);
    } else if (letter === ')') { // recuperar de la pila
      let partialString = getLastString(stack);
      if (stack.length !== 0) {
        // si todavia tenemos algo en la pila hay que reinsertar a la pila.
        partialString.forEach((el) => {
          stack.push(el);
        });
      } else {
        // si la pila esta vacia, concatenamos al string final.
        partialString.forEach((el) => {
          returnString.push(el);
        });
      }
    } else {
      stack.push(letter);
    }
  });
  return returnString.join('');
}

const tests = [
  "(bar)",
  "foo(bar)baz",
  "foo(bar(baz))blim",
  "",
  "()",
  "(abc)d(efg)",
  "foobarbaz",
  "a(bar(foo)ab)xz",
  "(abc)(def)hello(ghi(jkl)ba)world"
];

const responses = [
  "rab",
  "foorabbaz",
  "foobazrabblim",
  "",
  "",
  "cbadgfe",
  "foobarbaz",
  "abafoorabxz",
  "cbafedhelloabjklihgworld"
];

tests.forEach((test, index) => {
  const result = reverseString(test);
  console.log(test, '=>', result, ' | passed:' ,result === responses[index]);
});



function getLastString(stack) { // recuperar los caracteres hasta '(' de la pila.
    let partialString = [];
    let charStack = stack.pop();
    while (charStack !== '(') {
        partialString.push(charStack);
        charStack = stack.pop();
    }
    return partialString;
}

function reverseParentheses(input) {
    let stack = [];
    let returnString = [];
    input.split('').forEach((letter, index) => {
        if (stack.length === 0 && letter !== '(') { // si la pila esta vacia insertamos al string a retornar.
            returnString.push(letter);
        } else if (letter === ')') { // recuperar de la pila
            let partialString = getLastString(stack);
            if (stack.length !== 0) {
                // si todavia tenemos algo en la pila hay que reinsertar a la pila.
                partialString.forEach((el) => {
                    stack.push(el);
                });
            } else {
                // si la pila esta vacia, concatenamos al string final.
                partialString.forEach((el) => {
                    returnString.push(el);
                });
            }
        } else {
            stack.push(letter);
        }
    });
    return returnString.join('');
}
