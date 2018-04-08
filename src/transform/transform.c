/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:17:34 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:17:35 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_transform	init_transform(void)
{
	t_transform t;

	t.rotation = set_quat_f(0, 0, 0, 1);
	t.rotx = set_quat_f(0, 0, 0, 1);
	t.roty = set_quat_f(0, 0, 0, 1);
	t.angle = set_vector2(0, 0);
	return (t);
}

t_mat4		get_model(t_transform *t)
{
	t_mat4	translation;
	t_mat4	rotation;
	t_mat4	model;

	translation = init_translation(t->translation);
	rotation = quat_to_mat(quat_conjugate(quat_mul(t->rotx, t->roty)));
	model = mat_mult(&translation, &rotation);
	return (model);
}

t_mat4		get_mvp(t_cam *c)
{
	t_mat4	model;
	t_mat4	projection;
	t_mat4	view;
	t_mat4	mvp;

	model = get_model(&c->t);
	view = init_cam_mat(c->forward, c->up);
	projection = init_cam_projection(c->p);
	mvp = mat_mult(&model, &view);
	mvp = mat_mult(&mvp, &projection);
	return (model);
}
