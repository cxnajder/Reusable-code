#pragma once
#include <iostream>
#include "Shapes.h"


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
