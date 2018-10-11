#include "KeyBoardController.h"
#include <Input.h>

KeyBoardController::KeyBoardController()
{
	//input = nullptr;
}

KeyBoardController::KeyBoardController(aie::Input * input)
{
	this->input = input;
}

void KeyBoardController::update(Agent * agent, float deltaTime)
{
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		agent->AddForce(Vector2(0, 100.0f));
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		agent->AddForce(Vector2(0, -100.0f));
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		agent->AddForce(Vector2(-100.0f, 0.0f));
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		agent->AddForce(Vector2(100.0f, 0.0f));
	}
}


KeyBoardController::~KeyBoardController()
{
}
