/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/09 15:25:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		rotate_dir_reflection(t_rt *rt)
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

void			calculate_reflection(t_rt *rt, t_rgbap *c_refl)
{
	t_rt	*rt_reflection;

	rt_reflection = rt_init(rt->av);
	ft_copy(rt, rt_reflection);
	rotate_dir_reflection(rt_reflection);
	calculate_ray(rt_reflection);
	rt_reflection->calc->color.red *= rt->calc->cur_mat.reflection;
	rt_reflection->calc->color.green *= rt->calc->cur_mat.reflection;
	rt_reflection->calc->color.blue *= rt->calc->cur_mat.reflection;
	*c_refl = rt_reflection->calc->color;
	free(rt_reflection);
}