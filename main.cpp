#include <iostream>
#include <math.h>

#include "Basics/constants.h"
#include "Basics/basicTypes.h"
#include "Basics/coordinateTransformations.h"
#include "Basics/basicMath.h"


using namespace missiongeometry;

int main()
{
	//KeplerianStateVector kState = {6787.746891, 0.000731104, degToRad(51.68714486), degToRad(74.21987137), degToRad(127.5486706),
	//							0.0, 0.0, degToRad(24.06608426)};

	//KeplerianStateVector kState1 = {12269.6875912, 0.004932091570, degToRad(109.823277603), degToRad(106.380426142), degToRad(134.625563565),
	//                               0.0, 0.0, degToRad(301.149932402)};

	//CartesianStateVector cState = convertKeplerianToCartesian(kState1);

	CartesianStateVector cState2 = {1.7152e3, 1.9773e4, 0,
								 -4.4700, 1.3360, 0};

	KeplerianStateVector kState2 = convertCartesianToKeplerian(cState2);

	return 0;
}