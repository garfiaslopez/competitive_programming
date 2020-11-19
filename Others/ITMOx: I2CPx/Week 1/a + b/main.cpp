// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>

#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    return (0);
}
