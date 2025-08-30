#pragma once
#define _USE_MATH_DEFINES 

#include <cmath>
#include <string>

struct Vector3 {
    double x;
    double y;
    double z;

    //rounding to zero if less than a threshold
    Vector3& round(double eps = 1e-10) {
        if (std::fabs(x) < eps) x = 0.0;
        if (std::fabs(y) < eps) y = 0.0;
        if (std::fabs(z) < eps) z = 0.0;
        return *this;
    }
};

class Curve
{
public:
    Curve() = default;
	virtual ~Curve() = default;

	virtual Vector3 getPoint(double t) const = 0;
	virtual Vector3 getDerivative(double t) const = 0;

    virtual std::string getName() const = 0;
};
