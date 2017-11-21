/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:46:29 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_camera(t_rt *r)
{
	float	fov_radians;
	float	height_width_ratio;
	float	camerawidth;
	float	cameraheight;
	t_cam	*c;

	c = &r->scene->cam;
	c->world_up = set_vector3(0, 1, 0);
	c->p.near = 0.00001f;
	c->p.far = 30000;
	c->p.width = WIDTH;
	c->p.height = HEIGHT;
	c->t = init_transform();
	c->forward = vec3_norm(vec3_sub(&c->eye, &c->pos));
	c->right = vec3_norm(vec3_cross(&c->forward, &c->world_up));
	c->up = vec3_norm(vec3_cross(&c->right, &c->forward));
	fov_radians = PI * (c->p.fov / 2) / 180;
	height_width_ratio = (float)HEIGHT / (float)WIDTH;
	c->s.half_width = tanf(fov_radians);
	c->s.half_height = height_width_ratio * c->s.half_width;
	camerawidth = c->s.half_width * 2;
	cameraheight = c->s.half_height * 2;
	c->s.pixel_width = camerawidth / ((float)WIDTH - 1);
	c->s.pixel_height = cameraheight / ((float)HEIGHT - 1);
	r->scene->ray.start = c->pos;
}

void	cam_update(t_cam *c)
{
	t_quat	inverse;
	t_quat	new_dir;
	t_quat	new_right;
	t_quat	new_up;

	c->t.rotation = quat_mul(c->t.roty, c->t.rotx);
	c->t.rotation = quat_normalize(c->t.rotation);
	inverse = quat_conjugate(c->t.rotation);
	new_dir = quat_mul(c->t.rotation, set_quat_v(c->forward, 0));
	new_dir = quat_mul(inverse, new_dir);
	c->forward = vec3_norm(set_vec3_q(new_dir));
	new_up = quat_mul(c->t.rotation, set_quat_v(c->up, 0));
	new_up = quat_mul(inverse, new_up);
	c->up = vec3_norm(set_vec3_q(new_up));
	new_right = quat_mul(c->t.rotation, set_quat_v(c->right, 0));
	new_right = quat_mul(inverse, new_right);
	c->right = vec3_norm(set_vec3_q(new_right));
	c->right = vec3_norm(vec3_cross(&c->forward, &c->up));
	c->up = vec3_norm(vec3_cross(&c->right, &c->forward));
	c->t.rotation = set_quat_f(0, 0, 0, 1);
	c->t.rotx = set_quat_f(0, 0, 0, 1);
	c->t.roty = set_quat_f(0, 0, 0, 1);
}

void	cam_move(t_cam *c, t_vec3 *axis, float amt)
{
	t_mat4  identity;
	t_vec3  move_to;

	identity = init_identiny();
	move_to = vec3_scale(amt, axis);
	c->pos = mat_mult_vec3d(identity, vec3_add(&c->pos, &move_to));
}

void	cam_rot_x(t_cam *c, float angle)
{
	c->up = set_vector3(0, 1, 0);
	c->t.rotx = from_axis_angle(c->up, angle);
}

void	cam_rot_y(t_cam *c, float angle)
{
	c->right = vec3_norm(c->right);
	c->t.roty = from_axis_angle(c->right, angle);
}
