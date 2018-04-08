/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:29:35 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:29:36 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		normal_of_intersect(t_rt *rt, t_vec3 *n)
{
	rt->scene->objects[rt->calc->cur_obj]->
			normal(&rt->scene->ray, rt->scene->objects[rt->calc->cur_obj], n);
	*n = vec3_norm(*n);
}

t_bool		object_intersect(t_rt *rt)
{
	float		t;
	int			i;
	t_vec3		scaled;

	t = MAX_LEN;
	i = -1;
	while (i++ < rt->scene->objs_n - 1)
	{
		if (rt->scene->objects[i]->
			intersect(&rt->scene->ray, rt->scene->objects[i], &t))
			rt->calc->cur_obj = i;
	}
	if (rt->calc->cur_obj == -1)
		return (false);
	rt->calc->old_start = rt->scene->ray.pos;
	scaled = vec3_scale(t, &rt->scene->ray.dir);
	rt->calc->new_start = vec3_add(&rt->scene->ray.pos, &scaled);
	rt->scene->ray.pos = rt->calc->new_start;
	normal_of_intersect(rt, &rt->calc->intersect_normal);
	return (true);
}
