#include "rt.h"

t_mat4	mat_mult(t_mat4 *m1, t_mat4 *m2)
{
	int		i;
	int		j;
	t_mat4	res;


	for (int x = 0; x < 4; x++)
	{ // row number of output
		for (int y = 0; y < 4; y++)
		{ // column number of output
			res.m[x][y] = 0;
			for (int z = 0; z < 4; z++)
			{ // four elements are added for this output
				res.m[x][y] += m1->m[x][z] * m2->m[z][y];
			}
		}
	}
	return (res);
}

t_vec3d	mat_mult_vec3d(t_mat4 m, t_vec3d v)
{
	t_vec3d	res;

	res.x = m.m[0][0] * v.x + m.m[0][1] * v.x + m.m[0][2] * v.x + m.m[0][3] * 1;
	res.y = m.m[1][0] * v.y + m.m[1][1] * v.y + m.m[1][2] * v.y + m.m[1][3] * 1;
	res.z = m.m[2][0] * v.z + m.m[2][1] * v.z + m.m[2][2] * v.z + m.m[2][3] * 1;

	return (res);
}

t_mat4	quat_to_mat(t_quat q)
{
	t_mat4	res;
	t_mat4	m1;
	t_mat4	m2;

	q = quat_normalize(q);
	m1 = init_quat_m1(q);
	m2 = init_quat_m2(q);
	res = mat_mult(&m1, &m2);
	return (res);
}

