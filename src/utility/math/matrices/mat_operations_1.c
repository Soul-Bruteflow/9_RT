/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_operations_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:14:25 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:14:26 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mat4	mat_mult(t_mat4 *m1, t_mat4 *m2)
{
	int		x;
	int		y;
	int		z;
	t_mat4	res;

	x = -1;
	while (x++ < 4)
	{
		y = -1;
		while (y++ < 4)
		{
			z = -1;
			res.m[x][y] = 0;
			while (z++ < 4)
				res.m[x][y] += m1->m[x][z] * m2->m[z][y];
		}
	}
	return (res);
}

t_vec3	mat_mult_vec3d(t_mat4 m, t_vec3 v)
{
	t_vec3	res;

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

	m1 = init_quat_m1(q);
	m2 = init_quat_m2(q);
	res = mat_mult(&m1, &m2);
	return (res);
}
