#pragma once
#include "Shape.h"
#include<cmath>
class Triangle :
    public Shape
{
public:
    Triangle();
    void  area() const;
    bool  isSpecial() const;
    void  printSpecial() const;

};

