#ifndef RT_TEST_H
#define RT_TEST_H

/*
** Transform struct definition.
*/
typedef struct	s_transform
{
	t_vec3		translation;
	t_quat		rotation;
	t_quat		rotx;
	t_quat		roty;
	t_quat		rotz;
	t_vec3		scale;
	t_vec3		angle;

}				t_transform;

t_transform		init_transform(void);
t_mat4			get_model(t_transform *t);

#endif
