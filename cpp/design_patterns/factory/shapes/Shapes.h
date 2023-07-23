#include <istream>


enum class ShapeType_ {rectangle, triangle, circle};


struct Position 
{
    int x;
    int y;
};


class Shape 
{
protected:
    Position position;
public:
    virtual ~Shape() {}
    virtual void render() = 0;
};

//------------------------------------


class Rectangle : public Shape 
{
public:
    void render() override;
};

void Rectangle::render() 
{
    std::cout << "renders rectangle\n";
}

//------------------------------------

class Triangle : public Shape 
{
public:
    void render() override;
};

void Triangle::render() 
{
    std::cout << "renders triangle\n";
}

//------------------------------------


class Circle : public Shape 
{
public:
    void render() override;
};

void Circle::render() 
{
    std::cout << "renders circle\n";
}
