#include "LedState.h"
#include "States.h"
#include "LedMatrixApp.h"
#include <cinder/Utilities.h>
#include "LedManager.h"

namespace
{
	const int n_countdown = 2;
}

void StateAnimal::enter()
{	
	printf("%d %s\n", _dev_id, "Animal");
	resetTimer();
	_app.changeToState(LedState::create(_app, _dev_id, T_SPARK_INT));
}

void StateAnimal::update()
{
	if (getElapsedSeconds() > n_countdown)
		_app.changeToRandomInteractiveState(_dev_id);
}

void StateAnimal::draw()
{


}

void StateAnimal::exit()
{

}
