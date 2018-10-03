#include "PatrolState.h"
#include <iostream>
#include "StateMachine.h"


PatrolState::PatrolState()
{

}


PatrolState::~PatrolState()
{

}

void OnEnter()
{
	std::cout << "starting patrol!" << std::endl;
}

void OnUpdate(StateMachine* pStateMachine)
{
	std::cout << "Can i see the player?" << std::endl;
	char result[100];
	std::cin >> result;
	if (strcmp(result, "y") == 0)
	{
		pStateMachine->changeState(ESTATE_ATTACK);
	}
}

void OnExit()
{
 
}