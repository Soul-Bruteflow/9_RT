/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_refl_refr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:28:52 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:36:01 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	calculate_reflect_refract(t_rt *rt)
{
	t_rgbap	c_refl;
	t_rgbap	c_refr;

	c_refl.red = 0;
	c_refl.green = 0;
	c_refl.blue = 0;
	c_refr.red = 0;
	c_refr.green = 0;
	c_refr.blue = 0;
	if (rt->calc->level_reflection != rt->scene->max_level_reflection)
	{
		rt->calc->level_reflection++;
		calculate_reflection(rt, &c_refl);
	}
	if (rt->calc->level_transparent != rt->scene->max_level_transparent)
	{
		rt->calc->level_transparent++;
		calculate_refraction(rt, &c_refr);
	}
	rt->calc->color.red += c_refl.red + c_refr.red;
	rt->calc->color.green += c_refl.green + c_refr.green;
	rt->calc->color.blue += c_refl.blue + c_refr.blue;
}
