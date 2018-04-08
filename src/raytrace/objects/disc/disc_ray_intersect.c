/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc_ray_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:37:32 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:37:38 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			intersect_disc(t_ray *r, t_obj3d *obj, float *d)
{
	t_disc		*disc;
	float		x;
	t_vec3		new_pos;
	t_vec3		zone;
	float		diameter;

	disc = obj->type;
	x = ((vec3_dot(obj->rot, obj->pos) - vec3_dot(obj->rot, r->pos))
		/ vec3_dot(obj->rot, r->dir));
	if ((x > 0.5f) && (x < *d))
	{
		new_pos = vec3_scale(x, &r->dir);
		new_pos = vec3_add(&r->pos, &new_pos);
		zone = vec3_sub(&new_pos, &obj->pos);
		diameter = vec3_dot(zone, zone);
		if (sqrtf(diameter) <= disc->r1 && sqrtf(diameter) >= disc->r)
		{
			*d = x;
			return (true);
		}
	}
	return (false);
}
