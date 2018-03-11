/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <vholovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:39:16 by vholovin          #+#    #+#             */
/*   Updated: 2018/10/09 15:25:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_copy_calc(t_rt *rt_orig, t_rt *rt_copy)
{
	rt_copy->calc->color = rt_orig->calc->color;
	rt_copy->calc->sum_color = rt_orig->calc->sum_color;
	rt_copy->calc->pixel_color = rt_orig->calc->pixel_color;
	rt_copy->calc->cur_obj = rt_orig->calc->cur_obj;
	rt_copy->calc->intersect_normal = rt_orig->calc->intersect_normal;
	rt_copy->calc->old_start = rt_orig->calc->old_start;
	rt_copy->calc->new_start = rt_orig->calc->new_start;
	rt_copy->calc->cur_mat = rt_orig->calc->cur_mat;
	rt_copy->calc->material_n = rt_orig->calc->material_n;
	rt_copy->calc->cur_power_ray = rt_orig->calc->cur_power_ray;
	rt_copy->calc->level_reflection = rt_orig->calc->level_reflection;
	rt_copy->calc->level_transparent = rt_orig->calc->level_transparent;
	rt_copy->calc->shadow = rt_orig->calc->shadow;
	rt_copy->calc->last_status_refract = rt_orig->calc->last_status_refract;
	rt_copy->calc->i = rt_orig->calc->i;
	rt_copy->calc->n = rt_orig->calc->n;
	rt_copy->tmp_surface = rt_orig->tmp_surface;
}

static void		ft_copy_scene(t_rt *rt_orig, t_rt *rt_copy)
{
	rt_copy->scene->objects = rt_orig->scene->objects;
	rt_copy->scene->materials = rt_orig->scene->materials;
	rt_copy->scene->lights = rt_orig->scene->lights;
	rt_copy->scene->ray = rt_orig->scene->ray;
	rt_copy->scene->cam = rt_orig->scene->cam;
	rt_copy->scene->objs_n = rt_orig->scene->objs_n;
	rt_copy->scene->mats_n = rt_orig->scene->mats_n;
	rt_copy->scene->lits_n = rt_orig->scene->lits_n;
	rt_copy->scene->aa = rt_orig->scene->aa;
	rt_copy->scene->max_level_reflection = rt_orig->scene->max_level_reflection;
	rt_copy->scene->max_level_transparent = rt_orig->scene->max_level_transparent;
	rt_copy->scene->status_shadow = rt_orig->scene->status_shadow;
	rt_copy->scene->status_glossy = rt_orig->scene->status_glossy;
	rt_copy->scene->status_color = rt_orig->scene->status_color;
}

t_rt			*ft_copy(t_rt *rt_orig)
{
	t_rt *rt_copy;

	rt_copy = malloc(sizeof(*(rt_copy)));
	if (rt_copy == NULL)
		rtv_error(malloc_error);
	rt_copy->calc = malloc(sizeof(*(rt_copy->calc)));
	if (rt_copy->calc == NULL)
		rtv_error(malloc_error);
	rt_copy->scene = malloc(sizeof(*(rt_copy->scene)));
	if (rt_copy->scene == NULL)
		rtv_error(malloc_error);
	ft_copy_scene(rt_orig, rt_copy);
	ft_copy_calc(rt_orig, rt_copy);
	return(rt_copy);
}

void			ft_free(t_rt *rt_free)
{
	free(rt_free->scene);
	free(rt_free->calc);
	free(rt_free);
}