// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <string> 

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int needed = 0;
    bool isUpper = false, isLower = false, isMinimum = false, haveDigit = false, haveSpecial = false;

    haveDigit = true;
    if (std::string::npos != password.find_first_of("0123456789")) {
        haveDigit = true;
    } else {
        needed ++;
    }
    
    if (std::string::npos != password.find_first_of("!@#$%^&*()-+")) {
        haveSpecial = true;
    } else {
        needed ++;
    }

    // UPPER AND LOWER
    for (int i=0; i<n; i++) {
        if (islower(password[i])) {
            isLower = true;
            break;
        }
    }

    for (int i=0; i<n; i++) {
        if (isupper(password[i])){
            isUpper = true;
            break;
        }
    }

    if (!isLower) {
        needed++;
    }
    if (!isUpper) {
        needed++;
    }
    
    if (n >= 6) {
        return needed;
    } else {
        int dif = 6 - n; // 2
        //cout<<dif<<" - "<<needed<<endl;
        return max(dif, needed);
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    cout << answer << "\n";
    return 0;
}

