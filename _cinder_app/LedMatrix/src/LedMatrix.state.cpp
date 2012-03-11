#include "LedMatrixApp.h"
#include "LedState.h"
#include <cinder/Rand.h>

void LedMatrixApp::changeToState(LedState* new_state)
{
	assert(new_state != NULL);
	int id = new_state->_dev_id;
	if (current_states[id])
	{
		current_states[id]->exit();
	}
	current_states[id] = shared_ptr<LedState>(new_state);
	current_states[id]->enter();
}

void LedMatrixApp::setupStates()
{
	for (int dev=0;dev<2;dev++)
	{
		changeToRandomIdleState(dev);
	}
}

void LedMatrixApp::changeToRandomIdleState( int dev )
{
#if 0
	static StateType idle_states[3] = {T_SPARK,T_BREATHE,T_LOTS};
	changeToStateAmong(dev, idle_states);
#else
	changeToState(LedState::create(*this, dev, T_BREATHE));
#endif
	assert(LedState::isIdleState(current_states[dev]->_type));
}

void LedMatrixApp::changeToRandomInteractiveState( int dev )
{
#if 0
	static StateType interative_states[3] = {T_FOLLOWING,T_SPARK_INT,T_ANIMAL};
	changeToStateAmong(dev, interative_states);
#else	
	changeToState(LedState::create(*this, dev, T_FOLLOWING));
#endif
	assert(!LedState::isIdleState(current_states[dev]->_type));
}

void LedMatrixApp::changeToStateAmong( int dev, StateType state_types[3])
{ 
	StateType current = T_INVALID;
	if (current_states[dev])
		current = current_states[dev]->_type;
	int next = randInt(3);
	while (state_types[next] == current)
	{
		next = randInt(3);
	}
	LedState* new_st = LedState::create(*this, dev, state_types[next]);
	if (new_st)
		changeToState(new_st);
} 
