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


static void		calculate_reflection(t_rt *rt)
{
	t_vec3	tmp1;

	if (rt->calc->cur_power_ray > 0.01f)
	{
		tmp1 = vec3_scale(-2.0f * vec3_dot(rt->scene->ray.dir,
			rt->calc->intersect_normal), &rt->calc->intersect_normal);
		rt->scene->ray.dir = vec3_add(&rt->scene->ray.dir, &tmp1);
		rt->scene->ray.dir = vec3_norm(rt->scene->ray.dir);

		rt->calc->last_status_refract = false;
	}
	rt->calc->cur_power_ray *= rt->calc->cur_mat.reflection;
}

static void		calculate_refraction(t_rt *rt_last, t_rt *rt)
{
	t_vec3	intersect_normal;
	float	cos_angle;
	float	n1;
	float	n2;
	float	k;
	t_vec3	tmp1;

	k = 1.0f;

	if (rt->calc->cur_power_ray > 0.01f)
	{	

		(void)rt_last;
		n1 = rt_last->calc->cur_mat.refraction;
		if (rt_last->calc->last_status_refract == false)
			n1 = 1.0f;

		n2 = rt->calc->cur_mat.refraction;
 		intersect_normal = rt->calc->intersect_normal;
		cos_angle = vec3_dot(rt->scene->ray.dir, intersect_normal);
		if (cos_angle < -1.0f)
 			cos_angle = -1.0f;
 		else if (cos_angle > 1.0f)
 		cos_angle = 1.0f;

 		if (cos_angle < 0)
 			cos_angle = fabsf(cos_angle);
		else
 		{
 			intersect_normal = vec3_scale( -1.0f, &intersect_normal);
			float swap = n1;
			n1 = n2;
			n2 = swap;
		}
		k = 1.0f - (n1 / n2) * (n1 / n2) * (1.0f - cos_angle * cos_angle);
		if (k > 0.0f)
		{
    		rt->scene->ray.dir = vec3_scale(n1 / n2, &rt->scene->ray.dir);
			tmp1 = vec3_scale( n1 / n2 * cos_angle - sqrtf(k) , &intersect_normal);
			rt->scene->ray.dir = vec3_add(&rt->scene->ray.dir, &tmp1);

			rt->calc->last_status_refract = true;
		}
		else
		{
			rt->calc->cur_power_ray = 0.01f;
			rt->calc->last_status_refract = false;
		}
	}
//	rt->calc->cur_power_ray *= rt->calc->cur_mat.transparent * k;
	rt->calc->cur_power_ray *= rt->calc->cur_mat.transparent;
}

static void		calculate_frenel(t_rt *rt, float *kr, float *kt)
{
	float	cos_angle_1;

	float n1 = 1.0f;
	float n2 = rt->calc->cur_mat.refraction;

	cos_angle_1 = vec3_dot(rt->scene->ray.dir, rt->calc->intersect_normal);
	if (cos_angle_1 < -1.0f)
		cos_angle_1 = -1.0f;
	else if (cos_angle_1 > 1.0f)
		cos_angle_1 = 1.0f;
	if (cos_angle_1 > 0)
	{
		float swap = n1;
		n1 = n2;
		n2 = swap;
	}

	float sin_angle_2 = 1.0f - cos_angle_1 * cos_angle_1;
	if (sin_angle_2 < 0.0f)
		sin_angle_2 = 0.0f;
	sin_angle_2 = n1 / n2 * sqrtf(sin_angle_2);

	if (sin_angle_2 >= 1.0f)
		*kr = 1.0f;
	else
	{
		float cos_angle_2 = 1.0f - sin_angle_2 * sin_angle_2;
		if (cos_angle_2 < 0.0f)
			cos_angle_2 = 0.0f;
		cos_angle_2 = sqrtf(cos_angle_2);

		cos_angle_1 = fabsf(cos_angle_1);
		
		float Rs = ((n2 * cos_angle_1) - (n1 * cos_angle_2))
			/ ((n2 * cos_angle_1) + (n1 * cos_angle_2));
		float Rp = ((n1 * cos_angle_1) - (n2 * cos_angle_2))
			/ ((n1 * cos_angle_1) + (n2 * cos_angle_2));
		
		*kr = (Rs * Rs + Rp * Rp) / 2;
	}
	*kt = 1.0f - *kr;
}

