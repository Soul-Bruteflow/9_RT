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

/*
** Solving the discriminant
*/

static float	calculate_discriminant(t_ray *r, t_obj3d *object, float *a, float *b, float *diametr)
{
	float		c;
	t_vec3		dist;
	t_sphere	*s;

	s = object->type;
	*diametr = 2 * s->radius;
	*a = vec3_dot(r->dir, r->dir);
	dist = vec3_sub(&r->start, &object->pos);
	*b = 2 * vec3_dot(r->dir, dist);
	c = vec3_dot(dist, dist) - (s->radius * s->radius);
	return (*b * *b - 4 * *a * c);
}

/*
** Check if the ray and sphere intersect
*/

t_bool			intersect_sphere_ray(t_ray *r, t_obj3d *object, float *t)
{
	float		a;
	float		b;
	float		t0;
	float		t1;
	float		discr;
	float		diametr;

	discr = calculate_discriminant(r, object, &a, &b, &diametr);
	if (discr < 0)
		return (false);
	else
	{
		t0 = (-b + sqrtf(discr)) / (2 * a);
		t1 = (-b - sqrtf(discr)) / (2 * a);
		object->shadow = 1.0f - powf(fabs( fabs(t0) - fabs(t1) ) / diametr, 10.0f);
		if (t0 > t1)
			t0 = t1;
		if ((t0 > 0.001f) && (t0 < *t))
		{
			*t = t0;
			return (true);
		}
		else
			return (false);
	}
}