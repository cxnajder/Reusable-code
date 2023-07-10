#include <iostream>
#include <vector>
#include <algorithm>
//#include <execution> // std::sort( std::execution::par, vec.begin(), vec.end() );

class Vector2D {
    double x;
    double y;
public:
    Vector2D(double x_, double y_): x(x_), y(y_) {}
    bool operator < (const Vector2D & R_vec)
    {
        return (( this->x + this-> y ) < ( R_vec.x + R_vec.y ));
    }

    friend std::ostream & operator<<(std::ostream & ostr, const Vector2D & v);

};

std::ostream & operator<<(std::ostream & ostr, const Vector2D & v) { // OSTREAM CAN ONLY BE PASTED BY REFERENCE!
    ostr << '(' << v.x << ", " << v.y << ')';
    return ostr;
}

template <typename T>
std::ostream & operator << (std::ostream & strm, const std::vector<T> & vec)
{
    for (auto vec_element: vec)
        strm << vec_element << ", ";
    return strm;
}

int main( void )
{
    std::vector<Vector2D> v_v2d = { {2, 5}, {1, 8}, {0.9, 8}, {-8, 9}, {0.9, 0} };

    std::cout << "2D vectors before sorting:\n";
    std::cout << v_v2d << '\n';

    std::sort( v_v2d.begin(), v_v2d.end() );

    std::cout << "2D vectors after sorting:\n";
    std::cout << v_v2d << '\n';

    return 0;
}