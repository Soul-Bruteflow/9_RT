#ifndef _CAMERA_H
# define _CAMERA_H

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
	t_vec3		pos;
	t_vec3		dir;
	t_vec3		up;
	t_vec3		right;
	t_vec3		world_up;
	float 		mov_amt;
	float 		rot_amt;
	float		horiz_angle;
	float		verti_angle;
	float		mouse_speed;
	t_persp		p;
	t_transform	t;
	t_sup		s;
}				t_cam;

/*
** Camera
*/
t_cam			*create_perspective_cam(t_vec3 origin, t_vec3 target,
										 t_vec3 upguide, float fov_asp[]);
void			make_ray(t_cam *cam, t_vec2 point, t_ray *r);
void			cam_move(t_cam *c, t_vec3 *axis, float amt);
void			cam_update(t_cam *c, t_vec3 *ray_start);
void			cam_rot(t_cam *c, t_vec3 *axis, float angle);
t_quat	quat_rotate_cam(t_cam *c, t_vec3 *axis, float angle);
void			cam_rot_x(t_cam *c, float angle);
void			cam_rot_y(t_cam *c, float angle);

t_mat4			get_mvp(t_cam *c);
t_mat4			init_cam_projection(t_persp p);

#endif
