#include <iostream>

using namespace std;

typedef int long long;

int hash[1000000];
int pot[1000000];
int mod = 10000000000 + 7;
int base = 57;

// polinomio:  aoB^k +  a1B^k-1 + ... +  ak-1B^k1 +  akB^0
//  Hi = Hi-1 * B + cadi

int char_to_int(char c) {
    return 1;
}

void create_hash(string word) {
    pot[0] = 1;
    hash[0] = char_to_int(word[0]);

}
// revisar i y j en casos de cero para que no se desborde...

int obtenerHash()

int main() {
    
}