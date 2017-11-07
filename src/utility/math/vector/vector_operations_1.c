/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:13:21 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		vec3_add(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3 result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

t_vec3		vec3_sub(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3 result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

float		vec3_dot(t_vec3 *v1, t_vec3 *v2)
{
	float result;

	result = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (result);
}

t_vec3		vec3_scale(float c, t_vec3 *v)
{
	t_vec3 result;

	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}

t_vec3		vec3_cross(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3 result;

	result.x = (v1->y * v2->z) - (v1->z * v2->y);
	result.y = (v1->z * v2->x) - (v1->x * v2->z);
	result.z = (v1->x * v2->y) - (v1->y * v2->x);
	return (result);
}
