#ifndef RT_CAMERA_H
# define RT_CAMERA_H

# include "rt/transform.h"
# include "rtv.h"

/*
** Support struct for calculations
*/
typedef struct	s_sup
{
	float		pixel_width;
	float		pixel_height;
	float		half_width;
	float		half_height;
}				t_sup;

/*
** Perspective projection definition
*/
typedef struct	s_persp
{
	float		fov;
	float 		near;
	float 		far;
	float 		width;
	float 		height;
}				t_persp;

/*
** Camera definition
*/
typedef struct	s_cam
{
	t_vec3d		pos;
	t_vec3d		dir;
	t_vec3d		up;
	t_vec3d		right;
	t_vec3d		left;
	t_vec3d		world_up;
	float 		mov_amt;
	float 		rot_amt;
	t_persp		p;
	t_transform	t;
	t_sup		s;
}				t_cam;

#endif
