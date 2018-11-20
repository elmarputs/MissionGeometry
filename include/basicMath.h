//
// Created by elmar on 20-11-18.
//

#ifndef MISSIONGEOMETRY_BASICMATH_H
#define MISSIONGEOMETRY_BASICMATH_H

#include "basicTypes.h"

namespace MissionGeometry
{
	double degToRad(const double degrees);

	Vector crossProduct(const Vector &vector1, const Vector &vector2);
	double dotProduct(const Vector &vector1, const Vector &vector2);
}

#endif //MISSIONGEOMETRY_BASICMATH_H