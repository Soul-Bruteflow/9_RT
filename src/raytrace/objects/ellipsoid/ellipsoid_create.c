/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:39:50 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ellipsoid		*new_ellipsoid(void)
{
	t_ellipsoid *ellipsoid;

	ellipsoid = malloc(sizeof(*(ellipsoid)));
	if (ellipsoid == NULL)
		rtv_error(malloc_error);
	return (ellipsoid);
}

static void		set_ellipsoid_param(t_obj3d *obj, float k, float rad)
{
	t_ellipsoid *ellipsoid;

	ellipsoid = obj->type;
	ellipsoid->k = k;
	ellipsoid->rad = k + 2.0f * rad;
}

void			set_ellipsoid(t_obj3d *obj, t_vec3 *pr,
	float *krm, Uint16 mat)
{
	set_object_position(obj, pr[0]);
	set_object_rotation(obj, pr[1]);
	set_object_material(obj, mat);
	set_ellipsoid_param(obj, krm[0], krm[1]);
}
