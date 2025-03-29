#pragma once
#include <limits>
template <typename T> requires std::floating_point<T>

class complex_number {
    
    T re, im;
    
public:
    //Costruttore di default
    complex_number() 
        : re(0), im(0)
    {}
    //Costruttore user-defined per parte reale e immaginaria
    explicit complex_number(T r, T i)
        : re(r), im(i)
    {}
    //Costruttore user-defined per numeri reali
    explicit complex_number(T r)
        : re(r), im(0)
    {}
    
    //Metodo per coniugato
    complex_number coniugato() const {
        return complex_number(re, -im);
    }
    //Metodo per parte reale
    T parte_reale() const {
        return re;
    }
    //Metodo per parte immaginaria
    T parte_immaginaria() const {
        return im;
    }
    
    //Overload operatori += e +
    complex_number& operator+=(const complex_number& c2) {
        re += c2.re;
        im += c2.im;
        return *this;
    }
    complex_number operator+(const complex_number& c2) {
        return complex_number(re + c2.re, im + c2.im);
    }

    //Operazione + e += tra tipo T e complex
    complex_number& operator+=(const T& c2) {
        re += c2;
        return *this;
    }
    complex_number operator+(const T& c2) {
        return complex_number(re + c2, im);
    }

    //Overload operatori *= e *
    complex_number& operator*=(const complex_number& c2) {
        T a = re;
        T b = im;
        T c = c2.re;
        T d = c2.im;
        re = a*c - b*d;
        im = a*d + b*c;
        return *this;
    }
    complex_number operator*(const complex_number& c2) {
        return complex_number(re*c2.re - im*c2.im, re*c2.im + im*c2.re);
           }

    //Operazioni *= e * tra tipo T e complex
    complex_number& operator*=(const T& c2) {
        re *= c2;
        im *= c2;
        return *this;
    }
    complex_number operator*(const T& c2) {
        return complex_number(re*c2, im*c2);
    }

};


template<typename T>
std::ostream& operator<< (std::ostream& os, const complex_number<T>& c) {
    T EPS = std::numeric_limits<T>::epsilon();
    bool re_zero = c.parte_reale() < EPS && c.parte_reale() > - EPS;
    bool im_zero = c.parte_immaginaria() < EPS && c.parte_immaginaria() > - EPS;

    if (re_zero && im_zero){
        os << 0;
    }
    else {
        if (re_zero){
            os << c.parte_immaginaria() << "i";
        }
        if (im_zero){
            os << c.parte_reale();
        }
        if (!re_zero && !im_zero){
            if (c.parte_immaginaria() > 0){
                os << c.parte_reale() << "+" << c.parte_immaginaria() << "i";
            }
            if (c.parte_immaginaria() < 0){
                os << c.parte_reale() << c.parte_immaginaria() << "i";
            }         
        }
    }
    return os;

   

}

