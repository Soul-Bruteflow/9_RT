/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planar_mapping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:23:33 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:23:34 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	planar_mapping(t_rt *rt, int *x, int *y)
{
	float		u;
	float		v;
	t_vec3		u_axis;
	t_vec3		v_axis;
	t_obj3d		*obj;

	obj = rt->scene->objects[rt->calc->cur_obj];
	u_axis = (t_vec3) { obj->rot.y, obj->rot.z, -obj->rot.x};
	v_axis = vec3_cross(&u_axis, &obj->rot);
	u = vec3_dot(rt->scene->ray.pos, u_axis);
	v = vec3_dot(rt->scene->ray.pos, v_axis);
	u /= rt->calc->cur_mat.texture.scale.x;
	v /= rt->calc->cur_mat.texture.scale.y;
	u = u - floor(u);
	v = v - floor(v);
	*x = (int)((u * rt->calc->cur_mat.texture.map->w)
			+ rt->calc->cur_mat.texture.offset.x)
			% rt->calc->cur_mat.texture.map->w;
	*y = (int)((v * rt->calc->cur_mat.texture.map->h)
			+ rt->calc->cur_mat.texture.offset.y)
			% rt->calc->cur_mat.texture.map->h;
}
