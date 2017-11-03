/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:30:58 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cone	*new_cone(void)
{
	t_cone *cone;

	cone = malloc(sizeof(*(cone)));
	if (cone == NULL)
		rtv_error(malloc_error);
	return (cone);
}

void	set_cone_axis(t_obj3d *obj, t_vec3d new_axis)
{
	t_cone *tmp_cone;

	tmp_cone = obj->type;
	new_axis = vec3_norm(new_axis);
	tmp_cone->axis.x = new_axis.x;
	tmp_cone->axis.y = new_axis.y;
	tmp_cone->axis.z = new_axis.z;
}

void	set_cone_angle(t_obj3d *obj, float new_angle)
{
	t_cone *tmp_cone;

	tmp_cone = obj->type;
	tmp_cone->angle = new_angle;
}

void	set_cone(t_obj3d *obj, t_vec3d *data, float angle, Uint16 new_material)
{
	set_object_position(obj, data[0]);
	set_object_material(obj, new_material);
	set_cone_angle(obj, angle);
	set_cone_axis(obj, data[1]);
}
