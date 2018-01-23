/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <vholovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:39:16 by vholovin          #+#    #+#             */
/*   Updated: 2018/01/09 15:25:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_color(t_rt *rt_cur, t_light cur_light)
{
	rt_cur->calc->shadow.red *= cur_light.color.red *
		cur_light.power	* rt_cur->calc->cur_mat.diffuse.red;
	rt_cur->calc->shadow.green *= cur_light.color.green *
		cur_light.power	* rt_cur->calc->cur_mat.diffuse.green;
	rt_cur->calc->shadow.blue *= cur_light.color.blue *
		cur_light.power	* rt_cur->calc->cur_mat.diffuse.blue;
}

static void 	calculate(t_rt *rt_cur, double n1, double n2, float cos_angle,
					t_vec3 intersect_normal)
{
	float	k;
	t_vec3	tmp1;

	k = 1.0f - (n1 / n2) * (n1 / n2) * (1.0f - cos_angle * cos_angle);
	if (k > 0.0f)
	{
		rt_cur->scene->ray.dir = vec3_scale(n1 / n2, &rt_cur->scene->ray.dir);
		tmp1 = vec3_scale( n1 / n2 * cos_angle - sqrtf(k) , &intersect_normal);
		rt_cur->scene->ray.dir = vec3_add(&rt_cur->scene->ray.dir, &tmp1);
		rt_cur->calc->cur_power_ray *= rt_cur->calc->cur_mat.transparent * k;
	}
	else
		rt_cur->calc->cur_power_ray = 0.01f;
}

static void		set_coef_refraction(t_rt *rt_last, t_rt *rt_cur,
					double *n1, double *n2)
{
		*n1 = (rt_last->calc->last_status_refract == false
			&& rt_cur->calc->last_status_refract == false)
			? 1.00029f : rt_last->calc->cur_mat.refraction;
		*n2 = rt_cur->calc->cur_mat.refraction;
}

static void		rotate_dir_shadow(t_rt *rt_last, t_rt *rt_cur)
{
	double	n1;
	double	n2;
	t_vec3	intersect_normal;
	float	cos_angle;

	if (rt_cur->calc->cur_power_ray > 0.01f)
	{
		set_coef_refraction(rt_last, rt_cur, &n1, &n2);
		intersect_normal = rt_cur->calc->intersect_normal;
		cos_angle = vec3_dot(rt_cur->scene->ray.dir, intersect_normal);
		cos_angle = (cos_angle < -1.0f) ? -1.0f : cos_angle;
		cos_angle = (cos_angle > 1.0f) ? 1.0f : cos_angle;
		if (cos_angle < 0)
		{
			cos_angle = fabsf(cos_angle);
			rt_cur->calc->last_status_refract = true;			
		}
		else
		{
			intersect_normal = vec3_scale( -1.0f, &intersect_normal);
			ft_swap(&n1, &n2);
			rt_cur->calc->last_status_refract = false;
		}
		calculate(rt_cur, n1, n2, cos_angle, intersect_normal);
	}
}

static void		shadow(t_rt *rt_last, t_rt *rt_cur, t_light cur_light,
					t_obj3d **objs)
{
	t_vec3	scale;
	t_vec3	v_dist;
	float	dist;
	int 	cur_obj;

	v_dist = vec3_sub(&cur_light.pos, &rt_cur->scene->ray.pos);
	dist = sqrtf(vec3_dot(v_dist, v_dist));
	rt_cur->calc->cur_obj = -1;
	cur_obj = -1;
	while (cur_obj++ < rt_cur->scene->objs_n - 1)
	{
		if (objs[cur_obj]->
			intersect(&rt_cur->scene->ray, objs[cur_obj], &dist))
		rt_cur->calc->cur_obj = cur_obj;
	}
	if (rt_cur->calc->cur_obj != -1 &&
		normal_of_intersect(rt_cur, &rt_cur->calc->intersect_normal) == true)
	{
		rt_cur->calc->cur_mat = *rt_cur->scene->materials[objs[
			rt_cur->calc->cur_obj]->material];
		scale = vec3_scale(dist, &rt_cur->scene->ray.dir);
		rt_cur->scene->ray.pos = vec3_add(&rt_cur->scene->ray.pos, &scale);
		rotate_dir_shadow(rt_last, rt_cur);
		set_color(rt_cur, cur_light);
	}
}

void			calculate_shadow(t_rt *rt, t_light cur_light, t_vec3 v_dist,
					float dist)
{
	t_rt 	*rt_shadow;

	rt_shadow = ft_copy(rt);
	rt_shadow->calc->shadow.red = 1.0f;
	rt_shadow->calc->shadow.green = 1.0f;
	rt_shadow->calc->shadow.blue = 1.0f;
	if (rt->scene->status_shadow == true)
	{
		rt_shadow->calc->level_transparent = 0;
		rt_shadow->scene->ray.dir = vec3_scale(1.0f / dist, &v_dist);
		while(rt_shadow->calc->level_transparent <
				rt_shadow->scene->max_level_transparent + 1)
		{
			shadow(rt, rt_shadow, cur_light, rt->scene->objects);
			rt_shadow->calc->level_transparent++;
		}
	}
	rt->calc->shadow = rt_shadow->calc->shadow;
	ft_free(rt_shadow);
}