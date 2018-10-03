#include "Duck.h"
#include "SeekBehaviour.h"
#include "Grid.h"
#include "StateMachine.h"
#include "Input.h"
#include "Agent.h"

Duck::Duck(aie::Texture* pTexture, Vector2 v2Pos, float fRotRadians, Grid* pGrid) :
	Agent(pTexture, v2Pos, fRotRadians)
{
	m_fMaxSpeed = 2000.0f;

	m_pSeekBehaviour = new SeekBehaviour();
	//AddBehaviour(m_pSeekBehaviour);

	m_pGrid = pGrid;
	m_Path = m_pGrid->GetPath(Vector2(500, 300), Vector2(600, 610), false);

	m_pStateMachine = new StateMachine();
	m_pStateMachine->ChangeState(ESTATE_CHASE);
	isFollowing = false;
	nextWaypoint = 0;
}


Duck::~Duck()
{
	delete m_pSeekBehaviour;
	delete m_pStateMachine;
}

void Duck::Update(float fDeltaTime)
{
	m_pStateMachine->Update(this, fDeltaTime);
	Agent::Update(fDeltaTime);
	aie::Input* input = aie::Input::getInstance();
	if (input->wasKeyPressed(aie::INPUT_KEY_F))
	{
		m_pStateMachine->ChangeState(ESTATE_FLEE);
		isFollowing = false;
	}
	else if (input->wasKeyPressed(aie::INPUT_KEY_R))
	{
		m_pStateMachine->ChangeState(ESTATE_CHASE);
		isFollowing = false;
	}
	else if (input->wasKeyPressed(aie::INPUT_KEY_T))
	{
		m_pStateMachine->ChangeState(NO_STATE);
		SetVelocity(Vector2());
		isFollowing = true;
		nextWaypoint = 0;
	}
	if (isFollowing == true)
	{
		//seek towards m_Path[nextWaypoint]

		Vector2 Steer = m_Path[nextWaypoint] - GetPosition();
		Steer.normalise();
		Steer = Steer * 100;
		Vector2 Force = Steer - GetVelocity();
		Vector2 velocity = GetVelocity();
		velocity = velocity + Force * fDeltaTime;
		SetVelocity(velocity);
		//Check distance between duck and target point (target-duckpos).magnitude
		float distance = (m_Path[nextWaypoint] - GetPosition()).magnitude();
		//if distance is less than some number
		if (distance <= 30)
			//then increase nextWaypoint
		{
			nextWaypoint++;
			if (nextWaypoint >= m_Path.size())
			{
				nextWaypoint = 0;
			}
		}
	}
	
}

void Duck::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->setRenderColour(0xFF0000FF);
	for (int i = 0; i < m_Path.size(); ++i)
	{
		pRenderer->drawBox(m_Path[i].x, m_Path[i].y, NODE_SIZE, NODE_SIZE);
	}
	pRenderer->setRenderColour(0xFFFFFFFF);

	Agent::Draw(pRenderer);
}