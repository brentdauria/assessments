#pragma once
class Agent;

class Basebehaviour
{
public:
	Basebehaviour();
	virtual ~Basebehaviour();

	virtual void Update(Agent* pAgent, float fDeltaTime) = 0;

	float Weighting;
};

