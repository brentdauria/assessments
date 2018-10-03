#include "Matrix3.h"
#include <math.h>


Matrix3::Matrix3()
{
	m[0] = 1.0f;
	m[1] = 0.0f;
	m[2] = 0.0f;

	m[3] = 0.0f;
	m[4] = 1.0f;
	m[5] = 0.0f;
	
	m[6] = 0.0f;
	m[7] = 0.0f;
	m[8] = 1.0f;
}

Matrix3::Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
{
	m[0] = m0;
	m[1] = m1;
	m[2] = m2;

	m[3] = m3;
	m[4] = m4;
	m[5] = m5;

	m[6] = m6;
	m[7] = m7;
	m[8] = m8;

}

Matrix3::~Matrix3()
{

}

Vector3 Matrix3::operator* (Vector3 rhs)
{
	Vector3 result;

	result.x = (m[0] * rhs.x) + (m[3] * rhs.y) + (m[6] * rhs.z);
	result.y = (m[1] * rhs.x) + (m[4] * rhs.y) + (m[7] * rhs.z);
	result.z = (m[2] * rhs.x) + (m[5] * rhs.y) + (m[8] * rhs.z);

	return result;
}

Matrix3 Matrix3::operator* (Matrix3 rhs)
{
	Matrix3 result;

	result.m[0] = (m[0] * rhs.m[0]) + (m[3] * rhs.m[1]) + (m[6] * rhs.m[2]);
	result.m[1] = (m[1] * rhs.m[0]) + (m[4] * rhs.m[1]) + (m[7] * rhs.m[2]);
	result.m[2] = (m[2] * rhs.m[0]) + (m[5] * rhs.m[1]) + (m[8] * rhs.m[2]);

	result.m[3] = (m[0] * rhs.m[3]) + (m[3] * rhs.m[4]) + (m[6] * rhs.m[5]);
	result.m[4] = (m[1] * rhs.m[3]) + (m[4] * rhs.m[4]) + (m[7] * rhs.m[5]);
	result.m[5] = (m[2] * rhs.m[3]) + (m[5] * rhs.m[4]) + (m[8] * rhs.m[5]);

	result.m[6] = (m[0] * rhs.m[6]) + (m[3] * rhs.m[7]) + (m[6] * rhs.m[8]);
	result.m[7] = (m[1] * rhs.m[6]) + (m[4] * rhs.m[7]) + (m[7] * rhs.m[8]);
	result.m[8] = (m[2] * rhs.m[6]) + (m[5] * rhs.m[7]) + (m[8] * rhs.m[8]);

	return result;
}

void Matrix3::setRotateX(float rotation)
{
	
	m[4] = cosf(rotation);
	m[5] = sinf(rotation);
	m[7] = -sinf(rotation);
	m[8] = cosf(rotation);
}

void Matrix3::setRotateY(float rotation)
{
	m[0] = cosf(rotation);
	m[2] = -sinf(rotation);
	m[6] = sinf(rotation);
	m[8] = cosf(rotation);
}

void Matrix3::setRotateZ(float rotation)
{
	m[0] = cosf(rotation);
	m[1] = sinf(rotation);
	m[3] = -sinf(rotation);
	m[4] = cosf(rotation);
	
}

Vector3& Matrix3::operator[](int index)
{
	return *(Vector3*)&m[index * 3];
}

Matrix3::operator float*()
{
	return &m[0];
}
