//
// Created by elmar on 16-11-18.
//

#ifndef MISSIONGEOMETRY_COORDINATETRANSFORMATIONS_H
#define MISSIONGEOMETRY_COORDINATETRANSFORMATIONS_H

#include "basicTypes.h"

namespace missiongeometry
{
	KeplerianStateVector convertCartesianToKeplerian(CartesianStateVector &cartesianStateVector);
	CartesianStateVector convertKeplerianToCartesian(KeplerianStateVector &keplerianStateVector);
}

#endif //MISSIONGEOMETRY_COORDINATETRANSFORMATIONS_H
