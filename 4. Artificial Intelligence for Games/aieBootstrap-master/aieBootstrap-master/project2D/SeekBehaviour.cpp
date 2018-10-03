#include "SeekBehaviour.h"
#include <Input.h>
#include "Vector2.h"
#include "Agent.h"

SeekBehaviour::SeekBehaviour()
{
}


SeekBehaviour::~SeekBehaviour()
{
}

void SeekBehaviour::Update(Agent* pAgent, float fDeltaTime)
{
	aie::Input* pInput = aie::Input::getInstance();
	Vector2 v2MousePos;

	v2MousePos.x = (float)pInput->getMouseX();
	v2MousePos.y = (float)pInput->getMouseY();

	// Seek Force
	Vector2 v2Dir = v2MousePos - pAgent->GetPosition();
	v2Dir.normalise();
	v2Dir = v2Dir * pAgent->GetMaxSpeed();
	Vector2 v2Force = v2Dir - pAgent->GetVelocity();
	
	//Linear Motion
	pAgent->SetVelocity(pAgent->GetVelocity()+ v2Force * fDeltaTime);
}