/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 18:20:52 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_triangle		*new_triangle(void)
{
	t_triangle *triangle;

	triangle = malloc(sizeof(*(triangle)));
	if (triangle == NULL)
		rtv_error(malloc_error);
	return (triangle);
}

static void		set_triangle_pos(t_obj3d *obj, t_vec3 a, t_vec3 b, t_vec3 c)
{
	t_triangle	*triangle;
	t_vec3		tmp0;
	t_vec3		tmp1;

	triangle = obj->type;
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	tmp0 = vec3_sub(&b, &a);
	tmp1 = vec3_sub(&c, &a);
	obj->rot = vec3_norm(vec3_cross(&tmp1, &tmp0));
}

void			set_triangle(t_obj3d *obj, t_vec3 *abc,
				Uint16 mat)
{
	set_object_material(obj, mat);
	set_triangle_pos(obj, abc[0], abc[1], abc[2]);
}
