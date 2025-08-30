#pragma once
#include "Curve.h"

class Circle : public Curve
{
public:
    explicit Circle(double radius);

    Vector3 getPoint(double t) const override;
    Vector3 getDerivative(double t) const override;

    std::string getName() const override;

    double getRadius() const;

private:
    double _radius;
};

