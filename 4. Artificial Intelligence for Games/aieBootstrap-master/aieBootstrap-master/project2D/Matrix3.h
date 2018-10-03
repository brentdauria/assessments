#pragma once
#include "Vector3.h"
struct Matrix3
{
	Matrix3();
	Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
	~Matrix3();

	Vector3& operator[](int index);
	explicit operator float*();

	void setRotateX(float rotation);
	void setRotateY(float rotation);
	void setRotateZ(float rotation);

	Vector3 operator* (Vector3 rhs);
	Matrix3 operator* (Matrix3 rhs);

	float m[9];
};

