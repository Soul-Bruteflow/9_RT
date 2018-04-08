/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:21:22 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 18:20:35 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_torus			*new_torus(void)
{
	t_torus *torus;

	torus = malloc(sizeof(*(torus)));
	if (torus == NULL)
		rtv_error(malloc_error);
	return (torus);
}

static void		set_torus_radius(t_obj3d *obj, float r1, float r)
{
	t_torus *torus;

	torus = obj->type;
	torus->r1 = r1;
	torus->r = r;
}

void			set_torus(t_obj3d *obj, t_vec3 *pr,
					float *lrsrm, Uint16 mat)
{
	set_object_position(obj, pr[0]);
	set_object_rotation(obj, pr[1]);
	set_object_material(obj, mat);
	set_torus_radius(obj, lrsrm[0], lrsrm[1]);
}
