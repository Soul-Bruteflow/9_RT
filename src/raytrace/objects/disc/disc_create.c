/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:32:36 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:32:57 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_disc			*new_disc(void)
{
	t_disc *disc;

	disc = malloc(sizeof(*(disc)));
	if (disc == NULL)
		rtv_error(malloc_error);
	return (disc);
}

static void		set_disc_radius(t_obj3d *obj, float r1, float r)
{
	t_disc *disc;

	disc = obj->type;
	disc->r1 = r1;
	disc->r = r;
}

void			set_disc(t_obj3d *obj, t_vec3 *pr,
					float *r1rm, Uint16 mat)
{
	set_object_position(obj, pr[0]);
	set_object_rotation(obj, pr[1]);
	set_object_material(obj, mat);
	set_disc_radius(obj, r1rm[0], r1rm[1]);
}
