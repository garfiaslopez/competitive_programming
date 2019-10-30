#include <cstdio>
#include <cmath>

using namespace std;

unsigned long long int numberCopy = 0;
unsigned long long int raiz = 0;
int sieve[100000000];

void imprime(int result) {
    printf("%d\n", result);
}

void procesa() {
    unsigned long long int result = 1;
    int cont = 0;
    int mark = 0;
    if (numberCopy < 10) raiz = numberCopy;
    int i = 2;
    while (result <= numberCopy) {
        if (!sieve[i]) {
            mark = i+i;
            while (mark<=raiz) {
                sieve[mark] = 1;
                mark = mark+i;
            }
            result *= i;
            if (result<=numberCopy) {
                cont++;
            }
        }
        i++;
    }
    imprime(cont);
}

void lee() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%llu", &numberCopy);
        printf("%llu", numberCopy);
        raiz = sqrt(numberCopy);
        procesa();
    }
}

int main() {
    lee();
}