//
// Created by Elmar Puts on 16-11-18.
// This file provides the declaration of the Vector class and two state vector structs (for Cartesian and Kepler states).
//

#ifndef MISSIONGEOMETRY_BASICTYPES_H
#define MISSIONGEOMETRY_BASICTYPES_H

namespace missiongeometry
{
	typedef double timeType;
	typedef double stateType;

	struct CartesianStateVector
	{
		stateType x;
		stateType y;
		stateType z;

		stateType v_x;
		stateType v_y;
		stateType v_z;
	};

	struct KeplerianStateVector
	{
		stateType a;
		stateType e;
		stateType i;
		stateType omega;
		stateType Omega;
		stateType trueAnomaly;
		stateType eccentricAnomaly;
		stateType meanAnomaly;
	};

	class Vector
	{
	public:
		stateType x;
		stateType y;
		stateType z;

		double magnitude();
		Vector getUnitVector();

		Vector operator-(const Vector& v);
		Vector operator*(const double factor);
	};
}

#endif