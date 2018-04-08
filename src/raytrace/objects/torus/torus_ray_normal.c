/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_ray_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 18:20:44 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		normal_torus(t_ray *r, t_obj3d *obj, t_vec3 *n)
{
	t_vec3		tmp0;
	t_vec3		tmp1;
	t_vec3		tmp2;
	t_torus		*torus;

	torus = obj->type;
	tmp0 = vec3_sub(&r->pos, &obj->pos);
	tmp1 = vec3_scale(vec3_dot(tmp0, obj->rot), &obj->rot);
	tmp1 = vec3_sub(&tmp0, &tmp1);
	tmp2 = vec3_scale(torus->r1 / sqrt(vec3_dot(tmp1, tmp1)),
		&tmp1);
	*n = (vec3_sub(&tmp0, &tmp2));
}
