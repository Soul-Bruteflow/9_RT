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

t_bool	intersect_plane(t_ray *r, t_obj3d *obj, float *d)
{
	t_plane		*p;
	float		x;

	p = obj->type;
	x = ((vec3_dot(obj->rot, obj->pos) - vec3_dot(obj->rot, r->pos))
		/ vec3_dot(obj->rot, r->dir));
	if ((x > 0.5f) && (x < *d))
	{
		*d = x;
		return (true);
	}
	return (false);
}
