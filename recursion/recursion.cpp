#include <iostream>
#include <string>

//--------------------------------------
// FACTORIAL
int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}
void factorial_test(const int x, int i=0){
    std::cout<<i<<"! = "<<factorial(i)<<std::endl;
    if (x > i) 
        factorial_test(x, ++i);
    return;
}
//--------------------------------------
// SUM OF FOLLOWING NUMBERS ( k + (k-1) + (k-2) + ... + 1 )
int sum_of_num(int k) {
  if (k > 0) {
    return k + sum_of_num(k - 1);
  } else {
    return 0;
  }
}
void sum_of_num_test(const int x, int i=0) {
    std::cout<<"sum of next nums from "<<i<<" = "<<sum_of_num(i)<<std::endl;
    if (x > i) 
        sum_of_num_test(x, ++i);
    return;
}
//--------------------------------------
// GRPHICALS

const std::string DOT_SIGN_ = "+ ";
const std::string BLANK_SIGN_ = "- ";

void ramp1(const int width) {
    static int i = 1;
    for(int j = 0; j < i; ++j )
        std::cout<<DOT_SIGN_;
    std::cout<<"\n";
    if (i >= width)
        return;
    ++i;
    ramp1(width);
}
void ramp2(int width) {
    static int i = 1;
    for(int j = 0; j < width; ++j ){
        if (j < i) {
            std::cout<<DOT_SIGN_;
        }
        else {
            std::cout<<BLANK_SIGN_;
        }
    }
    std::cout<<'\n';
    if (i >= width) return;
    ++i;
    ramp2(width);
}

void ramp3(int width) {
    static int i = 1;
    for(int j = 0; j < i; ++j ){
        std::cout<<DOT_SIGN_;
    }
    for(int j = 0; j < width-i; ++j ){
        std::cout<<BLANK_SIGN_;
    }
    std::cout<<'\n';
    if (i >= width) return;
    ++i;
    ramp3(width);
}   //ramp2 looks better then ramp3 (CLEANER AND EASIER TO READ) but it uses unnecessary if-else statements

        

void arrow_bolt1(const int width){
    static int rep = 1;
    if (rep > width)
        return;
    for (int i = 0; i < rep; ++i)
        std::cout<<DOT_SIGN_;
    std::cout<<'\n';

    ++rep;
    arrow_bolt1(width);
    --rep;

    if (rep < width) { 
        for (int i = 0; i < rep; ++i)
            std::cout<<DOT_SIGN_;
        std::cout<<'\n';
    }
}

void arrow_bolt2(const int width, int rep = 1){
    if (rep > width)
        return;
    for (int i = 0; i < rep; ++i)
        std::cout<<DOT_SIGN_;
    std::cout<<'\n';

    arrow_bolt2(width, rep+1);

    if (rep < width) { 
        for (int i = 0; i < rep; ++i)
            std::cout<<DOT_SIGN_;
        std::cout<<'\n';
    }
}

void arrow_bolt3(const int width, int rep = 1){
    if (rep > width)
        return;
    for (int i = 0; i < width; ++i)
        if (i < rep)
            std::cout<<DOT_SIGN_;
        else 
            std::cout<<BLANK_SIGN_;
    std::cout<<'\n';

    arrow_bolt3(width, rep+1);

    if (rep < width) { //this if makes sure there will be only one sharp edge (one row instead of two)
        for (int i = 0; i < width; ++i)
            if (i < rep)
                std::cout<<DOT_SIGN_;
            else 
                std::cout<<BLANK_SIGN_;
        std::cout<<'\n';
    }
}

void pyramid(const int height){
    static int rep = 1;
    if (rep > height)
        return;

    for (int i = 0; i < height; ++i)
        if (i < height - rep)
                std::cout<<BLANK_SIGN_;
            else 
                std::cout<<DOT_SIGN_;
    
    for (int i = 1; i < height; ++i) //starting with i=1 will make sure there will be only one sharp pick
        if (i < rep)
                std::cout<<DOT_SIGN_;
            else 
                std::cout<<BLANK_SIGN_;

    std::cout<<'\n';
    ++rep;
    pyramid(height);
}

