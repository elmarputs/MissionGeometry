//
// Created by elmar on 15-12-18.
//

#ifndef MISSIONGEOMETRY_EULERINTEGRATOR_H
#define MISSIONGEOMETRY_EULERINTEGRATOR_H

#include "integrator.h"

namespace missiongeometry
{
	template < class StateType >
	class EulerIntegrator : public Integrator< StateType >
	{
	public:

		EulerIntegrator( TimeType stepSize, StateType initialState, StateType (*stateDerivativeFunction)(TimeType, StateType) = nullptr )
			: Integrator< StateType >( stepSize, initialState, stateDerivativeFunction )
		{
		}

		StateType performIntegrationStep(TimeType currentTime, StateType currentState)
		{
			StateType stateDerivative = this->stateDerivativeFunction_(currentTime, currentState);

			return currentState + this->stepSize_ * stateDerivative;
		}
	};
}

#endif //MISSIONGEOMETRY_EULERINTEGRATOR_H
