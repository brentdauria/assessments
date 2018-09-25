#pragma once
#include "Vector3.h"

class Matrix2
{
public:
	union {
		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		Vector3 axis[3];
	};
	Matrix2();
	~Matrix2();
};

