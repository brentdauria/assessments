#include "AttackState.h"
#include <iostream>
#include "StateMachine.h"

AttackState::AttackState()
{
}


AttackState::~AttackState()
{
}

void OnEnter()
{
	std::cout << "Starting my attack" << std::endl;
}

void OnUpdate(StateMachine* pStateMachine)
{
	std::cout << "I attacked you!" << std::endl;
	std::cout << "Are you still there?" << std::endl;

	char result[100];
	std::cin >> result;
	if (strcmp(result, "n") == 0)
	{
		pStateMachine->changeState(ESTATE_PATROL);
	}
}

void OnExit()
{
	std::cout << "Fine! im leaving" << std::endl;
}