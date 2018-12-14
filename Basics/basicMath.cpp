//
// Created by Elmar Puts on 20-11-18.
//

#include "basicMath.h"
#include "constants.h"

double missiongeometry::degToRad(const double degrees)
{
	return degrees * missiongeometry::pi / 180.0;
}

missiongeometry::Vector missiongeometry::crossProduct(const missiongeometry::Vector &vector1, const missiongeometry::Vector &vector2)
{
	double x = vector1.y * vector2.z - vector1.z * vector2.y;
	double y = -(vector1.x * vector2.z - vector1.z * vector2.x);
	double z = vector1.x * vector2.y - vector1.y * vector2.x;
	missiongeometry::Vector temp = {x, y, z};

	return temp;
}

double missiongeometry::dotProduct(const missiongeometry::Vector &vector1, const missiongeometry::Vector &vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}
