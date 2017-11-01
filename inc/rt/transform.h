#ifndef TRANSFORM_H
# define TRANSFORM_H

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

#endif
