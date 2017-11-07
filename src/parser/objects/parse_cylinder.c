/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:15:39 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	alloc_new_cylinder(t_rt *r, int i)
{
	r->scene->objects[i] = new_object(cylinder);
	r->scene->objects[i]->type = new_cylinder();
	r->scene->objects[i]->intersect = intersect_cylinder_ray;
}

t_bool	parse_cylinder(t_rt *r, int i)
{
	t_vec3		ab[2];
	float		radius;
	Uint16		material;

	free(r->pars->line);
	alloc_new_cylinder(r, i);
	if (!(check_line(r, "point a:")))
		return (false);
	if (!(parse_vector(r, &ab[0], V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "point b:")))
		return (false);
	if (!(parse_vector(r, &ab[1], V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "radius:")))
		return (false);
	if (!(parse_number(r, &radius, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "material:")))
		return (false);
	if (!(valid_material(r, &material, M_MIN, M_MAX)))
		return (false);
	set_cylinder(r->scene->objects[i], ab, radius, material);
	return (true);
}
