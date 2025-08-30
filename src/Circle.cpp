#include "Circle.h"

Circle::Circle(double radius) 
	: _radius(radius) 
{
}

Vector3 Circle::getPoint(double t) const
{
    return { _radius * cos(t), _radius * sin(t), 0.0 };
}

Vector3 Circle::getDerivative(double t) const
{
    return { _radius * -sin(t), _radius * cos(t), 0.0 };
}

std::string Circle::getName() const
{
    return "Circle";
}

double Circle::getRadius() const
{
    return _radius;
}
