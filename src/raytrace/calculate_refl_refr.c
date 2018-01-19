/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_refl_refr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/09 15:25:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_copy_scene(t_rt *rt_orig, t_rt *rt_copy)
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
}
/*костиль копіювання*/
void		ft_copy(t_rt *rt_orig, t_rt *rt_copy)
{
	ft_copy_scene(rt_orig, rt_copy);
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
}

void	calculate_reflect_refract(t_rt *rt)
{
	t_rgbap	c_refl;
	t_rgbap	c_refr;
	
	c_refl.red = 0;
	c_refl.green = 0;
	c_refl.blue = 0;
	c_refr.red = 0;
	c_refr.green = 0;
	c_refr.blue = 0;
	if (rt->calc->level_reflection != rt->scene->max_level_reflection)
	{
		rt->calc->level_reflection++;
		calculate_reflection(rt, &c_refl);
	}
	if (rt->calc->level_transparent != rt->scene->max_level_transparent)
	{
		rt->calc->level_transparent++;
		calculate_refraction(rt, &c_refr);
	}
	rt->calc->color.red += c_refl.red + c_refr.red;
	rt->calc->color.green += c_refl.green + c_refr.green;
	rt->calc->color.blue += c_refl.blue + c_refr.blue;
}