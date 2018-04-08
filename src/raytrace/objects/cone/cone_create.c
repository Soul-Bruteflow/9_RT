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

t_cone		*new_cone(void)
{
	t_cone *cone;

	cone = malloc(sizeof(*(cone)));
	if (cone == NULL)
		rtv_error(malloc_error);
	return (cone);
}

static void	set_cone_angle(t_obj3d *obj, float angle)
{
	t_cone *cone;

	cone = obj->type;
	cone->angle = angle;
}

void		set_cone(t_obj3d *obj, t_vec3 *pr, float angle,
				Uint16 mat)
{
	set_object_position(obj, pr[0]);
	set_object_rotation(obj, pr[1]);
	set_object_material(obj, mat);
	set_cone_angle(obj, angle);
}
