/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_ray_intersect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:38:08 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Solving the discriminant
*/

static float	calculate_discriminant(t_ray *r, t_obj3d *o, float *b, float *a)
{
	float		c;
	t_cylinder	*cy;
	t_vec3		tmp[4];

	cy = o->type;
	tmp[0] = vec3_sub(&cy->b, &cy->a);
	tmp[1] = vec3_sub(&r->start, &cy->a);
	tmp[2] = vec3_cross(&tmp[1], &tmp[0]);
	tmp[3] = vec3_cross(&r->dir, &tmp[0]);
	*a = vec3_dot(&tmp[3], &tmp[3]);
	*b = 2 * vec3_dot(&tmp[3], &tmp[2]);
	c = vec3_dot(&tmp[2], &tmp[2]) - (cy->radius * cy->radius *
	(vec3_dot(&tmp[0], &tmp[0])));
	return (*b * *b - 4 * *a * c);
}

/*
** Check if the ray and sphere intersect
*/

t_bool			intersect_cylinder_ray(t_ray *r, t_obj3d *object, float *t)
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
		t0 = (-b + sqrtf(discr)) / (2 * a);
		t1 = (-b - sqrtf(discr)) / (2 * a);
		if (t0 > t1)
			t0 = t1;
		if ((t0 > 1e-1f) && (t0 < *t))
		{
			*t = t0;
			return (true);
		}
		else
			return (false);
	}
}
