/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_ray_intersect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:39:07 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool	intersect_plane_ray(t_ray *r, t_obj3d *obj, float *t)
{
	t_plane		*p;
	float		denom;
	float		t0;
	t_vec3		tmp;

	p = obj->type;
	denom = vec3_dot(r->dir, p->normal);
	if (fabs(denom) >= 1e-1f)
	{
		tmp = vec3_sub(&p->point, &r->start);
		t0 = vec3_dot(&tmp, &p->normal) / denom;
		if (t0 >= 1e-1f && t0 < *t)
		{
			*t = t0;
			return (true);
		}
	}
	return (false);
}