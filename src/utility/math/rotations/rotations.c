/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:09:23 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:09:26 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vec3	rotate_x(t_vec3 dot_rot, t_vec3 dot_null, float angle)
{
	float	rad;
	t_vec3	dot_buf;

	rad = ft_to_radians(angle);
	dot_buf.x = dot_rot.x;
	dot_buf.y = dot_null.y + (dot_rot.y - dot_null.y) * cosf(rad)
				- (dot_rot.z - dot_null.z) * sinf(rad);
	dot_buf.z = dot_null.z + (dot_rot.y - dot_null.y) * sinf(rad)
				+ (dot_rot.z - dot_null.z) * cosf(rad);
	return (dot_buf);
}

static t_vec3	rotate_y(t_vec3 dot_rot, t_vec3 dot_null, float angle)
{
	float	rad;
	t_vec3	dot_buf;

	rad = ft_to_radians(angle);
	dot_buf.x = dot_null.x + (dot_rot.x - dot_null.x) * cosf(rad)
				+ (dot_rot.z - dot_null.z) * sinf(rad);
	dot_buf.y = dot_rot.y;
	dot_buf.z = dot_null.z - (dot_rot.x - dot_null.x) * sinf(rad)
				+ (dot_rot.z - dot_null.z) * cosf(rad);
	return (dot_buf);
}

static t_vec3	rotate_z(t_vec3 dot_rot, t_vec3 dot_null, float angle)
{
	float	rad;
	t_vec3	dot_buf;

	rad = ft_to_radians(angle);
	dot_buf.x = dot_null.x + (dot_rot.x - dot_null.x) * cosf(rad)
				- (dot_rot.y - dot_null.y) * sinf(rad);
	dot_buf.y = dot_null.y + (dot_rot.x - dot_null.x) * sinf(rad)
				+ (dot_rot.y - dot_null.y) * cosf(rad);
	dot_buf.z = dot_rot.z;
	return (dot_buf);
}

t_vec3			obj_rotation(t_vec3 vec, t_vec3 pos, t_vec3 rot)
{
	vec = rotate_x(vec, pos, rot.x);
	vec = rotate_y(vec, pos, rot.y);
	vec = rotate_z(vec, pos, rot.z);
	return (vec);
}
