/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:16:35 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	alloc_new_plane(t_rt *r, int i)
{
	r->scene->objects[i] = new_object(plane);
	r->scene->objects[i]->type = new_plane();
	r->scene->objects[i]->intersect = intersect_plane_ray;
}

t_bool	parse_plane(t_rt *r, int i)
{
	t_vec3		normal;
	t_vec3		point;
	Uint16		material;

	free(r->pars->line);
	alloc_new_plane(r, i);
	if (!(check_line(r, "normal:")))
		return (false);
	if (!(parse_vector(r, &normal, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "point:")))
		return (false);
	if (!(parse_vector(r, &point, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "material:")))
		return (false);
	if (!(valid_material(r, &material, M_MIN, M_MAX)))
		return (false);
	set_plane(r->scene->objects[i], normal, point, material);
	return (true);
}
