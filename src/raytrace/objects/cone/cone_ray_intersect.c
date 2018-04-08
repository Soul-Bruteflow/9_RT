/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_ray_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:33:50 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	calculate_discriminant(t_ray *r, t_obj3d *obj,
					float *b, float *a)
{
	t_cone	*cone;
	t_vec3	dist;
	float	c;

	cone = obj->type;
	dist = vec3_sub(&r->pos, &obj->pos);
	obj->rot = vec3_norm(obj->rot);
	*a = vec3_dot(r->dir, r->dir) - (1.0f + powf(tanf(cone->angle), 2.0f))
		* powf(vec3_dot(r->dir, obj->rot), 2.0f);
	*b = 2.0f * (vec3_dot(r->dir, dist) - (1.0f + powf(tanf(cone->angle), 2.0f))
		* vec3_dot(r->dir, obj->rot) * vec3_dot(dist, obj->rot));
	c = vec3_dot(dist, dist) - (1.0f + powf(tanf(cone->angle), 2.0f))
		* powf(vec3_dot(dist, obj->rot), 2.0f);
	return (*b * *b - 4.0f * *a * c);
}

static void		calculate_parameters(float *data,
					float *x0, float *x1, float *d)
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
		if (fabsf(*d) > fabsf(*x1))
			*x0 = *x1;
	}
}

t_bool			intersect_cone(t_ray *r, t_obj3d *obj, float *d)
{
	float	x0;
	float	x1;
	float	data[3];

	data[0] = calculate_discriminant(r, obj, &data[2], &data[1]);
	if (data[0] < 0.0f || data[1] == 0.0f)
		return (false);
	else
	{
		calculate_parameters(data, &x0, &x1, d);
		if ((x0 > 0.5f) && (x0 < *d))
		{
			*d = x0;
			return (true);
		}
		else
			return (false);
	}
}
