/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc_ray_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:36:50 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		normal_disc(t_ray *r, t_obj3d *obj, t_vec3 *n)
{
	if (vec3_dot(r->dir, obj->rot) > 0)
		*n = vec3_scale(-1, &obj->rot);
	else
		*n = obj->rot;
}
