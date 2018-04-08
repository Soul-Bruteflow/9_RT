/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:29:22 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:50:05 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			calculate_shadow(t_rt *rt, t_light cur_light, t_vec3 v_dist,
					float dist)
{
	t_rt	*rt_shadow;

	rt_shadow = ft_copy(rt);
	rt_shadow->calc->shadow.red = 1.0f;
	rt_shadow->calc->shadow.green = 1.0f;
	rt_shadow->calc->shadow.blue = 1.0f;
	if (rt->scene->status_shadow == true)
	{
		rt_shadow->calc->level_transparent = 0;
		rt_shadow->scene->ray.dir = vec3_scale(1.0f / dist, &v_dist);
		while (rt_shadow->calc->level_transparent <
				rt_shadow->scene->max_level_transparent + 1)
		{
			shadow(rt, rt_shadow, cur_light, rt->scene->objects);
			rt_shadow->calc->level_transparent++;
		}
	}
	rt->calc->shadow = rt_shadow->calc->shadow;
	ft_free(rt_shadow);
}
