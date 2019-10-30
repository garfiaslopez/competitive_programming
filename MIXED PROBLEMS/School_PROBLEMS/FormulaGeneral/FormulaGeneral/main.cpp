#include <iostream>
#include <math.h>
using namespace std;

class Formula {
private:
    double x1,x2,xR,xI,a,b,c,d;
public:
    Formula(){
        x1=x2=xR=xI=a=b=c=d=0.0;
    }
    void Lee(){
        cout<<"\n Dame a: "; cin >>a;
        cout<<"\n Dame b: "; cin >>b;
        cout<<"\n Dame c: "; cin >>c;
    }
    bool esLineal(){
        if(a==0){
            return 1;
        }else{
            return 0;
        }
    }
    double D(){
        d=b*b-4*a*c;
        return d;
    }
    void Real(){
        x1=(-b+sqrt(D()))/(2*a);
        x2=(-b-sqrt(D()))/(2*a);
        
        cout<<"Solucion Real : "<<endl;
        cout<<"X1 = "<<x1<<endl<<"X2 = "<<x2<<endl;
    }
    void Imag(){
        xR=-b/(2*a);
        xI=sqrt(-D())/(2*a);
        
        cout<<"Solucion Imaginaria : "<<endl;
        cout<<"X1 = "<<xR<<endl<<"+i "<<xI<<endl;
        cout<<"X2 = "<<xR<<endl<<"-i "<<xI<<endl;
    }
    void Lineal(){
        double res = -c/b;
        
        cout<<"Solucion Lineal : "<<endl;
        cout<<"X1 = "<<res<<endl;
    }
    
};

int main(){
    
    Formula F;
    F.Lee();
    
    if(F.esLineal()){
        
        F.Lineal();
        
    }else{
        if(F.D() > 0){
            
            F.Real();
            
        }else{
            
            F.Imag();
            
        }
    }
    return 0;
}
