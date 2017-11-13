#include "rt.h"

t_transform	init_transform(void)
{
	t_transform new_t;

	new_t.translation = set_vector(0, 0, 0);
	new_t.rotation = set_quat_f(0, 0, 0, 1);
	new_t.scale = set_vector(1, 1, 1);
	return (new_t);
}

t_mat4		get_model(t_transform *t)
{
	t_mat4	translation;
	t_mat4	rotation;
//	t_mat4	scale;
	t_mat4	model;

	translation = init_translation(t->translation);
	rotation = quat_to_mat(quat_conjugate(quat_mul(t->rotx, t->roty)));
//	scale = init_scale(t->scale);
	model = mat_mult(&translation, &rotation);
//	model = mat_mult(&model, &translation);
	return (model);
}

t_mat4		get_mvp(t_cam *c)
{
	t_mat4	model;
	t_mat4	projection;
	t_mat4	view;
	t_mat4	mvp;

	model = get_model(&c->t);
	view = init_cam_mat(c->dir, c->up);
	projection = init_cam_projection(c->p);
	mvp = mat_mult(&model, &view);
	mvp = mat_mult(&mvp, &projection);
	return (model);
}