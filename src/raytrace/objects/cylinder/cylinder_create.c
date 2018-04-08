/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:35:43 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cylinder		*new_cylinder(void)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(*(cylinder)));
	if (cylinder == NULL)
		rtv_error(malloc_error);
	return (cylinder);
}

static void		set_cylinder_radius(t_obj3d *obj, float rad)
{
	t_sphere *cylinder;

	cylinder = obj->type;
	cylinder->radius = rad;
}

void			set_cylinder(t_obj3d *obj, t_vec3 *pr, float rad,
				Uint16 mat)
{
	set_object_position(obj, pr[0]);
	set_object_rotation(obj, pr[1]);
	set_object_material(obj, mat);
	set_cylinder_radius(obj, rad);
}
