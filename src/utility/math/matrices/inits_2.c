#include "math/math.h"

t_mat4	init_rotation_x(float z)
{
	t_mat4	m;

	m.m[0][0] = cosf(z);
	m.m[0][1] = -sinf(z);
	m.m[0][2] = 0;
	m.m[0][3] = 0;

	m.m[1][0] = sinf(z);
	m.m[1][1] = cosf(z);
	m.m[1][2] = 0;
	m.m[1][3] = 0;

	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = 0;

	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_mat4	init_rotation_y(float x)
{
	t_mat4	m;

	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;

	m.m[1][0] = 0;
	m.m[1][1] = cosf(x);
	m.m[1][2] = -sinf(x);
	m.m[1][3] = 0;

	m.m[2][0] = 0;
	m.m[2][1] = sinf(x);
	m.m[2][2] = cosf(x);
	m.m[2][3] = 0;

	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_mat4	init_rotation_z(float y)
{
	t_mat4	m;

	m.m[0][0] = cosf(y);
	m.m[0][1] = 0;
	m.m[0][2] = -sinf(y);
	m.m[0][3] = 0;

	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[1][3] = 0;

	m.m[2][0] = sinf(y);
	m.m[2][1] = 0;
	m.m[2][2] = cosf(y);
	m.m[2][3] = 0;

	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}