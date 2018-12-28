//
// Created by elmar on 14-12-18.
//

#ifndef MISSIONGEOMETRY_INTEGRATOR_H
#define MISSIONGEOMETRY_INTEGRATOR_H

#include <iostream>

#include "../Basics/basicTypes.h"

namespace missiongeometry
{
	template < class StateType >
	class Integrator
	{
	protected:
		// Member variables
		TimeType stepSize_;
		StateType initialState_;
		StateType (*stateDerivativeFunction_)(TimeType, StateType);

	public:

		Integrator( TimeType stepSize, StateType initialState, StateType (*stateDerivativeFunction)(TimeType, StateType) = nullptr )
			: stepSize_(stepSize), initialState_(initialState), stateDerivativeFunction_(stateDerivativeFunction)
		{
		}

		// Perform next integration step
		virtual StateType performIntegrationStep(TimeType currentTime, StateType currentState) = 0;

		virtual void changeStepSize( const TimeType newStepSize )
		{
			if ( newStepSize > 0.0 )
			{
				stepSize_ = newStepSize;
			}
			else
			{
				std::cout << "Negative step size given, not changing current step size.\n";
			}
		}

		virtual TimeType getStepSize( )
		{
			return stepSize_;
		}
	};
}

#endif //MISSIONGEOMETRY_INTEGRATOR_H
