#include <iostream> 
#include <vector>

using namespace std; 


int n;
vector<int> numbers;

bool isPrime(int n) { 
    if (n <= 1){
        return false;
    }
    for (int i = 2; i < n; i++){
        if (n % i == 0) {
            return false;
        }
    }
    return true; 
}

bool isInArray(int n) {
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i] == n) {
            return true;
        }
    }
    return false;
}
  
// Driver Program 
int main() {

    cin>>n;
    for (int i=0; i<n; i++) {
        int number;
        cin>>number;
        numbers.push_back(number);
    }

    int a,b;
    cin>>a>>b;

    int primes=0;
    for (int i=a ; i<=b; i++) {
        if (isInArray(i) && isPrime(i)) {
            primes++;
        }
        
    }
    cout<<primes<<endl;

    return 0; 
} 