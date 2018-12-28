//
// Created by elmar on 15-12-18.
//

#include "../Basics/basicTypes.h"
#include "rk4Integrator.h"

namespace missiongeometry
{
	template < class StateType >

	StateType RK4Integrator< StateType >::performIntegrationStep(TimeType currentTime, StateType currentState)
	{
		std::cout << "Performing integration step...\n";
		return currentState;
	}

	template class RK4Integrator< CartesianStateVector >;
}