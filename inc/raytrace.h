/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:15 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 16:04:03 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RAYTRACE_H
# define _RAYTRACE_H

# include "vectors.h"

/*
** RGBA color 0-255 definition
*/
typedef struct	s_rgba
{
	Uint8		red;
	Uint8		green;
	Uint8		blue;
	Uint8		alpha;
}				t_rgba;

/*
** RGBA color 0%-100%/0-1.0 definition
*/
typedef struct	s_rgbap
{
	float		red;
	float		green;
	float		blue;
	float		alpha;
}				t_rgbap;

/*
** Perspective cmera definition
*/
typedef struct	s_cam
{
	t_vec3d		o;
	t_vec3d		d;
	t_vec3d		up;
	float		fov;
	t_vec3d		eye;
	t_vec3d		vp_right;
	t_vec3d		vp_left;
	t_vec3d		vp_up;
	float		pixel_width;
	float		pixel_height;
	float		half_width;
	float		half_height;
	float 		roll;
	float 		mov_amt;
	float 		rot_amt;
}				t_cam;

/*
** Ray definition
*/
typedef struct	s_ray
{
	t_vec3d		start;
	t_vec3d		dir;
}				t_ray;

/*
** Material definition
*/
typedef struct	s_material
{
	t_rgbap		diffuse;
	float		reflection;
}				t_material;

/*
** Light source definition
*/
typedef struct	s_light
{
	t_vec3d		pos;
	t_rgbap		color;
}				t_light;

/*
** Common
*/
t_rgbap			ft_set_color(float r, float g, float b, float a);
t_vec3d			ft_set_vector(float x, float y, float z);
/*
** Camera
*/
t_cam			*create_perspective_cam(t_vec3d origin, t_vec3d target,
				t_vec3d upguide, float fov_asp[]);
void			make_ray(t_cam *cam, t_vec2d point, t_ray *r);
void			cam_move(t_vec3d *cam_pos, t_vec3d *dir, float amt);
void			cam_update(t_cam *c, t_vec3d *ray_start);
/*
** Material
*/
t_material		*new_material();
void			set_material(t_material *material, t_rgbap diffuse, float r);
/*
** Light
*/
t_light			*new_light();
void			set_light(t_light *light, t_vec3d pos, t_rgbap intensity);

#endif
