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

t_bool	object_intersect(t_rt *rt, t_ray *r, int *cur_obj, t_vec3 *new_start)
{
	float		t;
	int			i;
	t_vec3		scaled;

/* to define t = 10000 */
	t = 10000;
	i = -1;
	while (i++ < rt->scene->objs_n - 1)
	{
			if (rt->scene->objects[i]->intersect(r, rt->scene->objects[i], &t))
			*cur_obj = i;
	}
	if (*cur_obj == -1)
		return (false);
	rt->calc->old_start = *new_start;
	scaled = vec3_scale(t, &r->dir);
	*new_start = vec3_add(&r->start, &scaled);
	return (true);
}

/*
** Find the normal for this new vector at the point of intersection.
** n - normal; s - new_start;
*/

t_bool	normal_of_intersect(t_vec3 *n, t_vec3 *s, int cur_obj, t_scene *scene)
{
//	float		temp;

	if (scene->objects[cur_obj]->obj_type == plane)
	{
		t_plane		*plane;
		plane = scene->objects[cur_obj]->type;
		*n = plane->normal;
	}
	else if (scene->objects[cur_obj]->obj_type == sphere)
	{
		*n = vec3_sub(s, &scene->objects[cur_obj]->pos);
	}
	else if (scene->objects[cur_obj]->obj_type == cylinder)
	{
		t_cylinder	*cylinder;
		cylinder = scene->objects[cur_obj]->type;
		t_vec3 rot	= vec3_sub(&cylinder->a, &cylinder->b);
		rot = vec3_norm(rot);
		t_vec3 tmp0 = vec3_sub(s, &scene->objects[cur_obj]->pos);
		t_vec3 tmp1 = vec3_scale(vec3_dot(scene->ray.dir, rot)
			+ vec3_dot(tmp0, rot), &rot);
		*n = vec3_sub(&tmp0, &tmp1);
	}
	else if (scene->objects[cur_obj]->obj_type == cone)
	{
		t_cone		*cone;
		cone = scene->objects[cur_obj]->type;
		cone->axis = vec3_norm(cone->axis);
		t_vec3 tmp0 = vec3_sub(s, &scene->objects[cur_obj]->pos);
		t_vec3 tmp1 = vec3_scale((vec3_dot(scene->ray.dir, cone->axis) + vec3_dot(tmp0, cone->axis)),
			 &cone->axis);
		tmp1 = vec3_scale((1.0f + powf(tanf(cone->angle), 2.0f)), &tmp1);
		*n = vec3_sub(&tmp0, &tmp1);
}
//	temp = vec3_dot(n, n);
//	if (temp == 0)
//		return (false);
//	temp = 1.0f / sqrtf(temp);
//	*n = vec3_scale(temp, n);
	*n = vec3_norm(*n);
	return (true);
}