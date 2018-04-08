/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ambient_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:28:18 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:28:19 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_rgbap	max_lim(t_rgbap color, float lim)
{
	float max;

	max = color.red;
	max = (color.green > max) ? color.green : max;
	max = (color.blue > max) ? color.blue : max;
	max = max - lim;
	color.red -= max;
	color.green -= max;
	color.blue -= max;
	color.red = (color.red < 0.0f) ? 0.0f : color.red;
	color.green = (color.green < 0.0f) ? 0.0f : color.green;
	color.blue = (color.blue < 0.0f) ? 0.0f : color.blue;
	return (color);
}

static t_rgbap	min_lim(t_rgbap color, float lim)
{
	float min;

	min = color.red;
	min = (min > color.green) ? color.green : min;
	min = (min > color.blue) ? color.blue : min;
	min = lim - min;
	color.red += min;
	color.green += min;
	color.blue += min;
	return (color);
}

static t_rgbap	set_color(t_rgbap color, float lim)
{
	if (color.red < lim && color.green < lim && color.blue < lim)
		color = min_lim(color, lim);
	else if (color.red > lim || color.green > lim || color.blue > lim)
		color = max_lim(color, lim);
	return (color);
}

void			calculate_ambient_light(t_rt *rt)
{
	rt->calc->color.red = rt->calc->cur_mat.diffuse.red;
	rt->calc->color.green = rt->calc->cur_mat.diffuse.green;
	rt->calc->color.blue = rt->calc->cur_mat.diffuse.blue;
	if (rt->scene->lits_n == 0)
		rt->calc->color = set_color(rt->calc->color, 0.3f);
	else
		rt->calc->color = set_color(rt->calc->color, 0.03f);
}
