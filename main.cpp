#define _USE_MATH_DEFINES 

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include "CurveUtils.h"

using namespace std;

int main()
{
    //Creating random curves container
    std::vector<std::shared_ptr<Curve>> curves;
    for (int i = 0; i < 100; ++i) {
        curves.emplace_back(CurveUtils::createRandomCurve());
    }

    //For each curve printing point and derivative at t = PI/4
    const double t = M_PI / 4;
    for (const auto& curve : curves) {
        Vector3 point = curve->getPoint(t).round();
        Vector3 derivative = curve->getDerivative(t).round();
        std::cout 
            << curve->getName() << ": " 
            << "point(" << point.x << ", " << point.y << ", " << point.z << "); "
            << "derivative(" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")\n";
    }

    std::cout << "\nCreating second container of circles: \n";

    //Creating container of circles from the first container via pinters.
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curves) {
        //Casting Curve pointer to Circle pointer
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.emplace_back(circle);
        }
    }

    //Printing container of circles
    CurveUtils::printCircles(circles);

    std::cout << "\nSorting second container of circles: \n";

    //Sorting second container in the ascending order of circles’ radii.
    std::sort(circles.begin(), circles.end(), [](const auto& a, const auto& b) {
        return a->getRadius() < b->getRadius();
    });

    //Printing sorted container of circles
    CurveUtils::printCircles(circles);

    //Caclulating total sum of radii of all curves in the second container.
    std::cout << "\nTotal sum of radii in second container: " << CurveUtils::calculateRadiiSum(circles) << std::endl;

    //Waiting for user input
    system("pause");
}
