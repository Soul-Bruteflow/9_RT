/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_ray_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:21:38 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		normal_cylinder(t_ray *r, t_obj3d *obj, t_vec3 *n)
{
	t_vec3	tmp0;
	t_vec3	tmp1;

	obj->rot = vec3_norm(obj->rot);
	tmp0 = vec3_sub(&r->pos, &obj->pos);
	tmp1 = vec3_scale(vec3_dot(r->dir, obj->rot)
		+ vec3_dot(tmp0, obj->rot), &obj->rot);
	*n = vec3_sub(&tmp0, &tmp1);
}
