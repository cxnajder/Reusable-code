#include <iostream>
#include <memory>
#include <vector>

#include "ShapeFactory.h"

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
