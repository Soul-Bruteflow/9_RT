/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_ray_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:18:08 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		normal_cone(t_ray *r, t_obj3d *obj, t_vec3 *n)
{
	t_cone	*c;
	t_vec3	tmp0;
	t_vec3	tmp1;

	c = obj->type;
	obj->rot = vec3_norm(obj->rot);
	tmp0 = vec3_sub(&r->pos, &obj->pos);
	tmp1 = vec3_scale((vec3_dot(r->dir, obj->rot)
			+ vec3_dot(tmp0, obj->rot)), &obj->rot);
	tmp1 = vec3_scale((1.0f + powf(tanf(c->angle), 2.0f)), &tmp1);
	*n = vec3_sub(&tmp0, &tmp1);
}
