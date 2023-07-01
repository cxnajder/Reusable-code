#include <iostream>

class Complex{
    double real;
    double imagin;
public:
    explicit Complex(double r, double im=0) : real(r), imagin(im) {}

    // operators
    friend Complex operator+(const Complex & c1, const Complex & c2);
    friend Complex operator-(const Complex & c1, const Complex & c2);
};
Complex operator+(const Complex & c1, const Complex & c2) {
    return Complex(c1.real + c2.real, c1.imagin + c2.imagin);
}
Complex operator-(const Complex & c1, const Complex & c2) {
    return Complex(c1.real - c2.real, c1.imagin - c2.imagin);
}


int main(int argc, char const *argv[])
{
    Complex x1{1, 2};                       // 1 + 2i
    Complex x2 = static_cast<Complex>(3);   // 3 + 0i
    //Complex x3 = 3;       // wont work becouse of the "explicit" in constructor
    x1 + x2;
    //x1 + 1;               // wont work becouse of the "explicit" in constructor
    //              it would require separate operator+ for Object and double/int

    return 0;
}