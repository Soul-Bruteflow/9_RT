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

t_bool	object_intersect(t_rt *rt)
{
	float		t;
	int			i;
	t_vec3		scaled;

	t = MAX_LEN;
	i = -1;
	while (i++ < rt->scene->objs_n - 1)
	{
			if (rt->scene->objects[i]->intersect(&rt->scene->ray, rt->scene->objects[i], &t))
			rt->calc->cur_obj = i;
	}
	if (rt->calc->cur_obj == -1)
		return (false);
	rt->calc->old_start = rt->scene->ray.pos;
	scaled = vec3_scale(t, &rt->scene->ray.dir);
	rt->calc->new_start = vec3_add(&rt->scene->ray.pos, &scaled);
	rt->scene->ray.pos = rt->calc->new_start;
	return (true);
}

/*
** Find the normal for this new vector at the point of intersection.
** n - normal; s - new_start;
*/

t_bool	normal_of_intersect(t_rt *rt, t_vec3 *n)
{
	if (rt->scene->objects[rt->calc->cur_obj]->obj_type == plane)
	{
		t_plane		*plane;
		plane = rt->scene->objects[rt->calc->cur_obj]->type;
		*n = plane->normal;
	}
	else if (rt->scene->objects[rt->calc->cur_obj]->obj_type == sphere)
	{
		*n = vec3_sub(&rt->calc->new_start, &rt->scene->objects[rt->calc->cur_obj]->pos);
		rt->scene->normal = n;
	}
	else if (rt->scene->objects[rt->calc->cur_obj]->obj_type == cylinder)
	{
		t_cylinder	*cylinder;
		cylinder = rt->scene->objects[rt->calc->cur_obj]->type;
		t_vec3 rot	= vec3_sub(&cylinder->a, &cylinder->b);
		rot = vec3_norm(rot);
		t_vec3 tmp0 = vec3_sub(&rt->calc->new_start, &rt->scene->objects[rt->calc->cur_obj]->pos);
		t_vec3 tmp1 = vec3_scale(vec3_dot(rt->scene->ray.dir, rot)
			+ vec3_dot(tmp0, rot), &rot);
		*n = vec3_sub(&tmp0, &tmp1);
	}
	else if (rt->scene->objects[rt->calc->cur_obj]->obj_type == cone)
	{
		t_cone		*cone;
		cone = rt->scene->objects[rt->calc->cur_obj]->type;
		cone->axis = vec3_norm(cone->axis);
		t_vec3 tmp0 = vec3_sub(&rt->calc->new_start, &rt->scene->objects[rt->calc->cur_obj]->pos);
		t_vec3 tmp1 = vec3_scale((vec3_dot(rt->scene->ray.dir, cone->axis) + vec3_dot(tmp0, cone->axis)),
			 &cone->axis);
		tmp1 = vec3_scale((1.0f + powf(tanf(cone->angle), 2.0f)), &tmp1);
		*n = vec3_sub(&tmp0, &tmp1);
}
	*n = vec3_norm(*n);
	return (true);
}