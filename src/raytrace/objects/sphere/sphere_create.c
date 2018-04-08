/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:40:05 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere		*new_sphere(void)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(*(sphere)));
	if (sphere == NULL)
		rtv_error(malloc_error);
	return (sphere);
}

static void		set_sphere_radius(t_obj3d *obj, float rad)
{
	t_sphere *sphere;

	sphere = obj->type;
	sphere->radius = rad;
}

void			set_sphere(t_obj3d *obj, t_vec3 pos, float rad, Uint16 mat)
{
	set_object_position(obj, pos);
	set_object_material(obj, mat);
	set_sphere_radius(obj, rad);
}