/*костиль копіювання*/
static void		ft_copy(t_rt *rt_orig, t_rt *rt_copy)
{

	rt_copy->scene->objects = rt_orig->scene->objects;
	rt_copy->scene->materials = rt_orig->scene->materials;
	rt_copy->scene->lights = rt_orig->scene->lights;
	rt_copy->scene->ray = rt_orig->scene->ray;
	rt_copy->scene->cam = rt_orig->scene->cam;
	rt_copy->scene->objs_n = rt_orig->scene->objs_n;
	rt_copy->scene->mats_n = rt_orig->scene->mats_n;
	rt_copy->scene->lits_n = rt_orig->scene->lits_n;

	rt_copy->calc->color = rt_orig->calc->color;
	rt_copy->calc->pixel_color = rt_orig->calc->pixel_color;
	rt_copy->calc->cur_obj = rt_orig->calc->cur_obj;
	rt_copy->calc->intersect_normal = rt_orig->calc->intersect_normal;
	rt_copy->calc->old_start = rt_orig->calc->old_start;
	rt_copy->calc->new_start = rt_orig->calc->new_start;
	rt_copy->calc->cur_mat = rt_orig->calc->cur_mat;
	rt_copy->calc->material_n = rt_orig->calc->material_n;
	rt_copy->calc->cur_power_ray = rt_orig->calc->cur_power_ray;
	rt_copy->calc->level_reflection = rt_orig->calc->level_reflection;
	rt_copy->calc->max_level_reflection = rt_orig->calc->max_level_reflection;
	rt_copy->calc->level_transparent = rt_orig->calc->level_transparent;
	rt_copy->calc->max_level_transparent = rt_orig->calc->max_level_transparent;
	rt_copy->calc->shadow = rt_orig->calc->shadow;
	rt_copy->calc->last_status_refract = rt_orig->calc->last_status_refract;
	rt_copy->calc->i = rt_orig->calc->i;
	rt_copy->calc->n = rt_orig->calc->n;
}


void	calculate_reflect_refract(t_rt *rt)
{
	float	kr;
	float	kt;
	
	calculate_frenel(rt, &kr, &kt);

	if (rt->calc->level_reflection
			!= rt->calc->max_level_reflection)
	{
		rt->calc->level_reflection++;

		t_rt	*rt_reflection;
		rt_reflection = rt_init(rt->av);
		ft_copy(rt, rt_reflection);

		calculate_reflection(rt_reflection);

		calculate_ray(rt_reflection);
		
		rt_reflection->calc->color.red *= rt->calc->cur_mat.reflection;
		rt_reflection->calc->color.green *= rt->calc->cur_mat.reflection;
		rt_reflection->calc->color.blue *= rt->calc->cur_mat.reflection;

		rt->calc->color.red += rt_reflection->calc->color.red;
		rt->calc->color.green += rt_reflection->calc->color.green;
		rt->calc->color.blue += rt_reflection->calc->color.blue;

		free(rt_reflection);
	}

/* complete internal reflection - to flag */
//	if (rt->calc->level_transparent != rt->calc->max_level_transparent)
	if (rt->calc->level_transparent != rt->calc->max_level_transparent && kr < 1.0f)
	{
		rt->calc->level_transparent++;

		t_rt	*rt_refraction;
		rt_refraction = rt_init(rt->av);
		ft_copy(rt, rt_refraction);

		calculate_refraction(rt, rt_refraction);

		calculate_ray(rt_refraction);

/*photo filtr - flag*/
		rt_refraction->calc->color.red *= rt->calc->cur_mat.diffuse.red
			* rt->calc->cur_mat.transparent;
		rt_refraction->calc->color.green *= rt->calc->cur_mat.diffuse.green
			* rt->calc->cur_mat.transparent;
		rt_refraction->calc->color.blue *= rt->calc->cur_mat.diffuse.blue
			* rt->calc->cur_mat.transparent;

/*No Frenel - flag*/
//	 	rt->calc->color.red += rt_refraction->calc->color.red;
//	 	rt->calc->color.green += rt_refraction->calc->color.green;
//	 	rt->calc->color.blue += rt_refraction->calc->color.blue;


/*Frenel - flag*/
	 	rt->calc->color.red += rt_refraction->calc->color.red * kt;
	 	rt->calc->color.green += rt_refraction->calc->color.green * kt;
	 	rt->calc->color.blue += rt_refraction->calc->color.blue * kt;

		free(rt_refraction);
	}
}