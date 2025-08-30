#include "CurveUtils.h"

#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <iostream>
#include <memory>
#include <random>
#include <omp.h>

namespace CurveUtils
{
	std::shared_ptr<Curve> createRandomCurve()
	{
        //making random numbers generator for type of curve and it's params
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> typeDist(0, 2);
        static std::uniform_real_distribution<> paramDist(0.1, 10.0);

        switch (typeDist(gen)) {
        case 0:
            return std::make_shared<Circle>(paramDist(gen));
        case 1:
            return std::make_shared<Ellipse>(paramDist(gen), paramDist(gen));
        case 2:
            return std::make_shared<Helix>(paramDist(gen), paramDist(gen));
        default:
            return nullptr;
        }
	}

    double calculateRadiiSum(const std::vector<std::shared_ptr<Circle>>& circles)
    {
        double sum = 0.0;
        //using OpenMP to calculate sum of radii
#pragma omp parallel for reduction(+:sum)
        for (int i = 0; i < static_cast<int>(circles.size()); i++) {
            sum += circles[i]->getRadius();
        }
        return sum;
    }

    void printCircles(const std::vector<std::shared_ptr<Circle>>& circles) 
    {
        for (const auto& circle : circles) {
            std::cout << circle->getName() << " radius: " << circle->getRadius() << "\n";
        }
    }
}

