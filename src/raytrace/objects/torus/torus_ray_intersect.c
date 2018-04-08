/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_ray_intersect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 18:20:39 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static	float	select_root(t_pol *res)
{
	int		i;
	int		k;
	float	t[4];
	float	real_distanse;

	i = -1;
	k = 0;
	real_distanse = -1.0f;
	while (++i < res->deg)
		if ((res->x_im[i] == 0.0f) && (res->x_re[i] > 0.0f))
		{
			t[k] = res->x_re[i];
			k++;
		}
	if (k > 0)
	{
		real_distanse = t[0];
		i = -1;
		while (++i < k)
			if (fabsf(real_distanse) > fabsf(t[i]))
				real_distanse = t[i];
	}
	return (real_distanse);
}

static t_pol	calculate_polinome(t_vec3 dir, t_vec3 dist, t_obj3d *obj)
{
	t_torus		*tor;
	float		a;
	float		b;
	float		c;
	float		d;

	tor = obj->type;
	a = 1 - (vec3_dot(obj->rot, dir) * vec3_dot(obj->rot, dir));
	b = 2 * (vec3_dot(dist, dir) - vec3_dot(obj->rot, dist)
		* vec3_dot(obj->rot, dir));
	c = vec3_dot(dist, dist) - (vec3_dot(obj->rot, dist)
		* vec3_dot(obj->rot, dist));
	d = vec3_dot(dist, dist) + (tor->r1 * tor->r1) - (tor->r * tor->r);
	return (polinom_4_degr(4 * vec3_dot(dist, dir),
		2 * d + 1 / 4.0 * ((4 * vec3_dot(dist, dir))
		* (4 * vec3_dot(dist, dir))) - 4 * (tor->r1 * tor->r1) * a,
		4 * vec3_dot(dist, dir) * d - 4 * (tor->r1 * tor->r1) * b,
		d * d - 4 * (tor->r1 * tor->r1) * c));
}

t_bool			intersect_torus(t_ray *r, t_obj3d *obj, float *d)
{
	float		x;
	t_vec3		dir;
	t_vec3		dist;
	t_pol		res;

	x = -1.0f;
	dist = vec3_sub(&r->pos, &obj->pos);
	dir = vec3_norm(r->dir);
	res = calculate_polinome(dir, dist, obj);
	x = select_root(&res);
	if ((x > 0.5f) && (x < *d))
	{
		*d = x;
		return (true);
	}
	else
		return (false);
}
