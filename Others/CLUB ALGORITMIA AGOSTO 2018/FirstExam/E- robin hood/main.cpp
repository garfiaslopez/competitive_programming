// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

// Definiciones iniciales.
typedef long double Double;
typedef long long Long;
typedef pair<int, int> pii;

const Double INF = 1ll << 60;
const Double ERROR = 1e-12;
const Double M_2PI = 2.0 * M_PI;

#define EQ(a, b) (fabs((a) - (b)) < ERROR)

struct Punto {
    Double x, y;
    Punto() : x(), y() {}
    Punto(Double X, Double Y) : x(X), y(Y) {}
    bool operator<(const Punto& q) const {
        if (!EQ(x, q.x)) return x < q.x;
        return EQ(y, q.y)? false: y < q.y;
    }
    bool operator==(const Punto& q) const {
        return EQ(x, q.x) && EQ(y, q.y);
    }
    //Sumar los vectores actual y q.
    Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
    //Restar los vectores (o trasladarlos), tomando p como el origen.
    Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
    //Obtener el vector opuesto.
    Punto operator -() const { return Punto(-x, -y); }
    //Obtener el vector por un escalar.
    Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
    //Obtener el vector dividido por un escalar.
    Punto operator/( Double c ) const { return Punto( x/c, y/c ); }
    //Magnitud del vector.
    Double Abs() const { return hypot(x, y); }
    //Distancia entre el punto actual y q.
    Double Dist( const Punto& q ) const { return (*this - q ).Abs(); }
};

int main() {
    int totalPairs;
    cin>>totalPairs;
    vector<Punto> pairs;
    for (int i=0; i<totalPairs; i++) {
        int a,b;
        cin>>a>>b;
        Punto p = Punto(a,b);
        pairs.push_back(p);
    }
    Double max = -100000;
    for (int i=0; i<totalPairs; i++) {
        for (int j=0; j<totalPairs; j++) {
            Double dist = pairs[i].Dist(pairs[j]);
            if (dist > max) {
                max = dist;
            }
        }
    }
    cout<<max<<endl;
    return 0;
}