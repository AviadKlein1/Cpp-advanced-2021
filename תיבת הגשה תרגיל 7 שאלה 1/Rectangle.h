#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
public:
    Rectangle();
    void  area() const;
    bool  isSpecial() const;
    void  printSpecial() const;

};

