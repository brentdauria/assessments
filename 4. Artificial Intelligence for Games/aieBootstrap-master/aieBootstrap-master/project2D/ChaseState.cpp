#include "ChaseState.h"
#include "Input.h"
#include "Agent.h"
#include "Vector2.h"
ChaseState::ChaseState()
{

}
ChaseState::~ChaseState()
{

}
void ChaseState::OnEnter()
{

}
void ChaseState::OnUpdate(StateMachine* pStateMachine, Agent* agent, float fDeltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	Vector2 MousePos;
	MousePos.x = input->getMouseX();
	MousePos.y = input->getMouseY();

	Vector2 Steer = MousePos - agent->GetPosition();
	Steer.normalise();
	Steer = Steer * 1000;
	Vector2 Force = Steer - agent->GetVelocity();
	Vector2 velocity = agent->GetVelocity();
	velocity = velocity + Force * fDeltaTime;
	agent->SetVelocity(velocity);
}
void ChaseState::OnExit()
{

}
