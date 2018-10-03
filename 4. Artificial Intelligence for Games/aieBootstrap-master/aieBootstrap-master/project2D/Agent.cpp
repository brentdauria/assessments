#include "Agent.h"



Agent::Agent(aie::Texture* pTexture, Vector2 v2Pos, float fRotRadians) : 
	GameObject(pTexture, v2Pos, fRotRadians)
{
	m_fMaxSpeed = 1000.0f;
}


Agent::~Agent()
{
}

void Agent::Update(float fDeltaTime)
{
	Vector2 v2TotalForce;

	for (int i = 0; i < m_BehaviourList.size(); ++i)
	{
//		Vector2 v2Force = m_BehaviourList[i]->Update(this, fDeltaTime);
	}

	Vector2 v2Pos = GetPosition();
	v2Pos = v2Pos + m_v2Velocity * fDeltaTime;
	SetPosition(v2Pos);
}

void Agent::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_Transform);
}

Vector2 Agent::GetVelocity()
{
	return m_v2Velocity;
}

void Agent::SetVelocity(Vector2 v2Velocity)
{
	m_v2Velocity = v2Velocity;
}

float Agent::GetMaxSpeed()
{
	return m_fMaxSpeed;
}

void Agent::AddBehaviour(Basebehaviour* pBehaviour, float fWeighting)
{
	pBehaviour->Weighting = fWeighting;
	m_BehaviourList.push_back(pBehaviour);
}