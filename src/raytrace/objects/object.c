/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:29:53 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_object_position(t_obj3d *obj, t_vec3d new_position)
{
	obj->pos.x = new_position.x;
	obj->pos.y = new_position.y;
	obj->pos.z = new_position.z;
}

void	set_object_material(t_obj3d *obj, Uint16 new_material)
{
	obj->material = new_material;
}
