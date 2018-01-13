#include "rt.h"

t_mat4	init_quat_m1(t_quat q)
{
	t_mat4	m;

	m.m[0][0] = q.w;
	m.m[0][1] = q.z;
	m.m[0][2] = -q.y;
	m.m[0][3] = q.x;

	m.m[1][0] = -q.z;
	m.m[1][1] = q.w;
	m.m[1][2] = q.x;
	m.m[1][3] = q.y;

	m.m[2][0] = q.y;
	m.m[2][1] = -q.x;
	m.m[2][2] = q.w;
	m.m[2][3] = q.z;

	m.m[3][0] = -q.x;
	m.m[3][1] = -q.y;
	m.m[3][2] = -q.z;
	m.m[3][3] = q.w;
	return (m);
}

t_mat4	init_quat_m2(t_quat q)
{
	t_mat4	m;

	m.m[0][0] = q.w;
	m.m[0][1] = q.z;
	m.m[0][2] = -q.y;
	m.m[0][3] = -q.x;

	m.m[1][0] = -q.z;
	m.m[1][1] = q.w;
	m.m[1][2] = q.x;
	m.m[1][3] = -q.y;

	m.m[2][0] = q.y;
	m.m[2][1] = -q.x;
	m.m[2][2] = q.w;
	m.m[2][3] = -q.z;

	m.m[3][0] = q.x;
	m.m[3][1] = q.y;
	m.m[3][2] = q.z;
	m.m[3][3] = q.w;
	return (m);
}