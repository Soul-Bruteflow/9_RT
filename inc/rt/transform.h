#ifndef TRANSFORM_H
# define TRANSFORM_H

#include "math/math.h"
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
t_mat4			get_proj_transformation(t_transform *t);

#endif
