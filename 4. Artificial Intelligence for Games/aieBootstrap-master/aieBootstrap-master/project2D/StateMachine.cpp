#include "StateMachine.h"
#include "BaseState.h"
#include "ChaseState.h"
#include "FleeState.h"
#include "Agent.h"

StateMachine::StateMachine()
{
	m_pCurrentState = nullptr;
	m_StateList.push_back(new ChaseState());
	m_StateList.push_back(new FleeState());
}
StateMachine::~StateMachine()
{
	for (int i = 0; i < m_StateList.size(); ++i)
	{
		delete m_StateList[i];
	}
}

void StateMachine::Update(Agent* agent, float fDeltaTime)
{
	if (m_pCurrentState)
		m_pCurrentState->OnUpdate(this, agent, fDeltaTime);
}

void StateMachine::ChangeState(EStates eNewState)
{

	if (m_pCurrentState)
		m_pCurrentState->OnExit();
	if (eNewState == NO_STATE)
	{
		m_pCurrentState = nullptr;
		return;
	}
	m_pCurrentState = m_StateList[eNewState];

	if (m_pCurrentState)
		m_pCurrentState->OnEnter();

}