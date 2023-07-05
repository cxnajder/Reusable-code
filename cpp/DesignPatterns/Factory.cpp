#include <iostream>
#include <memory>
#include <vector>

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

//------------------------------------//
//              FACTORY               //
//------------------------------------//


class ShapeFactory
{
public:
    Shape * createShape(ShapeType_ type);
};

Shape * ShapeFactory::createShape(ShapeType_ type)
{
    switch (type)
    {
    case ShapeType_::rectangle:
        return new Rectangle();

    case ShapeType_::triangle:
        return new Triangle();

    case ShapeType_::circle:
        return new Circle();
    default:
        break;
    }
    throw std::runtime_error("ShapeType not handled by SpaheFactory.");
}


int main(int argc, char const *argv[])
{
    ShapeType_ tested_types[] = {ShapeType_::rectangle, ShapeType_::triangle, ShapeType_::circle};
    ShapeFactory factory;
    std::vector<Shape *> shapes;

    for (auto shape_type: tested_types)
        shapes.push_back(factory.createShape(shape_type));

    for (auto shape_ptr: shapes)
    {
        shape_ptr->render();
        delete shape_ptr;
    }
}
