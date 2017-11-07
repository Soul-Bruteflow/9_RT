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
	t_cone	*s;
	float	c_cov[2];
	float	cov;
	float	tmp[3];
	t_vec3	co;

	s = o->type;
	c_cov[1] = vec3_dot(&r->dir, &s->axis);
	co = vec3_sub(&r->start, &o->pos);
	cov = vec3_dot(&co, &s->axis);
	tmp[0] = vec3_dot(&r->dir, &co);
	tmp[1] = powf(cosf(s->angle), 2);
	tmp[2] = vec3_dot(&co, &co);
	*a = powf(c_cov[1], 2) - tmp[1];
	*b = 2.0f * (c_cov[1] * cov - tmp[0] * tmp[1]);
	c_cov[0] = powf(cov, 2) - tmp[2] * tmp[1];
	return (powf(*b, 2) - (4 * *a * c_cov[0]));
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
		t0 = (-b + sqrtf(discr)) / (2 * a);
		t1 = (-b - sqrtf(discr)) / (2 * a);
		if (t0 > t1)
			t0 = t1;
		if ((t0 > 0.2) && (t0 < *t))
		{
			*t = t0;
			return (true);
		}
		else
			return (false);
	}
}
