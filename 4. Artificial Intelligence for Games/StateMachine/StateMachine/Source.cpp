#include <iostream>
#include "StateMachine.h"



int main()
{
	StateMachine* pStateMachine = new StateMachine();
	pStateMachine->changeState(ESTATE_PATROL);

	while (true)
	{
		pStateMachine->Update();
	}

	system("pause");
	return 0;
}