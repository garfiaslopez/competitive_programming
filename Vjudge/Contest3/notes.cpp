// D
// implementar el codigo de segment tree directamente:


// C Metro
    // DP
    // Considerar 3 casos
        // default, ,otro;

// Llevar una segunda variable que nos de informacion sobre lo ultimo que hicimos.
// Flags:
    // DP(position, color)

// E - K-based Numbers
    // empiezas con numeros y de ahi elijes si escoges 0 o cualquier otro numero..

    // DP(position, isZero)


// B  Frequent values:
//  Comprimir todos los numeros en el arreglo porque esta ordenado de menor  a mayor
//  [0001122222344555555]  -> y mapear los indices para que apunten a su bloque mas cercano a la derecha
//                      -> Y calcular los maximos en subrangos en los bloques:
//  -> [325126]

// H - Little Girl and Maximum Sum
//  Suma de acumulados o BIT

// A - Watermelon Full of Water  [harder];
//  DP con estructura de datos: Segment Tree. En vez de guardar la DP en un arreglo, guardar en segment tree, y hacer query's.

//  J - Brackets Subsequences
//  DP
//   1, i=N^cnt=0;
//   0, i=N^cnt=0;
//      DP(i+1,cnt+1) + DP(i+1,cnt),        S[i] == 'C'
//      DP(i+1, cnt),                       cnt=0
//      DP(i+1, cnt + 1) + DP(i+1, cnt),    OTRO
//

// I - Horrible Queries
// Segment Tree With Lazy Propagation:
//

// K - Can you answer these queries I
//  Segment Tree de sufijos y prefijos
//     Cuando la solucion pasa por la derecha, la izquierda o enmedio.  
//
//
