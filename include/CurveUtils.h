#pragma once

#include <memory>
#include <vector>

class Curve;
class Circle;
class Ellipse;
class Helix;

namespace CurveUtils
{
	//Creating random curve
	std::shared_ptr<Curve> createRandomCurve();

	//Caclulating sum of radii in vector of Circle objects
	double calculateRadiiSum(const std::vector<std::shared_ptr<Circle>>& circles);

	//Print elements of container of Circle objects
	void printCircles(const std::vector<std::shared_ptr<Circle>>& circles);
}
