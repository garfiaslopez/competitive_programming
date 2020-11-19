// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string> 

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    string numberString = to_string(n);
    int digits = 0;
    for (int i=0; i<numberString.size(); i++) {
        int digit = (int)numberString[i] - 48;
        if(digit != 0 && n % digit == 0) {
            digits++;
        }
    }
    return digits;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        cout << result << "\n";
    }
    return 0;
}