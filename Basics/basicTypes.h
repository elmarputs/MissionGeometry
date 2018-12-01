//
// Created by Elmar Puts on 16-11-18.
// This file provides the declaration of the Vector class and two state vector structs (for Cartesian and Kepler states).
//

#ifndef MISSIONGEOMETRY_BASICTYPES_H
#define MISSIONGEOMETRY_BASICTYPES_H

namespace MissionGeometry
{
	struct CartesianStateVector
	{
		double x;
		double y;
		double z;

		double v_x;
		double v_y;
		double v_z;
	};

	struct KeplerianStateVector
	{
		double a;
		double e;
		double i;
		double omega;
		double Omega;
		double trueAnomaly;
		double eccentricAnomaly;
		double meanAnomaly;
	};

	class Vector
	{
	public:
		double x;
		double y;
		double z;

		double magnitude();
		Vector getUnitVector();

		Vector operator-(const Vector& v);
		Vector operator*(const double factor);
	};
}

#endif