//
// Created by elmar on 16-11-18.
//

#ifndef MISSIONGEOMETRY_COORDINATETRANSFORMATIONS_H
#define MISSIONGEOMETRY_COORDINATETRANSFORMATIONS_H

#include "../Basics/basicTypes.h"

namespace MissionGeometry
{
	KeplerianStateVector convertCartesianToKeplerian(CartesianStateVector &cartesianStateVector);
	CartesianStateVector convertKeplerianToCartesian(KeplerianStateVector &keplerianStateVector);
}

#endif //MISSIONGEOMETRY_COORDINATETRANSFORMATIONS_H
