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
	t_vec3		eye;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;
	t_vec3		world_up;
	float 		mov_amt;
	float 		rot_amt;
	t_vec2 		m_rot_amt;
	t_persp		p;
	t_transform	t;
	t_sup		s;
}				t_cam;

/*
** Camera
*/
void			cam_move(t_cam *c, t_vec3 *axis, float amt);
void			cam_rot_x(t_cam *c, float angle);
void			cam_rot_y(t_cam *c, float angle);
void			cam_rot_z(t_cam *c, float angle);
void			cam_update(t_cam *c);
void			cam_update2(t_cam *c);
void			cam_rot(t_cam *c, t_vec3 angle);
void			update_cam_from_quat(t_cam *c);
t_mat4			get_mvp(t_cam *c);
t_mat4			init_cam_projection(t_persp p);
t_bool          handle_cam_y_pos_deg(t_vec2 *angle, float rot_amt);
t_bool          handle_cam_y_neg_deg(t_vec2 *angle, float rot_amt);
void            handle_cam_x_pos_deg(t_vec2 *angle, float rot_amt);
void            handle_cam_x_neg_deg(t_vec2 *angle, float rot_amt);
#endif
