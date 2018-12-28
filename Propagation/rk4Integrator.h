//
// Created by elmar on 15-12-18.
//

#ifndef MISSIONGEOMETRY_RK4INTEGRATOR_H
#define MISSIONGEOMETRY_RK4INTEGRATOR_H

#include "integrator.h"

namespace missiongeometry
{
	template < class StateType >
	class RK4Integrator : public Integrator< StateType >
	{

	public:

		RK4Integrator( TimeType stepSize, StateType initialState, StateType (*stateDerivativeFunction)(TimeType, StateType) = nullptr )
						: Integrator< StateType >( stepSize, initialState, stateDerivativeFunction )
		{
		}

		StateType performIntegrationStep(TimeType currentTime, StateType currentState) override;
	};
}


#endif //MISSIONGEOMETRY_RK4INTEGRATOR_H
