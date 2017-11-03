/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:38:30 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane	*new_plane(void)
{
	t_plane *plane;

	plane = malloc(sizeof(*(plane)));
	if (plane == NULL)
		rtv_error(malloc_error);
	return (plane);
}

void	set_plane_normal(t_obj3d *obj, t_vec3d new_normal)
{
	t_plane *tmp_plane;

	tmp_plane = obj->type;
	tmp_plane->normal.x = new_normal.x;
	tmp_plane->normal.y = new_normal.y;
	tmp_plane->normal.z = new_normal.z;
}

void	set_plane_point(t_obj3d *obj, t_vec3d new_point)
{
	t_plane *tmp_plane;

	tmp_plane = obj->type;
	tmp_plane->point.x = new_point.x;
	tmp_plane->point.y = new_point.y;
	tmp_plane->point.z = new_point.z;
}

void	set_plane(t_obj3d *obj, t_vec3d normal, t_vec3d point, Uint16 material)
{
	set_plane_normal(obj, normal);
	set_plane_point(obj, point);
	set_object_position(obj, normal);
	set_object_material(obj, material);
}
