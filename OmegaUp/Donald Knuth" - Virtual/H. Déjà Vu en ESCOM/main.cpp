// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int dreamsTAM;
    scanf("%d", &dreamsTAM);
    int dreams[dreamsTAM];
    for (int i=0; i<dreamsTAM; i++) {
        scanf("%d", &dreams[i]);
    }
    int dreamsTrigger = dreams[0];
    int maxInception = 0;
    for (int i=1; i<dreamsTAM; i++) {
        if (dreams[i] == dreamsTrigger) {
            // check sequence for subdream: until we are...
            int inception = 0;
            for (int j=0; j<=i; j++) {
                if (j+i < dreamsTAM) { // si estamos adentro del arreglo
                    if (dreams[j] == dreams [j+i]) { // si son iguales
                        inception++;
                    }
                }
            }
            if (inception > maxInception) {
                maxInception = inception;
            }
        }
    }
    printf("%d\n", maxInception);
    return (0);
}
