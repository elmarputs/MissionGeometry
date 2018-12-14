//
// Created by Elmar Puts on 20-11-18.
// This file provides the implementation of the Vector class.
// v1.0 (29-11-2018): Vector provides methods for getting the unit vector and magnitude of a vector and overrides the standard + and * operators.
//

#include "basicTypes.h"
#include <math.h>

using namespace missiongeometry;

double Vector::magnitude()
{
	return std::sqrt(x*x + y*y + z*z);
}

Vector Vector::getUnitVector()
{
	double length = magnitude();
	Vector unitVector = {x/length, y / length, z/length};

	return unitVector;
}

Vector Vector::operator-(const Vector &v)
{
	Vector result = {x - v.x, y - v.y, z - v.z};
	return result;
}

Vector Vector::operator*(const double factor)
{
	Vector result = {x * factor, y * factor, z * factor};
	return result;
}
