//
// Created by elmar on 20-11-18.
//

#include "include/basicMath.h"
#include "include/constants.h"

double MissionGeometry::degToRad(const double degrees)
{
	return degrees * MissionGeometry::pi / 180.0;
}

MissionGeometry::Vector MissionGeometry::crossProduct(const MissionGeometry::Vector &vector1, const MissionGeometry::Vector &vector2)
{
	double x = vector1.y * vector2.z - vector1.z * vector2.y;
	double y = -(vector1.x * vector2.z - vector1.z * vector2.x);
	double z = vector1.x * vector2.y - vector1.y * vector2.x;
	MissionGeometry::Vector temp = {x, y, z};

	return temp;
}

double MissionGeometry::dotProduct(const MissionGeometry::Vector &vector1, const MissionGeometry::Vector &vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}
