#pragma once
#include <Vector>

class Agent;
class BaseState;

enum EStates
{
	ESTATE_CHASE,
	ESTATE_FLEE,
	NO_STATE
};

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(Agent* agent, float fDeltaTime);
	void ChangeState(EStates eNewState);

private:
	BaseState * m_pCurrentState;
	std::vector<BaseState*> m_StateList;
};