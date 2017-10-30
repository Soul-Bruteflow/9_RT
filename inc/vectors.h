/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:49:10 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/17 16:49:14 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTORS_H
# define _VECTORS_H

#include <ntsid.h>
#include <math.h>

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
/*
**
*/
typedef struct	s_mat4
{
	float 		m[4][4];
}				t_mat4;
/*
** 3d Vector definition
*/
typedef struct	s_vec3d
{
	float		x;
	float		y;
	float		z;
}				t_vec3d;

/*
** 2d Vector definition
*/
typedef struct	s_vec2d
{
	float		u;
	float		v;
}				t_vec2d;

/*
** ADD two vectors and return the resulting vector
*/
t_vec3d			vec3_add(t_vec3d *v1, t_vec3d *v2);
/*
** ADD three vectors and return the resulting vector
*/
t_vec3d			vec3_add3(t_vec3d a, t_vec3d b, t_vec3d c);
/*
** SUBTRACT two vectors and return the resulting vector
*/
t_vec3d			vec3_sub(t_vec3d *v1, t_vec3d *v2);
/*
** MULTIPLY two vectors and return the resulting scalar (DOT PRODUCT)
*/
float			vec3_dot(t_vec3d *v1, t_vec3d *v2);
/*
** Calculate Vector x Scalar
*/
t_vec3d			vec3_scale(float c, t_vec3d *v);
/*
** Calculate Vector CROSS PRODUCT
*/
t_vec3d			vec3_cross(t_vec3d *v1, t_vec3d *v2);
/*
** Calculate vector length(magnitude).
*/
float			vec3_len(t_vec3d v);
/*
** Calculate normal.
*/
t_vec3d			vec3_norm(t_vec3d v);

t_vec3d		vec3_rotate(float angle, t_vec3d *axis);
float		ft_to_degree(float radians);
float		ft_to_radians(float degrees);

t_mat4		init_identiny(void);
t_mat4		init_translation(float x, float y, float z);
t_mat4		mat_mult(t_mat4 *m1, t_mat4 *m2);

float		quat_len(t_quat q);
t_quat		quat_norm(t_quat q);
t_quat		quat_conjugate(t_quat q);
t_quat		quat_mul(t_quat q1, t_quat q2);
t_quat		quat_mul_vec3d(t_quat q, t_vec3d v);

t_vec3d		mat_mult_vec3d(t_mat4 m, t_vec3d v);

#endif
