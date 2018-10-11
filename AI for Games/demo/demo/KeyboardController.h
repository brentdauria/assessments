#pragma once
#include "IBehavior.h"
#include "Input.h"

class KeyboardController : public IBehavior
{
public:
	KeyboardController(aie::Input* input);

	void virtual update(float a_dt, Agent* agent);

	~KeyboardController();

private:
	aie::Input* input;

};

