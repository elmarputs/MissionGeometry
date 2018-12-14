//
// Created by Elmar Puts on 16-11-18.
// Contains functions that provide basic coordinate transformations.
// v1.0 (29-11-2018): Kepler -> Cartesian & Cartesian -> Kepler transformations available
//
// Note: all equations taken from AE4868 (MGOD) || all units are SI units except for length (km)
//
#include <math.h>
#include "basicTypes.h"
#include "coordinateTransformations.h"
#include "constants.h"
#include "basicMath.h"

using namespace std;
using namespace missiongeometry;


KeplerianStateVector missiongeometry::convertCartesianToKeplerian(CartesianStateVector &state)
{
	Vector R = {state.x, state.y, state.z};
	Vector V = {state.v_x, state.v_y, state.v_z};
	Vector H = crossProduct(R, V);
	double r = R.magnitude();
	double v = V.magnitude();

	Vector I_z = {0.0, 0.0, 1.0};
	Vector N = crossProduct(I_z, H);

	missiongeometry::KeplerianStateVector kState {0};
	kState.a = 1.0 / (2.0/r - v * v / mu_Earth);

	Vector E = (crossProduct(V, H))*(1/mu_Earth) - R*(1/R.magnitude());
	kState.e = E.magnitude();

	kState.i = acos(H.z / H.magnitude());

	double N_xy = sqrt(N.x * N.x + N.y * N.y);
	kState.Omega = atan2(N.y / N_xy, N.x / N_xy);
	if (kState.Omega < 0.0)
	{
		kState.Omega += 2.0*pi;
	}

	double sign;
	if (dotProduct(crossProduct(N.getUnitVector(), E), H) > 0)
	{
		sign = 1.0;
	}
	else
	{
		sign = -1.0;
	}

	kState.omega = sign * acos(dotProduct(E.getUnitVector(), N.getUnitVector()));

	if (dotProduct(crossProduct(E, R), H) > 0)
	{
		sign = 1.0;
	}
	else
	{
		sign = -1.0;
	}

	kState.trueAnomaly = sign * acos(dotProduct(R.getUnitVector(), E.getUnitVector()));
	if (kState.trueAnomaly < 0.0)
	{
		kState.trueAnomaly += 2.0*pi;
	}
	kState.eccentricAnomaly = 2.0 * atan(sqrt((1 - kState.e) / (1 + kState.e)) * tan(kState.trueAnomaly / 2.0));
	kState.meanAnomaly = kState.eccentricAnomaly - kState.e * sin(kState.eccentricAnomaly);

	return kState;
}

CartesianStateVector missiongeometry::convertKeplerianToCartesian(KeplerianStateVector &state)
{
	const double tolerance = 0.00000001;

	if (state.trueAnomaly == 0.0)
	{
		double E0;
		double E = 0.5;
		do
		{
			E0 = E;
			E = E0 + (state.meanAnomaly - E0 + state.e * sin(E0)) / (1 - state.e * cos(E0));
		}
		while (abs(E - E0) > tolerance);

		state.eccentricAnomaly = E;
		state.trueAnomaly = 2 * atan(sqrt((1+state.e)/(1-state.e)) * tan(E/2.0));
		if (state.trueAnomaly < 0.0)
		{
			state.trueAnomaly += 2.0*pi;
		}
	}

	double r = state.a * (1 - state.e * state.e)/(1 + state.e * cos(state.trueAnomaly));

	double ksi = r * cos(state.trueAnomaly);
	double eta = r * sin(state.trueAnomaly);

	double O = state.Omega;
	double o = state.omega;
	double i = state.i;

	double l1 = cos(O) * cos(o) - sin(O) * sin(o) * cos(i);
	double l2 = -cos(O) * sin(o) - sin(O) * cos(o) * cos(i);
	double m1 = sin(O) * cos(o) + cos(O) * sin(o) * cos(i);
	double m2 = -sin(O) * sin(o) + cos(O) * cos(o) * cos(i);
	double n1 = sin(o) * sin(i);
	double n2 = cos(o) * sin(i);

	missiongeometry::CartesianStateVector cState {0};
	cState.x = l1 * ksi + l2 * eta;
	cState.y = m1 * ksi + m2 * eta;
	cState.z = n1 * ksi + n2 * eta;

	double H = sqrt(mu_Earth * state.a * (1 - state.e * state.e));
	cState.v_x = mu_Earth / H * (-l1 * sin(state.trueAnomaly) + l2 * (state.e + cos(state.trueAnomaly)));
	cState.v_y = mu_Earth / H * (-m1 * sin(state.trueAnomaly) + m2 * (state.e + cos(state.trueAnomaly)));
	cState.v_z = mu_Earth / H * (-n1 * sin(state.trueAnomaly) + n2 * (state.e + cos(state.trueAnomaly)));

	return cState;
}
