/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:14:29 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	alloc_new_cone(t_rtv *r, int i)
{
	r->scene->objects[i] = new_object(cone);
	r->scene->objects[i]->type = new_cone();
	r->scene->objects[i]->intersect = intersect_cone_ray;
}

t_bool	parse_cone(t_rtv *r, int i)
{
	t_vec3d		data[2];
	float		angle;
	Uint16		material;

	free(r->pars->line);
	alloc_new_cone(r, i);
	if (!(check_line(r, "tip/position:")))
		return (false);
	if (!(parse_vector(r, &data[0], V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "axis:")))
		return (false);
	if (!(parse_vector(r, &data[1], V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "angle:")))
		return (false);
	if (!(parse_number(r, &angle, A_MIN, A_MAX)))
		return (false);
	if (!(check_line(r, "material:")))
		return (false);
	if (!(valid_material(r, &material, M_MIN, M_MAX)))
		return (false);
	set_cone(r->scene->objects[i], data, angle, material);
	return (true);
}
