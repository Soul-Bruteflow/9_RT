#ifndef _MATRICES_H
# define _MATRICES_H

/*
** 4x4 matrix representation
*/
typedef struct	s_mat4
{
	float 		m[4][4];
}				t_mat4;

/*
** Matrices initializations
*/
t_mat4			init_identiny(void);
t_mat4			init_translation(t_vec3d v);
t_mat4			init_rotation(t_vec3d v);
t_mat4			init_scale(t_vec3d v);
t_mat4			init_cam_mat(t_vec3d dir, t_vec3d up);
t_mat4			init_rotation_x(float z);
t_mat4			init_rotation_y(float x);
t_mat4			init_rotation_z(float y);
/*
** Matrices operations
*/
t_mat4			mat_mult(t_mat4 *m1, t_mat4 *m2);
t_vec3d			mat_mult_vec3d(t_mat4 m, t_vec3d v);


#endif
