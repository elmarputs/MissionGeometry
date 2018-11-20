#include <iostream>

#include "include/constants.h"
#include "include/basicTypes.h"
#include "include/coordinateTransformations.h"
#include "include/basicMath.h"
#include <math.h>

using namespace MissionGeometry;

int main()
{
	KeplerianStateVector kState = {7096.137, 0.0011219, degToRad(92.0316), degToRad(120.6878), degToRad(296.1384),
								degToRad(239.5437), 0.0, 0.0};

	CartesianStateVector cState = convertKeplerianToCartesian(kState);

	CartesianStateVector cState2 = {3126.97499, -6374.44574, 28.67359, -0.25491197, -0.08330107, 7.48570674};

	KeplerianStateVector kState2 = convertCartesianToKeplerian(cState2);

	return 0;
}