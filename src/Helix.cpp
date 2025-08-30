#include "Helix.h"

Helix::Helix(double radius, double step) 
	: _radius(radius)
	, _step(step)
{
}

Vector3 Helix::getPoint(double t) const
{
	return { _radius * cos(t), _radius * sin(t), (_step / (2 * M_PI)) * t };
}

Vector3 Helix::getDerivative(double t) const
{
	return { _radius * -sin(t), _radius * cos(t), _step / (2 * M_PI) };
}

std::string Helix::getName() const
{
	return "Helix";
};
