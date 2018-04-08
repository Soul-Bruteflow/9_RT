/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid_ray_normal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 18:02:32 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		normal_paraboloid(t_ray *r, t_obj3d *obj, t_vec3 *n)
{
	t_paraboloid	*paraboloid;
	t_vec3			tmp[2];
	float			m;

	paraboloid = obj->type;
	tmp[0] = vec3_sub(&r->pos, &obj->pos);
	m = vec3_dot(tmp[0], obj->rot);
	tmp[1] = vec3_scale((m + paraboloid->a), &obj->rot);
	*n = vec3_sub(&tmp[0], &tmp[1]);
}
