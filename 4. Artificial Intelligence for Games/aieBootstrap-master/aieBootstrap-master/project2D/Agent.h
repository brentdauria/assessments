#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include <vector>
#include "Basebehaviour.h"

class Agent : public GameObject
{
public:
	Agent(aie::Texture* pTexture, Vector2 v2Pos, float fRotRadians);
	virtual ~Agent();

	virtual void Update(float fDeltaTime);
	virtual void Draw(aie::Renderer2D* pRenderer);

	Vector2 GetVelocity();
	void SetVelocity(Vector2 v2Velocity);
	float GetMaxSpeed();

	void AddBehaviour(Basebehaviour* pBehaviour, float Weighting);

protected:
	Vector2 m_v2Velocity;
	float m_fMaxSpeed;

	std::vector<Basebehaviour*> m_BehaviourList;
};

