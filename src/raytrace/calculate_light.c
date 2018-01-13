/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:25:33 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_set_fong(t_rt *rt, t_light cur_light, float intensity)
{
	int 	coef_glow;
	float	fong;

	coef_glow = rt->calc->cur_mat.reflection * 100;
	fong = rt->calc->cur_mat.reflection * powf(intensity, coef_glow)
		* rt->calc->cur_power_ray;
	if (fong > 1.0f)
		fong = 1.0f;
	if (fong < 0.0f)
		fong = 0.0f;
	rt->calc->color.red += (rt->calc->cur_mat.diffuse.red
		* cur_light.color.red * cur_light.power * fong);
	rt->calc->color.green += (rt->calc->cur_mat.diffuse.green
		* cur_light.color.green * cur_light.power * fong);
	rt->calc->color.blue += (rt->calc->cur_mat.diffuse.blue
		* cur_light.color.blue * cur_light.power * fong);
}

static void	ft_fong(t_rt *rt, t_light cur_light, t_vec3 v_light, float shadow)
{
	t_vec3	v_position;
	float	intensity;

	v_position = vec3_sub(&rt->calc->old_start, &rt->calc->new_start);
	v_position = vec3_norm(v_position);
	intensity = 2.0f * vec3_dot(rt->calc->intersect_normal, v_light)
		* vec3_dot(rt->calc->intersect_normal, v_position)
		- vec3_dot(v_light, v_position);
	if (intensity >= 0.0f && shadow == 1.0f)
		ft_set_fong(rt, cur_light, intensity);
}

static void	ft_lambert(t_rt *rt, t_light cur_light, float shadow)
{
	t_vec3	v_light;
	float	lambert;

	v_light = vec3_sub(&cur_light.pos, &rt->calc->new_start);
	v_light = vec3_norm(v_light);
	lambert = vec3_dot(v_light, rt->calc->intersect_normal)
		* rt->calc->cur_power_ray * shadow;
	if (lambert > 1.0f)
		lambert = 1.0f;
	if (lambert < 0.0f)
		lambert = 0.0f;
	rt->calc->color.red += (rt->calc->cur_mat.diffuse.red
		* cur_light.color.red * cur_light.power * lambert);
	rt->calc->color.green += (rt->calc->cur_mat.diffuse.green
		* cur_light.color.green * cur_light.power * lambert);
	rt->calc->color.blue += (rt->calc->cur_mat.diffuse.blue
		* cur_light.color.blue * cur_light.power * lambert);

/*Glossy effect - add flag*/
	ft_fong(rt, cur_light, v_light, shadow);
}

static float	calculate_shadows(t_rt *rt, t_obj3d **objs, t_vec3 *v_dist,
	float *dist)
{
	t_ray	light_ray;
	int 	k;
	float	light_dist;

	light_dist = *dist;
	light_ray.pos = rt->calc->new_start;
	light_ray.dir = vec3_scale(1.0f / *dist, v_dist);
	k = -1;
	while (k++ < rt->scene->objs_n - 1)
	{
		if (objs[k]->intersect(&light_ray, objs[k], dist))
		{
			float result = (powf(*dist / light_dist, 0.1f)) / 2.0f;
			if (result >= 0.95f)
				result = powf(result, 0.75f);
			return(result);
		}
	}
	return (1.0f);
}

static void		no_light(t_rt *rt)
{
	t_vec3		v_dist;
	float		dist;

	v_dist = vec3_sub(&rt->calc->old_start, &rt->calc->new_start);
	dist = powf((1.0f - sqrtf(vec3_dot(v_dist, v_dist))
		/ (float)MAX_LEN), 16.0f);
	if (dist < 0.1f)
		dist = 0.1f;
	rt->calc->color.red = rt->calc->cur_mat.diffuse.red * dist;
	rt->calc->color.green = rt->calc->cur_mat.diffuse.green * dist;
	rt->calc->color.blue = rt->calc->cur_mat.diffuse.blue * dist;
}

void	calculate_light(t_rt *rt)
{
	t_light		cur_light;
	t_vec3		v_dist;
	float		dist;
	
	rt->calc->shadow = 0.0f;

	rt->calc->i = -1;
	if (rt->scene->lits_n == 0)
		no_light(rt);
	else
		while (rt->calc->i++ < rt->scene->lits_n - 1)
		{
			cur_light = *rt->scene->lights[rt->calc->i];
			v_dist = vec3_sub(&cur_light.pos, &rt->calc->new_start);
			dist = sqrtf(vec3_dot(v_dist, v_dist));
			if (dist <= 0.0f && vec3_dot(v_dist, rt->calc->intersect_normal) <= 0.0f)
				continue;
			rt->calc->shadow = calculate_shadows(rt, rt->scene->objects, &v_dist, &dist);
			ft_lambert(rt, cur_light, rt->calc->shadow);
	}
}