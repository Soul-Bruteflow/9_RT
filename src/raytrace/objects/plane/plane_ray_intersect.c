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
	float		t0;

	p = obj->type;
	t0 = ((vec3_dot(p->normal, p->point) - vec3_dot(p->normal, r->pos))
		/ vec3_dot(p->normal, r->dir));
	if ((t0 > 0.5f) && (t0 < *t))
	{
		*t = t0;
		return (true);
	}
	return (false);
}