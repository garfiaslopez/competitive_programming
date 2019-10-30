// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int North = 0;
    int South = 0;
    int West = 0;
    int East = 0;
    string path;
    cin>>path;
    for(int i=0;i<path.length(); i++) {
        if (path[i] == 'N') {
            North++;
        } else if (path[i] == 'S') {
            South++;
        } else if (path[i] == 'E') {
            East++;
        } else if (path[i] == 'W') {
            West++;
        }
    }
    if ((North > 0 && South > 0) && (West == 0 && East == 0)) {
        printf("Yes\n");
    } else {
        if ((West > 0 && East > 0) && (North == 0 && South == 0)) {
            printf("Yes\n");
        } else {
            if ((West > 0 && East > 0) && (North > 0 && South > 0)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return (0);
}