void diamond(const int height, int rep = 1) {
    if (rep > height/2)
        return;
    
    for (int i = 0; i < height/2; ++i)
        if (i < height/2 - rep)
                std::cout<<BLANK_SIGN_;
            else 
                std::cout<<DOT_SIGN_;
    
    for (int i = 1; i < height/2; ++i) //starting with i=1 will make sure there will be only one sharp pick
        if (i < rep)
                std::cout<<DOT_SIGN_;
            else 
                std::cout<<BLANK_SIGN_;

    std::cout<<'\n';

    diamond(height, rep+1);

    if (rep < height/2) { //this if makes sure there will be only one sharp edge (one row instead of two)
        for (int i = 0; i < height/2; ++i)
            if (i < height/2 - rep)
                    std::cout<<BLANK_SIGN_;
                else 
                    std::cout<<DOT_SIGN_;
        
        for (int i = 1; i < height/2; ++i) //starting with i=1 will make sure there will be only one sharp pick
            if (i < rep)
                    std::cout<<DOT_SIGN_;
                else 
                    std::cout<<BLANK_SIGN_;

        std::cout<<'\n';
    }

}
//--------------------------------------

void decorator(std::string Title = "", std::string line_sep = "-------------------"){
    std::cout<<line_sep<<'\n';
    if (Title == "")
        return;
    std::cout<<Title<<'\n';
}

int main(int argc, char const *argv[])
{
    decorator("RECURSION FACTORIAL");
    factorial_test(8);

    decorator("RECURSION SUM");
    sum_of_num_test(8);

    decorator("RAMP");
    //ramp1(10);
    ramp2(10);
    //ramp3(10);

    decorator("ARROW");
    //arrow_bolt1(10);
    //arrow_bolt2(10);
    arrow_bolt3(10);

    decorator("PYRAMID");
    pyramid(10);

    decorator("DIAMOND");
    diamond(10);
    return 0;

}

/* THE MAIN OUTPUT
-------------------
RECURSION FACTORIAL
0! = 1
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = 5040
8! = 40320
-------------------
RECURSION SUM
sum of next nums from 0 = 0
sum of next nums from 1 = 1
sum of next nums from 2 = 3
sum of next nums from 3 = 6
sum of next nums from 4 = 10
sum of next nums from 5 = 15
sum of next nums from 6 = 21
sum of next nums from 7 = 28
sum of next nums from 8 = 36
-------------------
RAMP
+ - - - - - - - - - 
+ + - - - - - - - - 
+ + + - - - - - - - 
+ + + + - - - - - - 
+ + + + + - - - - - 
+ + + + + + - - - - 
+ + + + + + + - - - 
+ + + + + + + + - - 
+ + + + + + + + + - 
+ + + + + + + + + + 
-------------------
ARROW
+ - - - - - - - - - 
+ + - - - - - - - - 
+ + + - - - - - - - 
+ + + + - - - - - - 
+ + + + + - - - - - 
+ + + + + + - - - - 
+ + + + + + + - - - 
+ + + + + + + + - - 
+ + + + + + + + + - 
+ + + + + + + + + + 
+ + + + + + + + + - 
+ + + + + + + + - - 
+ + + + + + + - - - 
+ + + + + + - - - - 
+ + + + + - - - - - 
+ + + + - - - - - - 
+ + + - - - - - - - 
+ + - - - - - - - - 
+ - - - - - - - - - 
-------------------
PYRAMID
- - - - - - - - - + - - - - - - - - - 
- - - - - - - - + + + - - - - - - - - 
- - - - - - - + + + + + - - - - - - - 
- - - - - - + + + + + + + - - - - - - 
- - - - - + + + + + + + + + - - - - - 
- - - - + + + + + + + + + + + - - - - 
- - - + + + + + + + + + + + + + - - - 
- - + + + + + + + + + + + + + + + - - 
- + + + + + + + + + + + + + + + + + - 
+ + + + + + + + + + + + + + + + + + + 
-------------------
DIAMOND
- - - - + - - - - 
- - - + + + - - - 
- - + + + + + - - 
- + + + + + + + - 
+ + + + + + + + + 
- + + + + + + + - 
- - + + + + + - - 
- - - + + + - - - 
- - - - + - - - - 
*/