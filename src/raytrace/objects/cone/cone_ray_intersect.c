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

/*
** Solving the discriminant
*/

static float	calculate_discriminant(t_ray *r, t_obj3d *o, float *b, float *a)
{
	t_cone *s;

	s = o->type;

	t_vec3 v_distance = vec3_sub(&r->start, &o->pos);
	s->axis = vec3_norm(s->axis);

	*a = vec3_dot(r->dir, r->dir) - (1.0f + powf(tanf(s->angle), 2.0f))
	* powf(vec3_dot(r->dir, s->axis), 2.0f);

	*b = 2.0f * (vec3_dot(r->dir, v_distance)
		- (1.0f + powf(tan(s->angle), 2.0f)) * vec3_dot(r->dir, s->axis)
		* vec3_dot(v_distance, s->axis));

	float c = vec3_dot(v_distance, v_distance)
	- (1.0f + powf(tan(s->angle), 2.0f))
	* pow(vec3_dot(v_distance, s->axis), 2.0f);

	return (*b * *b - 4 * *a * c);
}

/*
** Check if the ray and sphere intersect
*/

t_bool			intersect_cone_ray(t_ray *r, t_obj3d *object, float *t)
{
	float	b;
	float	a;
	float	discr;
	float	t0;
	float	t1;

	discr = calculate_discriminant(r, object, &b, &a);
	if (discr < 0)
		return (false);
	else
	{
		t0 = (-b + sqrtf(discr)) / (2.0f * a);
		t1 = (-b - sqrtf(discr)) / (2.0f * a);
		object->shadow = 0.0f;
		if (t0 > t1)
			t0 = t1;
		if ((t0 > 0.1f) && (t0 < *t))
		{
			*t = t0;
			return (true);
		}
		else
			return (false);
	}
}