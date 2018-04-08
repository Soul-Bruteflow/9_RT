/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_mapping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:23:40 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:23:41 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sphere_mapping(t_rt *rt, int *x, int *y)
{
	float		u;
	float		v;

	u = 0.5f + atan2f(rt->calc->intersect_normal.z,
		rt->calc->intersect_normal.x) / (2 * PI);
	v = 0.5f - asinf(rt->calc->intersect_normal.y) / PI;
	u /= rt->calc->cur_mat.texture.scale.x;
	v /= rt->calc->cur_mat.texture.scale.y;
	*x = (int)((u * rt->calc->cur_mat.texture.map->w)
			+ rt->calc->cur_mat.texture.offset.x)
			% rt->calc->cur_mat.texture.map->w;
	*y = (int)((v * rt->calc->cur_mat.texture.map->h)
			+ rt->calc->cur_mat.texture.offset.y)
			% rt->calc->cur_mat.texture.map->h;
}
