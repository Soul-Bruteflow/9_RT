/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:25:33 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_bool	calculate_shadows(t_rtv *r, t_obj3d **objs, t_ray *light_ray, float *t2)
{
	int k;

	k = -1;
	while (k++ < r->scene->objs_n - 1)
	{
		if (objs[k]->intersect(light_ray, objs[k], t2))
			return (true);
	}
	return (false);
}

float	lambert(t_ray *light_ray, t_vec3d *normal, float *coef)
{
	return (vec3_dot(&light_ray->dir, normal) * *coef);
}

/*
** Lambert diffusion
*/

void	lamb_dif(float lamb, t_rgbap *c, t_light cur_light, t_material cur_mat)
{
	c->red += lamb * cur_light.color.red * cur_mat.diffuse.red;
	c->green += lamb * cur_light.color.green * cur_mat.diffuse.green;
	c->blue += lamb * cur_light.color.blue * cur_mat.diffuse.blue;
}

/*
** Iterate over the reflection
** The reflected ray start and direction
*/

void	calculate_reflection(t_rtv *rtv)
{
	rtv->calc->coef *= rtv->calc->cur_mat.reflection;
	rtv->calc->reflect = 2.0f *
	vec3_dot(&rtv->scene->ray.dir, &rtv->calc->intersect_normal);
	rtv->calc->tmp = vec3_scale(rtv->calc->reflect,
	&rtv->calc->intersect_normal);
	rtv->scene->ray.dir = vec3_sub(&rtv->scene->ray.dir, &rtv->calc->tmp);
}

/*
** Find the value of the light at this point
*/

void	calculate_light(t_rtv *rtv)
{
	t_light		cur_light;
	t_vec3d		dist;
	float		t2;
	t_ray		light_ray;
	float		lamb;

	rtv->calc->i = -1;
	while (rtv->calc->i++ < rtv->scene->lits_n - 1)
	{
		cur_light = *rtv->scene->lights[rtv->calc->i];
		dist = vec3_sub(&cur_light.pos, &rtv->calc->new_start);
		if (vec3_dot(&rtv->calc->intersect_normal, &dist) <= 0.0f)
			continue;
		t2 = sqrtf(vec3_dot(&dist, &dist));
		if (t2 <= 0.0f)
			continue;
		light_ray.start = rtv->calc->new_start;
		light_ray.dir = vec3_scale(1.0f / t2, &dist);
//		if ((calculate_shadows(rtv, rtv->scene->objects, &light_ray, &t2)))
//			continue;
//		else
//		{
			lamb = lambert(&light_ray,
			&rtv->calc->intersect_normal, &rtv->calc->coef);
			lamb_dif(lamb, &rtv->calc->color, cur_light, rtv->calc->cur_mat);
//		}
	}
}
