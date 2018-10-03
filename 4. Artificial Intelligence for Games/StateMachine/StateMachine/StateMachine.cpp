#include "StateMachine.h"
#include "baseState.h"
#include "PatrolState.h"
#include "AttackState.h"

StateMachine::StateMachine()
{
	m_pCurrentState = nullptr;
	m_StateList.push_back(new PatrolState());
	m_StateList.push_back(new AttackState());
}

StateMachine::~StateMachine()
{
	for (int i = 0; i < m_StateList.size(); ++i)
	{
		delete m_StateList[i];
	}

}

void StateMachine::Update()
{
	if (m_pCurrentState)
		m_pCurrentState->OnUpdate(this);
}

void StateMachine::changeState(EStates eNewState)
{
	if (m_pCurrentState)
		m_pCurrentState->OnExit();

	m_pCurrentState = m_StateList[eNewState];

	if (m_pCurrentState)
		m_pCurrentState->OnEnter();
}