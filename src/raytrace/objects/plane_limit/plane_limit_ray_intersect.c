/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_limit_ray_intersect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 18:20:18 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	intersect(t_ray *r, t_vec3 a, t_vec3 b, t_vec3 c)
{
	t_vec3	edge[2];
	t_vec3	vec[3];
	float	det;
	float	u;
	float	v;

	edge[0] = vec3_sub(&b, &a);
	edge[1] = vec3_sub(&c, &a);
	vec[0] = vec3_cross(&r->dir, &edge[1]);
	det = vec3_dot(edge[0], vec[0]);
	if (det < 1e-8 && det > -1e-8)
		return (0);
	vec[1] = vec3_sub(&r->pos, &a);
	u = vec3_dot(vec[1], vec[0]) * (1.0f / det);
	if (u < 0 || u > 1)
		return (0);
	vec[2] = vec3_cross(&vec[1], &edge[0]);
	v = vec3_dot(r->dir, vec[2]) * (1.0f / det);
	if (v < 0 || u + v > 1)
		return (0);
	return (vec3_dot(edge[1], vec[2]) * (1.0f / det));
}

static float	plane_limit_intersection(t_ray *r, t_plane_limit *p)
{
	float x;

	x = intersect(r, p->d1, p->d2, p->d3);
	if (x == 0)
		x = intersect(r, p->d4, p->d1, p->d3);
	return (x);
}

t_bool			intersect_plane_limit(t_ray *r, t_obj3d *obj, float *d)
{
	t_plane_limit	*plane;
	float			x;

	plane = obj->type;
	x = plane_limit_intersection(r, plane);
	if ((x > 0.5f) && (x < *d))
	{
		*d = x;
		return (true);
	}
	return (false);
}
