#pragma once
#include "Shape.h"
#include <cmath>
class Circle :
    public Shape
{
public:

    float radius;
    Circle(float r);
    void  area() const;
    bool isSpecial() const;
    void printSpecial() const;
   

};

