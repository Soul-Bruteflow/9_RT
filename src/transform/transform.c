#include "rt.h"

t_transform	init_transform(void)
{
	t_transform new_t;

	new_t.translation = set_vector(0, 0, 0);
	new_t.rotation = set_vector(0, 0, 0);
	new_t.scale = set_vector(1, 1, 1);
	return (new_t);
}

t_mat4		get_transformation(t_transform *t)
{
	t_mat4	translation;
	t_mat4	rotation;
	t_mat4	scale;
	t_mat4	m;

	translation = init_translation(t->translation);
	rotation = init_rotation(t->rotation);
	scale = init_scale(t->scale);
	m = mat_mult(&scale, &rotation);
	m = mat_mult(&m, &translation);
	return (m);
}

t_mat4		get_proj_transformation(t_cam *c)
{
	t_mat4	transformation;
	t_mat4	projection;
	t_mat4	rotation;
	t_mat4	translation;
	t_mat4	m;

	transformation = get_transformation(&c->t);
	projection = init_cam_projection(c->p);
	rotation = init_cam_mat(c->dir, c->up);
	translation = init_translation(c->pos);
	m = mat_mult(&translation, &transformation);
	m = mat_mult(&rotation, &m);
	m = mat_mult(&projection, &m);
	return (transformation);
}