#include <iostream>

class Vector2D {
    double x;
    double y;
public:
    // konstruktory (2- i 0-argumentowe)
    Vector2D(double x_, double y_): x(x_), y(y_) {};
    Vector2D(): Vector2D(0, 0) {}; // konstruktor delegujący

    Vector2D operator+(const Vector2D & v2) const; // operator dodawania dwuch wektorów
    Vector2D operator-(const Vector2D & v2) const;
    Vector2D operator*(const double & scalar) const; // operator mnożenia wektor przez skalar
    Vector2D operator/(const double & scalar) const;
};

Vector2D Vector2D::operator+(const Vector2D & v2) const {
    return {this->x + v2.x, this->y + v2.y};
}

Vector2D Vector2D::operator-(const Vector2D & v2) const {
    return {this->x - v2.x, this->y - v2.y};
}

Vector2D Vector2D::operator*(const double & scalar) const {
    return {this->x * scalar, this->y * scalar};
}

Vector2D Vector2D::operator/(const double & scalar) const {
    return {this->x / scalar, this->y / scalar};
}


int main(int argc, char const *argv[])
{
    Vector2D v1 = {1, 0};
    Vector2D v2 = {0, 1};
    Vector2D v3;
    v1 + v2;
    return 0;
}
