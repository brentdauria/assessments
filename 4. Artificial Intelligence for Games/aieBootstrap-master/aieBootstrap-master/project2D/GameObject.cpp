#include "GameObject.h"



GameObject::GameObject(aie::Texture* pTexture, Vector2 v2Pos, float fRotRadians)
{
	m_pTexture = pTexture;
	SetPosition(v2Pos);
	SetRotation(fRotRadians);
}

GameObject::~GameObject()
{

}

void GameObject::SetPosition(Vector2 v2Pos)
{
	m_Transform.m[6] = v2Pos.x;
	m_Transform.m[7] = v2Pos.y;
}
Vector2 GameObject::GetPosition()
{
	Vector2 v2Result;
	v2Result.x = m_Transform.m[6];
	v2Result.y = m_Transform.m[7];
	return v2Result;
}

void GameObject::SetRotation(float fRadians)
{
	m_fRotation = fRadians;
	m_Transform.setRotateZ(fRadians);
}

float GameObject::GetRotation()
{
	return m_fRotation;
}