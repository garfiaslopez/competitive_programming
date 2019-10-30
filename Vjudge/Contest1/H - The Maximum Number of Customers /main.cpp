// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int CustomersTotal;
    int BussinesHours;
    scanf("%d%d", &CustomersTotal, &BussinesHours);
    BussinesHours +=1;
    int ArrayOfCustomers[BussinesHours];
    memset(ArrayOfCustomers, 0, BussinesHours*sizeof(*ArrayOfCustomers));
    int max = 0;
    for(int i=0; i<CustomersTotal; i++) {
        int start, end;
        scanf("%d%d", &start, &end);
        if (start < end) {
            for(int j=start; j<end; j++) {
                ArrayOfCustomers[j] += 1;
                if (ArrayOfCustomers[j]>max) {
                    max = ArrayOfCustomers[j];
                }
            }
        }
    }
    printf("%d\n", max);
    return (0);
}
