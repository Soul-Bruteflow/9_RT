/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_ray_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:41:43 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	calculate_discriminant(t_ray *r, t_obj3d *obj,
					float *a, float *b)
{
	t_sphere	*s;
	t_vec3		dist;
	float		c;

	s = obj->type;
	dist = vec3_sub(&r->pos, &obj->pos);
	*a = vec3_dot(r->dir, r->dir);
	*b = 2.0f * vec3_dot(r->dir, dist);
	c = vec3_dot(dist, dist) - powf(s->radius, 2.0f);
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

t_bool			intersect_sphere(t_ray *r, t_obj3d *obj, float *d)
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
