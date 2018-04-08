/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 18:01:43 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_paraboloid	*new_paraboloid(void)
{
	t_paraboloid *paraboloid;

	paraboloid = malloc(sizeof(*(paraboloid)));
	if (paraboloid == NULL)
		rtv_error(malloc_error);
	return (paraboloid);
}

static void		set_paraboloid_param(t_obj3d *obj, float a)
{
	t_paraboloid *paraboloid;

	paraboloid = obj->type;
	paraboloid->a = a;
}

void			set_paraboloid(t_obj3d *obj, t_vec3 *pr,
				float a, Uint16 mat)
{
	set_object_position(obj, pr[0]);
	set_object_rotation(obj, pr[1]);
	set_object_material(obj, mat);
	set_paraboloid_param(obj, a);
}
