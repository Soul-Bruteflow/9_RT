#ifndef RT_TEST_H
#define RT_TEST_H

/*
** Transform struct definition.
*/
typedef struct	s_transform
{
	t_vec3d		translation;
	t_vec3d		rotation;
	t_vec3d		scale;

}				t_transform;

t_transform		init_transform(void);
t_mat4			get_transformation(t_transform *t);

#endif
