/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_frenel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <vholovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/09 15:25:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	calculate(double n1, double n2, float cos_angle_1, float sin_angle_2)
{
	float	cos_angle_2;
	float	Rs;
	float	Rp;

	cos_angle_2 = 1.0f - sin_angle_2 * sin_angle_2;
	cos_angle_2 = (cos_angle_2 < 0.0f) ? 0.0f : cos_angle_2;
	cos_angle_2 = sqrtf(cos_angle_2);
	cos_angle_1 = fabsf(cos_angle_1);
	Rs = ((n2 * cos_angle_1) - (n1 * cos_angle_2))
			/ ((n2 * cos_angle_1) + (n1 * cos_angle_2));
	Rp = ((n1 * cos_angle_1) - (n2 * cos_angle_2))
			/ ((n1 * cos_angle_1) + (n2 * cos_angle_2));
	return((Rs * Rs + Rp * Rp) / 2);
}

void			calculate_frenel(t_rt *rt_last, t_rt *rt_cur, float *kr)
{
	double	n1;
	double	n2;
	float	cos_angle_1;
	float	sin_angle_2;

	n1 = (rt_last->calc->last_status_refract == false)
		? 1.00029f : rt_last->calc->cur_mat.refraction;
	n2 = rt_cur->calc->cur_mat.refraction;
	cos_angle_1 = vec3_dot(rt_cur->scene->ray.dir,
			rt_cur->calc->intersect_normal);
	cos_angle_1 = (cos_angle_1 < -1.0f) ? -1.0f : cos_angle_1;
	cos_angle_1 = (cos_angle_1 > 1.0f) ? 1.0f : cos_angle_1;
	if (cos_angle_1 > 0)
		ft_swap(&n1, &n2);
	sin_angle_2 = 1.0f - cos_angle_1 * cos_angle_1;
	sin_angle_2 = (sin_angle_2 < 0.0f) ? 0.0f : sin_angle_2;
	sin_angle_2 = n1 / n2 * sqrtf(sin_angle_2);
	if (sin_angle_2 >= 1.0f)
		*kr = 1.0f;
	else
		*kr = calculate(n1, n2, cos_angle_1, sin_angle_2);
}