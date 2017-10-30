#include "vectors.h"

t_mat4	init_identiny(void)
{
	t_mat4	m;
	
	m.m[0][0] = 1; m.m[0][1] = 0; m.m[0][2] = 0; m.m[0][3] = 0;
	m.m[1][0] = 0; m.m[1][1] = 1; m.m[1][2] = 0; m.m[1][3] = 0;
	m.m[2][0] = 0; m.m[2][1] = 0; m.m[2][2] = 1; m.m[2][3] = 0;
	m.m[3][0] = 0; m.m[3][1] = 0; m.m[3][2] = 0; m.m[3][3] = 1;
	return (m);
}

t_mat4	init_translation(float x, float y, float z)
{
	t_mat4	m;

	m.m[0][0] = 1; m.m[0][1] = 0; m.m[0][2] = 0; m.m[0][3] = x;
	m.m[1][0] = 0; m.m[1][1] = 1; m.m[1][2] = 0; m.m[1][3] = y;
	m.m[2][0] = 0; m.m[2][1] = 0; m.m[2][2] = 1; m.m[2][3] = z;
	m.m[3][0] = 0; m.m[3][1] = 0; m.m[3][2] = 0; m.m[3][3] = 1;
	return (m);
}