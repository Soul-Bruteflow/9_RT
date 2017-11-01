#include "math/math.h"

t_mat4	mat_mult(t_mat4 *m1, t_mat4 *m2)
{
	int		i;
	int		j;
	t_mat4	res;

	i = -1;
	while (i++ < 4)
	{
		j = -1;
		while(j++ < 4)
		{
			res.m[i][j] =	m1->m[i][0] * m2->m[0][j] +
							m1->m[i][1] * m2->m[1][j] +
							m1->m[i][2] * m2->m[2][j] +
							m1->m[i][3] * m2->m[3][j];
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

