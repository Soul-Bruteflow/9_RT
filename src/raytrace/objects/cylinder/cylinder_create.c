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

t_cylinder	*new_cylinder(void)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(*(cylinder)));
	if (cylinder == NULL)
		rtv_error(malloc_error);
	return (cylinder);
}

void		set_cylinder_radius(t_obj3d *obj, float new_radius)
{
	t_cylinder *tmp_cylinder;

	tmp_cylinder = obj->type;
	tmp_cylinder->radius = new_radius;
}

void		set_cylinder_a(t_obj3d *obj, t_vec3 a)
{
	t_cylinder *tmp_cylinder;

	tmp_cylinder = obj->type;
	tmp_cylinder->a.x = a.x;
	tmp_cylinder->a.y = a.y;
	tmp_cylinder->a.z = a.z;
}

void		set_cylinder_b(t_obj3d *obj, t_vec3 b)
{
	t_cylinder *tmp_cylinder;

	tmp_cylinder = obj->type;
	tmp_cylinder->b.x = b.x;
	tmp_cylinder->b.y = b.y;
	tmp_cylinder->b.z = b.z;
}

void		set_cylinder(t_obj3d *o, t_vec3 *ab, float new_rad, Uint16 new_mat)
{
	set_object_position(o, ab[1]);
	set_cylinder_a(o, ab[0]);
	set_cylinder_b(o, ab[1]);
	set_object_material(o, new_mat);
	set_cylinder_radius(o, new_rad);
}
