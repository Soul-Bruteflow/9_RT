/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid_ray_intersect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:57:37 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	calculate_discriminant(t_ray *r, t_obj3d *obj, float *a,
				float *b)
{
	t_ellipsoid		*e;
	t_vec3			dist;
	float			c;
	float			tmp[2];

	e = obj->type;
	dist = vec3_sub(&r->pos, &obj->pos);
	tmp[0] = 2.0f * e->k * vec3_dot(r->dir, obj->rot);
	tmp[1] = e->rad * e->rad + 2.0f * e->k * vec3_dot(dist, obj->rot) - e->k;
	*a = 4.0f * e->rad * e->rad * vec3_dot(r->dir, r->dir) - tmp[0] * tmp[0];
	*b = 2.0f * (4.0f * e->rad * e->rad * vec3_dot(r->dir, dist) - tmp[0]
				* tmp[1]);
	c = 4.0f * e->rad * e->rad * vec3_dot(dist, dist) - tmp[1] * tmp[1];
	return (*b * *b - 4.0f * *a * c);
}

static void		calculate_parameters(float *data,
					float *x0, float *x1)
{
	float discr;
	float a;
	float b;

	discr = data[0];
	a = data[1];
	b = data[2];
	if (discr == 0.0f)
	{
		*x0 = -0.5f * b / a;
		*x1 = *x0;
	}
	else if (discr > 0.0f)
	{
		*x0 = (-b + sqrtf(discr)) / (2.0f * a);
		*x1 = (-b - sqrtf(discr)) / (2.0f * a);
		if (fabsf(*x0) > fabsf(*x1))
			*x0 = *x1;
	}
}

t_bool			intersect_ellipsoid(t_ray *r, t_obj3d *obj, float *d)
{
	float	x0;
	float	x1;
	float	data[3];

	data[0] = calculate_discriminant(r, obj, &data[1], &data[2]);
	if (data[0] < 0.0f || data[1] == 0.0f)
		return (false);
	else
	{
		calculate_parameters(data, &x0, &x1);
		if ((x0 > 0.5f) && (x0 < *d))
		{
			*d = x0;
			return (true);
		}
		else
			return (false);
	}
}
