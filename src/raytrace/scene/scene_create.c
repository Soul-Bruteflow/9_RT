/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:45:05 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Allocates memory for new scene. And all objects,
** lights and materials defined bu arguments.
*/

t_bool	new_lights(t_rtv *r)
{
	int		i;

	i = 0;
	while (i < r->scene->lits_n)
	{
		r->scene->lights[i] = new_light();
		i++;
	}
	return (true);
}

t_bool	new_materials(t_rtv *r)
{
	int		i;

	i = 0;
	while (i < r->scene->mats_n)
	{
		r->scene->materials[i] = new_material();
		i++;
	}
	return (true);
}

void	new_scene(t_rtv *r, int n_of_lights, int n_of_mats, int n_of_objs)
{
	r->scene->objects = malloc(n_of_objs * sizeof(r->scene->objects));
	if (r->scene->objects == NULL)
		rtv_error(malloc_error);
	r->scene->materials = malloc(n_of_mats * sizeof(r->scene->materials));
	if (r->scene->materials == NULL)
		rtv_error(malloc_error);
	r->scene->lights = malloc(n_of_lights * sizeof(r->scene->lights));
	if (r->scene->lights == NULL)
		rtv_error(malloc_error);
}

t_bool	create_scene(t_rtv *r)
{
	new_scene(r, r->scene->lits_n, r->scene->mats_n, r->scene->objs_n);
	if (!(new_lights(r)))
		return (false);
	if (!(new_materials(r)))
		return (false);
	return (true);
}

t_obj3d	*new_object(t_obj_type object_type)
{
	t_obj3d *new_obj;

	new_obj = malloc(sizeof(*(new_obj)));
	if (new_obj == NULL)
		rtv_error(malloc_error);
	new_obj->obj_type = object_type;
	return (new_obj);
}
