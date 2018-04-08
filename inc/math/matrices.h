/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:20:51 by vholovin          #+#    #+#             */
/*   Updated: 2018/04/03 15:20:53 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

/*
** 4x4 matrix representation
*/
typedef struct	s_mat4
{
	float		m[4][4];
}				t_mat4;
/*
** Matrices initializations
*/
t_mat4			init_identiny(void);
t_mat4			init_translation(t_vec3 v);
t_mat4			init_rotation(t_vec3 v);
t_mat4			init_scale(t_vec3 v);
t_mat4			init_cam_mat(t_vec3 dir, t_vec3 up);
t_mat4			init_rotation_x(float z);
t_mat4			init_rotation_y(float x);
t_mat4			init_rotation_z(float y);
t_mat4			init_quat_m1(t_quat q);
t_mat4			init_quat_m2(t_quat q);
/*
** Matrices operations
*/
t_mat4			mat_mult(t_mat4 *m1, t_mat4 *m2);
t_vec3			mat_mult_vec3d(t_mat4 m, t_vec3 v);
t_mat4			quat_to_mat(t_quat q);

#endif
