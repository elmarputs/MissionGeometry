//
// Created by elmar on 16-11-18.
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
}

#endif