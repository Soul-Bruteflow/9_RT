/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_refraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:29:11 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:29:13 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		calculate(t_rt *rt_last, t_rt *rt_cur, double n,
					float cos_angle)
{
	float	k;
	t_vec3	tmp1;

	k = 1.0f - n * n * (1.0f - cos_angle * cos_angle);
	if (k > 0.0f)
	{
		rt_cur->scene->ray.dir = vec3_scale(n, &rt_cur->scene->ray.dir);
		tmp1 = vec3_scale(n * cos_angle - sqrtf(k),
			&rt_last->calc->intersect_normal);
		rt_cur->scene->ray.dir = vec3_add(&rt_cur->scene->ray.dir, &tmp1);
		rt_last->calc->last_status_refract = true;
		rt_cur->calc->cur_power_ray *= rt_cur->calc->cur_mat.transparent * k;
	}
	else
		rt_cur->calc->cur_power_ray = 0.01f;
}

static void		rotate_dir_refraction(t_rt *rt_last, t_rt *rt_cur)
{
	double	n1;
	double	n2;
	float	cos_angle;

	if (rt_cur->calc->cur_power_ray > 0.01f)
	{
		n1 = (rt_last->calc->last_status_refract == false)
			? 1.00029f : rt_last->calc->cur_mat.refraction;
		n2 = rt_cur->calc->cur_mat.refraction;
		cos_angle = vec3_dot(rt_cur->scene->ray.dir,
			rt_last->calc->intersect_normal);
		cos_angle = (cos_angle < -1.0f) ? -1.0f : cos_angle;
		cos_angle = (cos_angle > 1.0f) ? 1.0f : cos_angle;
		if (cos_angle < 0)
			cos_angle = fabsf(cos_angle);
		else
		{
			rt_last->calc->intersect_normal = vec3_scale(-1.0f,
				&rt_last->calc->intersect_normal);
			ft_swap(&n1, &n2);
		}
		calculate(rt_last, rt_cur, n1 / n2, cos_angle);
	}
}

void			calculate_refraction(t_rt *rt, t_rgbap *c_refr)
{
	float	kr;
	t_rt	*rt_refraction;

	rt_refraction = ft_copy(rt);
	calculate_frenel(rt, rt_refraction, &kr);
	if (kr < 1.0f)
	{
		rotate_dir_refraction(rt, rt_refraction);
		calculate_ray(rt_refraction);
		rt_refraction->calc->color.red *= rt->calc->cur_mat.diffuse.red
			* rt->calc->cur_mat.transparent;
		rt_refraction->calc->color.green *= rt->calc->cur_mat.diffuse.green
			* rt->calc->cur_mat.transparent;
		rt_refraction->calc->color.blue *= rt->calc->cur_mat.diffuse.blue
			* rt->calc->cur_mat.transparent;
		*c_refr = rt_refraction->calc->color;
	}
	ft_free(rt_refraction);
}
