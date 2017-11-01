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
/*
** Set vector
*/
t_vec3d			set_vector(float x, float y, float z);

#endif
