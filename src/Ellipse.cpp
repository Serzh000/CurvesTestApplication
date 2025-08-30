#include "Ellipse.h"

Ellipse::Ellipse(double radiusA, double radiusB)
	: _radiusA(radiusA)
	, _radiusB(radiusB) 
{
}

Vector3 Ellipse::getPoint(double t) const
{
	return { _radiusA * cos(t), _radiusB * sin(t), 0.0 };
}

Vector3 Ellipse::getDerivative(double t) const
{
	return { _radiusA * -sin(t), _radiusB * cos(t), 0.0 };
}

std::string Ellipse::getName() const
{
	return "Ellipse";
}
