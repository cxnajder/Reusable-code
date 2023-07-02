#include <iostream>
#include <string>
#include <sstream>

class Vector2D {
    double x;
    double y;
public:
    // konstruktory (2- i 0-argumentowe)
    Vector2D(double x_, double y_): x(x_), y(y_) {};
    Vector2D(): Vector2D(0, 0) {}; // konstruktor delegujący

    Vector2D operator+(const Vector2D & v2) const; // operator dodawania dwuch wektorów
    Vector2D operator-(const Vector2D & v2) const;

    Vector2D operator-() const; // wektor ze znakiem przeciwnym

    Vector2D operator*(const double & scalar) const; // operator mnożenia wektor przez skalar
    Vector2D operator/(const double & scalar) const;

    friend std::ostream & operator<<(std::ostream & ostr, const Vector2D & v);

    Vector2D & operator+=(const Vector2D & v2); // Zwiększ v1 (*this) o v2 (nie używamy "const", gdyż zmieniamy v1 (*this))

    Vector2D & operator++();      // ++v
    Vector2D operator++(int);   // v++  <-- "int" w deklaraci jest czysto kosmetyczny - pozwala odróznić v++ od ++v

    // conversion to string
    explicit operator std::string () const;     // explicit pozwala tylko na JAWNĄ konwersję

};

Vector2D Vector2D::operator+(const Vector2D & v2) const {
    return {this->x + v2.x, this->y + v2.y};
}

Vector2D Vector2D::operator-(const Vector2D & v2) const {
    return {this->x - v2.x, this->y - v2.y};
}

Vector2D Vector2D::operator-() const {
    return {-this->x, -this->y};
}

Vector2D Vector2D::operator*(const double & scalar) const {
    return {this->x * scalar, this->y * scalar};
}

Vector2D Vector2D::operator/(const double & scalar) const {
    return {this->x / scalar, this->y / scalar};
}

std::ostream & operator<<(std::ostream & ostr, const Vector2D & v) { // OSTREAM CAN ONLY BE PASTED BY REFERENCE!
    ostr << '(' << v.x << ", " << v.y << ')';
    return ostr;
}

Vector2D & Vector2D::operator+=(const Vector2D & v2){
    this->x += v2.x;
    this->y += v2.y;

    return *this;
}

Vector2D & Vector2D::operator++(){
    ++x; // ++(this->x); // or this->x += 1;
    ++y; // ++(this->y); //    this->y += 1;

    return *this; // zwracamy dereferencję na (ten - this) obiekt
}
Vector2D Vector2D::operator++(int){ // ŻELAZNA ZASADA: NIGDY NIE ZWRACAJ REERENCJI DO ZMIENNYCH >>LOKALNYCH<< FUNKCJI!
    Vector2D copy = *this;
    ++y;
    ++x;
    return copy;
}


Vector2D::operator std::string () const     // stringstream usage example
{
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

int main(int argc, char const *argv[])
{
    Vector2D v1 = {1, 0};
    Vector2D v2 = {0, 1};

    std::cout << "v1 = "<< v1 <<'\n';
    std::cout << "v2 = "<< v2 <<'\n';
    std::cout<<'\n';

    Vector2D v3;

    std::cout << "v1 + v2 = " << v1 + v2 <<'\n';
    std::cout << "v1 - v2 = " << v1 - v2 <<'\n';
    std::cout<<'\n';

    v3 = v1 + v2; // operator kopiujący/przypisania '=' jest utworzony domyślnie (niejawnie) wewnątrz klasy

    std::cout << "v3 = "<< v3 <<'\n';
    std::cout << "-v3 = "<< -v3 <<'\n';
    std::cout<<'\n';


    std::cout << "v3 * 4 = "<< v3 * 4 <<'\n';
    std::cout << "v3 / 2 = "<< v3 / 2 <<'\n';
    std::cout<<'\n';

    std::cout << "v1 += v2 --> " << (v1 += v2) <<'\n';
    std::cout << "v1 = "<< v1 <<'\n';
    std::cout<<'\n';

    std::cout << "++v1 --> "<< ++v1 <<'\n';  // resoult: (2,2)
    std::cout << "v1++ --> "<< v1++ <<'\n';  // resoult: (2,2) ((v++ returns a copy of v preincremented))
    std::cout << "v1 = "<< v1 <<'\n';       // resoult: (3,3) ((v postincremented))
    std::cout<<'\n';

    std::string vec_str = "test";
    //vec_str = v1;                                 // przykład NIEJAWNEJ KONWERSJI
    vec_str = static_cast<std::string>(v1);         // przykład    JAWNEJ KONWERSJI

    std::cout << "v1 as string --> "<< vec_str <<'\n';
    std::cout<<'\n';

    return 0;
}
