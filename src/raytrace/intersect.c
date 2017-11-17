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

t_bool	normal_of_intersect(t_vec3 *n, t_vec3 *s, t_obj3d **objs, int cur_obj)
{
	float		temp;

	*n = vec3_sub(s, &objs[cur_obj]->pos);
	temp = vec3_dot(*n, *n);
	if (temp == 0)
		return (false);
	temp = 1.0f / sqrtf(temp);
	*n = vec3_scale(temp, n);
	return (true);
}
