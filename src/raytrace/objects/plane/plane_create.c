/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2018/03/31 19:20:10 by mvlad            ###   ########.fr       */
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

void	set_plane(t_obj3d *obj, t_vec3 pos, t_vec3 rot, Uint16 mat)
{
	set_object_position(obj, pos);
	set_object_rotation(obj, rot);
	set_object_material(obj, mat);
}
