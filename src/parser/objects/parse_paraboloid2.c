/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:10:16 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/04/02 14:20:23 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		alloc_new_paraboloid(t_rt *rt, int i)
{
	rt->scene->objects[i] = new_object(paraboloid);
	rt->scene->objects[i]->type = new_paraboloid();
	rt->scene->objects[i]->intersect = intersect_paraboloid;
	rt->scene->objects[i]->normal = normal_paraboloid;
}

t_vec3		parse_parab_single_pos(cJSON *temp)
{
	cJSON	*temp2;
	cJSON	*temp3;
	t_vec3	pos;

	temp2 = cJSON_GetObjectItem(temp, "position");
	temp3 = cJSON_GetObjectItem(temp2, "x");
	pos.x = temp3->valuedouble;
	temp3 = cJSON_GetObjectItem(temp2, "y");
	pos.y = temp3->valuedouble;
	temp3 = cJSON_GetObjectItem(temp2, "z");
	pos.z = temp3->valuedouble;
	return (pos);
}
