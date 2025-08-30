#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
public:
    explicit Ellipse(double radiusA, double radiusB);

    Vector3 getPoint(double t) const override;
    Vector3 getDerivative(double t) const override;

    std::string getName() const override;

private:
    double _radiusA;
    double _radiusB;
};

