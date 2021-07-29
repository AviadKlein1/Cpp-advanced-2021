#include "Circle.h"

Circle::Circle(float r) :Shape(1)
{
    radius = r;
}

    void  Circle::area()const
    {
        cout << (float)(pow(radius, 2) * 3.14);
        return;
    }

    bool Circle::isSpecial()const
{
    if (this->Points->getx() == 0 && this->Points->gety() == 0)return true;
    else return false;
}

    void Circle::printSpecial()const
    {
       cout << "A canonical circle with a radius " << radius << endl;
        return;
    }

   