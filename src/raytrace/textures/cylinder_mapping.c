/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_mapping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:23:24 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:23:26 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cylinder_mapping(t_rt *rt, int *x, int *y)
{
	float		u;
	float		v;
	t_obj3d		*obj;

	obj = rt->scene->objects[rt->calc->cur_obj];
	u = 0.5f + atan2f(rt->calc->intersect_normal.z,
			rt->calc->intersect_normal.x) / (2 * PI);
	v = 0.5f + rt->scene->ray.pos.y - obj->pos.y * obj->rot.y;
	u /= rt->calc->cur_mat.texture.scale.x;
	v /= rt->calc->cur_mat.texture.scale.y;
	v = v - floor(v);
	*x = (int)((u * rt->calc->cur_mat.texture.map->w)
			+ rt->calc->cur_mat.texture.offset.x)
			% rt->calc->cur_mat.texture.map->w;
	*y = (int)((v * rt->calc->cur_mat.texture.map->h)
			+ rt->calc->cur_mat.texture.offset.y)
			% rt->calc->cur_mat.texture.map->h;
}
