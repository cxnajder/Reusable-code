#include <iostream>

//-----------------------
// defineing functions i will be poiting to

void printInt(int x) {
    std::cout<<x<<'\n';
}

void printSum(int x, int y) {
    std::cout<<x<<" + "<<y<<" = "<<x+y<<'\n';
}

double addUp(double a, double b) {
    return a+b;
}

double Multiply(double a, double b) {
    return a*b;
}

void printDou(double d) {
    std::cout<<d<<'\n';
}

//-----------------------
// defineing function pointers
typedef void(* OneIntVoidPtr)(int);      // returns void with 1 int arg
typedef void(* TwoIntVoidPtr)(int, int); // returns void with 2 int args

typedef double(* TwoDouDouPtr)(double, double); // returns double with 2 double args

//typedef void(* TwoDouDouPtr)(double); // returns void with 1 double arg
// ^rather then defining new function pointer
// I will defnie function pointer inside calling it function in definicion
// in line 49.

void callVoidFun1(int x, OneIntVoidPtr vfun_ptr ) {
    vfun_ptr(x);
}
void callVoidFun2(int x, int y, TwoIntVoidPtr vfun_ptr ) {
    vfun_ptr(x, y);
}

double callDouDouFun2(double a, double b, TwoDouDouPtr dfun_ptr) {
    return dfun_ptr(a, b);
}

void callVoidDouFun1(double d, void(* vfun_ptr )(double)){
    // inside this function definition is a function pointer declaration
    // pointing at a void fun with one double arg.
    vfun_ptr(d);
}

int main(int argc, char const *argv[])
{
    callVoidFun1(1, printInt);
    callVoidFun2(1, 2, printSum);
    
    std::cout<<callDouDouFun2(0.5, 1.4999, addUp)<<'\n';
    std::cout<<callDouDouFun2(999, 0.009, Multiply)<<'\n';

    callVoidDouFun1(123.456, printDou);

    return 0;
}
