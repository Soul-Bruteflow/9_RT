/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:26:48 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Find closest intersection
*/

t_bool	object_intersect(t_rt *rtv, t_ray *r, int *cur_obj, t_vec3 *new_start)
{
	float			t;
	int				i;
	t_vec3			scaled;

	t = rtv->scene->cam.p.far;
	i = -1;
	while (i++ < rtv->scene->objs_n - 1)
	{
		if (rtv->scene->objects[i]->intersect(r, rtv->scene->objects[i], &t))
			*cur_obj = i;
	}
	if (*cur_obj == -1)
		return (false);
	scaled = vec3_scale(t, &r->dir);
	*new_start = vec3_add(&r->start, &scaled);
	return (true);
}

/*
** Find the normal for this new vector at the point of intersection.
** n - normal; s - new_start;
*/

t_bool	normal_of_intersect(t_vec3d *n, t_vec3d *s, int cur_obj, t_scene *scene)
{
//	float		temp;
	if (scene->objects[cur_obj]->obj_type == plane)
	{
		t_plane		*plane;
		plane = scene->objects[cur_obj]->type;
		t_vec3d tmp1 = vec3_add(s, &plane->normal);
		t_vec3d tmp2 = vec3_sub(s, &scene->objects[cur_obj]->pos);
		*n = vec3_sub(&tmp2, &tmp1);
	}
	else if (scene->objects[cur_obj]->obj_type == sphere)
	{
		*n = vec3_sub(s, &scene->objects[cur_obj]->pos);
	}
	else if (scene->objects[cur_obj]->obj_type == cylinder)
	{
		t_cylinder	*cylinder;
		cylinder = scene->objects[cur_obj]->type;
		t_vec3d rot	= vec3_sub(&cylinder->a, &cylinder->b);
		t_vec3d tmp1 = vec3_scale(vec3_dot(&scene->ray.dir, &rot)
			+ vec3_dot(s, &rot), &rot);
		t_vec3d	tmp2 = vec3_sub(s, &scene->objects[cur_obj]->pos);
		*n = vec3_sub(&tmp2, &tmp1);
	}
	else if (scene->objects[cur_obj]->obj_type == cone)
	{
		t_cone		*cone;
		cone = scene->objects[cur_obj]->type;
		t_vec3d tmp1 = vec3_scale(vec3_dot(&scene->ray.dir, &cone->axis)
			+ vec3_dot(s, &cone->axis), &cone->axis);
		tmp1 = vec3_scale((1 + pow(tan(cone->angle), 2)), &tmp1);
		t_vec3d	tmp2 = vec3_sub(s, &scene->objects[cur_obj]->pos);
		*n = vec3_sub(&tmp2, &tmp1);
	}
//	temp = vec3_dot(n, n);
//	if (temp == 0)
//		return (false);
//	temp = 1.0f / sqrtf(temp);
//	*n = vec3_scale(temp, n);
	*n = vec3_norm(*n);
	return (true);
}