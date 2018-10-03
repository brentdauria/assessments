#pragma once
#include "Basebehaviour.h"

class SeekBehaviour : public Basebehaviour
{
public:
	SeekBehaviour();
	~SeekBehaviour();

	void Update(Agent* pAgent, float fDeltaTime);
};

