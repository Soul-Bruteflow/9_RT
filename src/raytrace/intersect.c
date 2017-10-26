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

#include "rtv.h"

int	sort_distance(t_intersect *ts, int objs_n)
{
	unsigned int	j;
	float 			value;
	unsigned int	ret;

	j = 0;
	value = ts[0].t;
	ret = 0;
	while (j < objs_n - 1)
	{
		if (value > ts[j].t)
		{
			value = ts[j].t;
			ret = j;
		}
		j++;
	}
	return (ret);
}

/*
** Find closest intersection
*/

t_bool	object_intersect(t_rtv *rtv, t_ray *r, int *cur_obj, t_vec3d *new_start)
{
	float			t;
	int				i;
	t_vec3d			scaled;
	int				j;

	t_intersect	ts[rtv->scene->objs_n];

	t = 30000;
	i = -1;
	j = 0;
	while (i++ < rtv->scene->objs_n - 1)
	{
		ts->t = 0;
		ts->i = 0;
	}
	i = -1;
	while (i++ < rtv->scene->objs_n - 1)
	{
		if (rtv->scene->objects[i]->intersect(r, rtv->scene->objects[i], &t))
		{
			ts[j].t = t;
			ts[j].i = i;
			*cur_obj = i;
			j++;
		}
	}
	if (*cur_obj == -1)
		return (false);
	j = sort_distance(ts, rtv->scene->objs_n);
	*cur_obj = ts[j].i;
	t = ts[j].t;
	scaled = vec3_scale(t, &r->dir);
	*new_start = vec3_add(&r->start, &scaled);
	return (true);
}

/*
** Find the normal for this new vector at the point of intersection.
** n - normal; s - new_start;
*/

t_bool	normal_of_intersect(t_vec3d *n, t_vec3d *s, t_obj3d **objs, int cur_obj)
{
	float		temp;

	*n = vec3_sub(s, &objs[cur_obj]->pos);
	temp = vec3_dot(n, n);
	if (temp == 0)
		return (false);
	temp = 1.0f / sqrtf(temp);
	*n = vec3_scale(temp, n);
	return (true);
}
