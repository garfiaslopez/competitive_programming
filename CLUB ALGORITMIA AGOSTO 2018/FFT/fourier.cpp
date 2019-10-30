//  ESIME ZACATENCO   7CV4
// © GARFIAS LOPEZ JOSE DE JESUS
//  Fourier Transform Function
//
// Resources for this code:
// https://betterexplained.com/articles/an-interactive-guide-to-the-fourier-transform/
// https://www.youtube.com/watch?v=r18Gi8lSkfM
// 
// INPUT SEQUENCE:
//   N      -> Number of data complex numbers
//  [R:I]  -> Real and Imaginary Value of N Numbers
//  1 | 0   -> 1 for IDFT and 0 for DFT
//
//  Fourier Transform Have O(N^2) Complexity
//  Fast Fourier Transform  O(N Log2(N)) Complexity
// compile & run:     g++ fourier.cpp -o fourier && ./fourier < input.txt > out.txt


#include <iostream>
#include <cmath>
#include <complex>
#include <vector>

using namespace std;

typedef double Double;
typedef complex<double> ComplexDouble;
int operations = 0;


// Simple formula technique doing the sumatory of multiplication of values of x[n]
void FourierTransform (vector<ComplexDouble> &data, bool isInverse) {
    // helper vars
    const ComplexDouble J(0, 1); // sqrt(-1)
    const int N = data.size();
    vector<ComplexDouble> result;

    // iterate for every freq
    for (int freq = 0; freq < N; freq++) {
        operations++;
        ComplexDouble temp_complex(0,0);
        // iterate for every point in data time
        for (int t = 0; t < N; t++) {
            operations++;
            if (isInverse) {
                temp_complex += data[t] * exp(2.0 * J * M_PI * Double(t) * Double(freq) / Double(N));
            } else {
                temp_complex += data[t] * exp(-2.0 * J * M_PI * Double(t) * Double(freq) / Double(N));
            }
        }
        // round zeros 
        if (abs(temp_complex.real()) < 1e-10) { temp_complex.real(0); }
        if (abs(temp_complex.imag()) < 1e-10) { temp_complex.imag(0); }

        // scale result if is inverse
        if (isInverse) {
            temp_complex.real(temp_complex.real() / Double(N));
            temp_complex.imag(temp_complex.imag() / Double(N));
        }
        result.push_back(temp_complex);
    }
    data = result;
}


// divide and conquer technique easy of understand.
// just bipartitioning the array in odds and even vals until you get a pair when the
// result is equals to one, and after that, by recursion going back to merge the
// results.
void FastFourierTransformRecursion(vector<ComplexDouble> &data, bool isInverse) {
    const ComplexDouble J(0, 1); // sqrt(-1)
    const int N = data.size();
    vector<ComplexDouble> result(N);
    if (N <= 1) return;

    // here is the increment val, because this amortizes all the next for loops
    operations++;

    // DIVIDE THE VECTOR INTO SUBPROBLEMS
    // get the even vals
    vector<ComplexDouble> even;
    for (int i=0; i<N; i+=2) {
        even.push_back(data[i]);
    }
    FastFourierTransformRecursion(even, isInverse);

    // get the odds vals
    vector<ComplexDouble> odd;
    for (int i=1; i<N; i+=2) {
        odd.push_back(data[i]);
    }
    FastFourierTransformRecursion(odd, isInverse);
    
    // COMBINE THE RESULTS AND GO BACK
    for (int i = 0; i<N/2; i++) {
        operations++;

        ComplexDouble temp_complex(0,0);
        if (isInverse) {
            temp_complex += odd[i] * exp(2.0 * J * M_PI * Double(i) / Double(N));
        } else {
            temp_complex += odd[i] * exp(-2.0 * J * M_PI * Double(i) / Double(N));
        }
        data[i] = even[i] + temp_complex;
        data[i+N/2] = even[i] - temp_complex;
    }

}

void FastFourierTransform(vector<ComplexDouble> &data, bool isInverse) {
    FastFourierTransformRecursion(data, isInverse);
    // scale the result 1/N if is Inverse
    if (isInverse) {
        for (int i=0; i<data.size();i++) {
            data[i] /= data.size();
        }
    }
}

int main () {
    ///////////////////////////////// READ INPUT DATA
    // read the input data: [N, vector, isInverse]:
    vector<ComplexDouble> data_to_calculate;
    int isInverse = 1;
    int N;
    cin>>N;
    for (int i=0; i<N; i++){
        Double real;
        Double imag;
        scanf("%lf:%lf", &real, &imag);
        data_to_calculate.push_back(ComplexDouble(real, imag));
    }
    cin>>isInverse;
    /////////////////////////////////


    ///////////////////////////////// PROCESS SUBSEQUENCE
    vector<ComplexDouble> res(data_to_calculate);
    /// SWITCH BETWEEN FAST AND NORMAL ALGORITHM
    FastFourierTransform(res, isInverse);
    //FourierTransform(res, isInverse);
    /////////////////////////////////


    ///////////////////////////////// PRINT SUBSEQUENCE
    // print the input vector:
    cout<<"Dada una entrada: [ ";
    for (int i = 0; i<data_to_calculate.size();i++) {
        cout<< data_to_calculate[i]<<" ";
    }
    cout<< "]"<<endl<<endl;
    if (isInverse == 1) {
        cout<<"[IDFT] Su transofrmada de fourier inversa es: "<<endl;
    } else {
        cout<<"[DFT]  Su transofrmada de fourier es: "<<endl;
    }

    for (int i = 0; i<res.size();i++) {
        cout<< res[i] <<" ";
    }
    cout<<endl<<endl;

    for (int i=0; i<res.size(); i++) {
        cout<< "frecuencia: "<< i + 1 <<endl;
        cout<< "real: "<< res[i].real() << "  img: " << res[i].imag() << endl;
        cout<< "amplitud: " 
        << sqrt((res[i].real() * res[i].real()) + (res[i].imag() * res[i].imag())) 
        << "  Fase (Grados): "<< (atan2(res[i].imag(), res[i].real()) * 180 / M_PI) 
        << endl<<endl;
    }
    cout<<" # De Operaciones: "<< operations << endl;
    /////////////////////////////////


    return 0;
}
