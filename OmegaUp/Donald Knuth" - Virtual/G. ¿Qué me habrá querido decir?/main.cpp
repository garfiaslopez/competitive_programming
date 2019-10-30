// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string.h>
#include <iterator>
#include <map>

using namespace std;

map<char, char>MapLetters;

int charToInt(char i) {
    return (int)i - 48;
}

char easytolower(char in) {
    if(in <= 'Z' && in >= 'A'){
        return in - ('Z' - 'z');
    }
  return in;
}

int main() {
    char Map[1000];
    char message[1000000];
    int cases;

    scanf("%[^\n]s",message); // ignore spaces and delimiter with \n
    int TAM = strlen(message);

    scanf("%d\n", &cases);
    fflush(stdin);

    for (int i=0; i<cases; i++) {
        char letter;
        char meaning;
        fflush(stdin);
        scanf("%c %c\n", &meaning, &letter);
        MapLetters[letter] = meaning;
        Map[letter] = meaning;
    }

    for (int i=0; i<TAM; i++) {
        if (MapLetters[easytolower(message[i])]) {
            char l = MapLetters[easytolower(message[i])];
            if (isupper(message[i])) {
                printf("%c", toupper(l));
            } else {
                printf("%c", l);
            }
        } else {
            printf("%c", message[i]);
        }
    }
    return (0);
}
