#pragma once
#include "Curve.h"

class Helix : public Curve
{
public:
    explicit Helix(double radius, double step);

    Vector3 getPoint(double t) const override;
    Vector3 getDerivative(double t) const override;

    std::string getName() const override;

private:
    double _radius;
    double _step;
};
