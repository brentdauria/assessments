#include "KeyboardController.h"





KeyboardController::KeyboardController(aie::Input * input)
{
	this->input = input;
}

void KeyboardController::update(float a_dt, Agent * agent)
{
	if (input->isKeyDown(aie::INPUT_KEY_W))
		agent->m_acceleration.y += 50.f ;
	if (input->isKeyDown(aie::INPUT_KEY_S))
		agent->m_acceleration.y -= 50.f ;
	if (input->isKeyDown(aie::INPUT_KEY_A))
		agent->m_acceleration.x -= 50.f ;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		agent->m_acceleration.x += 50.f ;
}

KeyboardController::~KeyboardController()
{
}
