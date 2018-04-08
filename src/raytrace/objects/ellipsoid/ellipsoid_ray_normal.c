/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid_ray_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:54:39 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		calc_param(t_ray *r, t_obj3d *obj, t_vec3 *param)
{
	t_ellipsoid		*e;
	float			tmp[2];
	t_vec3			dist;

	e = obj->type;
	dist = vec3_sub(&r->pos, &obj->pos);
	tmp[0] = 2.0f * e->k * vec3_dot(r->dir, obj->rot);
	tmp[1] = e->rad * e->rad + 2.0f * e->k * vec3_dot(dist, obj->rot) - e->k;
	param->x = 4.0f * e->rad * e->rad * vec3_dot(r->dir, r->dir)
				- tmp[0] * tmp[0];
	param->y = 2.0f * (4.0f * e->rad * e->rad * vec3_dot(r->dir, dist)
				- tmp[0] * tmp[1]);
}

void		normal_ellipsoid(t_ray *r, t_obj3d *obj, t_vec3 *n)
{
	t_ellipsoid		*e;
	t_vec3			tmp[2];
	t_vec3			r1;
	t_vec3			q;
	t_vec3			p;

	e = obj->type;
	calc_param(r, obj, &p);
	tmp[0] = vec3_scale(e->k / 2.0f, &obj->rot);
	tmp[1] = vec3_add(&obj->pos, &tmp[0]);
	r1 = vec3_sub(&r->pos, &tmp[1]);
	q = vec3_scale((1.0f - ((p.x * p.x) / (p.y * p.y))), &obj->rot);
	q = vec3_scale(vec3_dot(r1, obj->rot), &q);
	*n = vec3_sub(&r1, &q);
}
