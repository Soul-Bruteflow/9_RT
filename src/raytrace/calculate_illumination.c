/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_illumination.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <vholovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:39:16 by vholovin          #+#    #+#             */
/*   Updated: 2018/01/09 15:25:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		dirrect_light(t_rt *rt, t_light cur_light, t_vec3 v_dist,
					float dist)
{
	t_ray	ray;
	float	cos_angle;

	ray.pos = rt->scene->ray.pos;
	ray.dir = vec3_scale(1.0f / dist, &v_dist);
	ray.dir = vec3_scale(-1.0f, &ray.dir);
	cos_angle = vec3_dot(ray.dir, cur_light.dir);
	if (cos_angle < cos(cur_light.angle / 2 * 3.14 / 180)) 
	{
		rt->calc->light.red = 0.01f;
		rt->calc->light.green = 0.01f;
		rt->calc->light.blue = 0.01f;
	}
}

void			calculate_illumination(t_rt *rt, t_light cur_light,
					t_vec3 v_dist,	float dist)
{
	rt->calc->light.red = cur_light.color.red * cur_light.power;
	rt->calc->light.green = cur_light.color.green * cur_light.power;
	rt->calc->light.blue = cur_light.color.blue * cur_light.power;
	if (cur_light.type == 1)
		dirrect_light(rt, cur_light, v_dist, dist);
}