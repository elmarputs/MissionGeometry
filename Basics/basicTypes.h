//
// Created by Elmar Puts on 16-11-18.
// This file provides the declaration of the Vector class and two state vector structs (for Cartesian and Kepler states).
//

#ifndef MISSIONGEOMETRY_BASICTYPES_H
#define MISSIONGEOMETRY_BASICTYPES_H

namespace missiongeometry
{
	typedef double TimeType;
	typedef double stateVariableType;

	struct CartesianStateVector
	{
		stateVariableType x;
		stateVariableType y;
		stateVariableType z;

		stateVariableType v_x;
		stateVariableType v_y;
		stateVariableType v_z;
	};

	struct KeplerianStateVector
	{
		stateVariableType a;
		stateVariableType e;
		stateVariableType i;
		stateVariableType omega;
		stateVariableType Omega;
		stateVariableType trueAnomaly;
		stateVariableType eccentricAnomaly;
		stateVariableType meanAnomaly;
	};

	class Vector
	{
	public:
		stateVariableType x;
		stateVariableType y;
		stateVariableType z;

		double magnitude();
		Vector getUnitVector();

		Vector operator-(const Vector& v);
		Vector operator*(const double factor);
	};
}

#endif