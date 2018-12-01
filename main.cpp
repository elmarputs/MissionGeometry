#include <iostream>
#include <math.h>

#include "constants.h"
#include "basicTypes.h"
#include "coordinateTransformations.h"
#include "basicMath.h"


using namespace MissionGeometry;

int main()
{
	KeplerianStateVector kState = {6787.746891, 0.000731104, degToRad(51.68714486), degToRad(74.21987137), degToRad(127.5486706),
								0.0, 0.0, degToRad(24.06608426)};

	KeplerianStateVector kState1 = {12269.6875912, 0.004932091570, degToRad(109.823277603), degToRad(106.380426142), degToRad(134.625563565),
	                               0.0, 0.0, degToRad(301.149932402)};

	CartesianStateVector cState = convertKeplerianToCartesian(kState1);

	CartesianStateVector cState2 = {10157.7681264, -6475.9970091, 2421.2059518, 1.0992953996, 3.4551059240, 4.3550978095};

	KeplerianStateVector kState2 = convertCartesianToKeplerian(cState2);

	return 0;
}