/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:21:03 by vholovin          #+#    #+#             */
/*   Updated: 2018/04/03 15:21:04 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNIONS_H
# define QUATERNIONS_H

/*
** Quaternion definition
*/
typedef	struct	s_quat
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_quat;

float			quat_len(t_quat q);
t_quat			quat_normalize(t_quat q);
t_quat			quat_conjugate(t_quat q);
t_quat			quat_mul(t_quat q1, t_quat q2);
t_quat			quat_mul_vec3d(t_quat q, t_vec3 v);
t_quat			from_axis_angle(t_vec3 axis, float angle);
t_vec3			set_vec3_q(t_quat q);
t_quat			set_quat_f(float x, float y, float z, float w);
t_quat			set_quat_v(t_vec3 v, float w);
t_quat			quat_normalize_s(t_quat q);

#endif
