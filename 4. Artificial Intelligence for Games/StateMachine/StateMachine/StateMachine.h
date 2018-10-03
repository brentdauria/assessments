#pragma once
#include <vector>

class baseState;

enum EStates
{
	ESTATE_PATROL,
	ESTATE_ATTACK
};

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update();
	void changeState(EStates eNewState);

private:
	baseState * m_pCurrentState;
	std::vector<baseState*> m_StateList;
};

