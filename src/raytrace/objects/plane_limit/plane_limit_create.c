/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_limit_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 18:20:13 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane_limit	*new_plane_limit(void)
{
	t_plane_limit *plane_limit;

	plane_limit = malloc(sizeof(*(plane_limit)));
	if (plane_limit == NULL)
		rtv_error(malloc_error);
	return (plane_limit);
}

static t_vec3	create(float h, float w, t_vec3 pos, t_vec3 rot)
{
	t_vec3	buf;

	buf.x = pos.x + h * rot.y + w * rot.z;
	buf.y = pos.y + w * rot.x - h * rot.z;
	buf.z = pos.z;
	return (buf);
}

static void		set_plane_parameters(t_obj3d *obj, float h, float w)
{
	t_plane_limit	*p;
	t_vec3			tmp[2];

	p = obj->type;
	p->d1 = create(h / 2, w / 2, obj->pos, (t_vec3){0, 0, 1});
	p->d1 = obj_rotation(p->d1, obj->pos, obj->rot);
	p->d2 = create(h / 2, -w / 2, obj->pos, (t_vec3){0, 0, 1});
	p->d2 = obj_rotation(p->d2, obj->pos, obj->rot);
	p->d3 = create(-h / 2, -w / 2, obj->pos, (t_vec3){0, 0, 1});
	p->d3 = obj_rotation(p->d3, obj->pos, obj->rot);
	p->d4 = create(-h / 2, w / 2, obj->pos, (t_vec3){0, 0, 1});
	p->d4 = obj_rotation(p->d4, obj->pos, obj->rot);
	tmp[0] = vec3_sub(&p->d2, &p->d1);
	tmp[1] = vec3_sub(&p->d3, &p->d1);
	obj->rot = vec3_norm(vec3_cross(&tmp[1], &tmp[0]));
}

void			set_plane_limit(t_obj3d *obj, t_vec3 *pr, float *hw, Uint16 mat)
{
	set_object_position(obj, pr[0]);
	set_object_rotation(obj, pr[1]);
	set_object_material(obj, mat);
	set_plane_parameters(obj, hw[0], hw[1]);
}
