#include <iostream>

class Complex{
    double real;
    double imagin;
public:
    explicit Complex(double r, double im=0) : real(r), imagin(im) {}
    // becouse constructor is explicit there is required separate operators for complex + decimsal and decimal + complex

    // operators
    friend Complex operator+(const Complex & c1, const Complex & c2);   // complex + complex
    friend Complex operator+(const Complex & c, const double & d);      // complex +  double    
    friend Complex operator+(const double & d, const Complex & c);      // double  + complex

    friend Complex operator-(const Complex & c1, const Complex & c2);
    friend Complex operator-(const Complex & c, const double & d);
    friend Complex operator-(const double & d, const Complex & c);
    friend Complex operator-(const Complex & c);
};


Complex operator+(const Complex & c1, const Complex & c2) {
    return Complex(c1.real + c2.real, c1.imagin + c2.imagin);
}

Complex operator+(const Complex & c, const double & d) {
    return Complex(c.real + d , c.imagin);
}

Complex operator+(const double & d, const Complex & c) {
    return Complex(d + c.real , c.imagin); // could be: "return c + d;" since (complex + double) is already defined
}


Complex operator-(const Complex & c1, const Complex & c2) {
    return Complex(c1.real - c2.real, c1.imagin - c2.imagin);
}

Complex operator-(const Complex & c, const double & d) {
    return Complex(c.real - d , c.imagin);
}

Complex operator-(const double & d, const Complex & c) {
    return Complex(d - c.real, -c.imagin);
}

Complex operator-(const Complex & c) {
    return Complex( -c.real, -c.imagin);
}

class ComplexImplicit{
    double real;
    double imagin;
public:
    ComplexImplicit(double r, double im=0) : real(r), imagin(im) {}
    // one-arg implicit costructor allows implicit coverstion double/int -> complex

    // operators
    friend ComplexImplicit operator+(const ComplexImplicit & c1, const ComplexImplicit & c2);
    friend ComplexImplicit operator-(const ComplexImplicit & c1, const ComplexImplicit & c2);
    friend ComplexImplicit operator-(const ComplexImplicit & c);
};

ComplexImplicit operator+(const ComplexImplicit & c1, const ComplexImplicit & c2) {
    return {c1.real + c2.real, c1.imagin + c2.imagin}; 
    // becouse constructor is implicite there is no requirement for calling explicite constr like ComplexImplicit(x, y);
}
ComplexImplicit operator-(const ComplexImplicit & c1, const ComplexImplicit & c2) {
    return {c1.real - c2.real, c1.imagin - c2.imagin};
}
ComplexImplicit operator-(const ComplexImplicit & c) {
    return {-c.real, -c.imagin};
}

int main(int argc, char const *argv[])
{
    //---------------------------------------
    // Complex numbers with EXPLICIT creator:

    Complex x1{1, 2};                       // 1 + 2i
    Complex x2 = static_cast<Complex>(3);   // 3 + 0i
    //Complex x3 = 3;       // wont work becouse of the "explicit" in constructor
    //Complex x4 = {1, 2};  // -//-
    x1 + x2;
    //x1 + 1;               // wont work becouse of the "explicit" in constructor
    //              it would require separate operator+ for Object and double/int
    x1 + 0.5;
    x2 - 0.9;
    -x1;

    //---------------------------------------
    // Complex numbers with IMPLICIT creator:

    ComplexImplicit x_imp1 = 5;
    ComplexImplicit x_imp2 = {1, 2};
    
    x_imp1 + 100 - 10;
    0.99 + x_imp2;

    return 0;
}