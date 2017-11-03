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

t_mat4	quat_to_mat(t_quat q)
{
	t_mat4	res;
	t_mat4	m1;
	t_mat4	m2;

	q = quat_norm(q);
	m1 = init_quat_m1(q);
	m2 = init_quat_m2(q);
	res = mat_mult(&m1, &m2);
	return (res);
}

////Matrix44 CreateRotation(const Quaternion& quat)
//{
//Matrix44 m1(
//quat.w, quat.z, -quat.y, quat.x,
//-quat.z, quat.w, quat.x, quat.y,
//quat.y, -quat.x, quat.w, quat.z,
//-quat.x, -quat.y, -quat.z, quat.w );
//
//Matrix44 m2(
//quat.w, quat.z, -quat.y, -quat.x,
//-quat.z, quat.w, quat.x, -quat.y,
//quat.y, -quat.x, quat.w, -quat.z,
//quat.x, quat.y, quat.z, quat.w );
//
//return m1 * m2;
////}