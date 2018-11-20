//
// Created by elmar on 20-11-18.
//

#include "include/basicTypes.h"

using namespace MissionGeometry;

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
