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

//	c->pos = set_vector(0, 0, -2000);
//	c->dir = set_vector(0, 0, 1);
	c->world_up.x = 0;
	c->world_up.y = 1;
	c->world_up.z = 0;
	c->p.fov = 25;
	c->p.near = 0.00001f;
	c->p.far = 30000;
	c->p.width = WIDTH;
	c->p.height = HEIGHT;

	c->t = init_transform();

	c->dir = vec3_norm(vec3_sub(&c->dir, &c->pos));
	c->right = vec3_norm(vec3_cross(&c->dir, &c->world_up));
	c->up = vec3_norm(vec3_cross(&c->right, &c->dir));

	c->horiz_angle = 3.14f;
	c->verti_angle = 0;
	c->mouse_speed = 0.000000000005f / 1000;

	fov_radians = PI * (c->p.fov / 2) / 180;
	height_width_ratio = (float)HEIGHT / (float)WIDTH;
	c->s.half_width = tanf(fov_radians);
	c->s.half_height = height_width_ratio * c->s.half_width;
	camerawidth = c->s.half_width * 2;
	cameraheight = c->s.half_height * 2;
	c->s.pixel_width = camerawidth / ((float)WIDTH - 1);
	c->s.pixel_height = cameraheight / ((float)HEIGHT - 1);
	r->scene->ray.start = c->pos;
//	c->world_up = vec3_cross(&c->dir, &c->right);
}

void	cam_update(t_cam *c, t_vec3 *ray_start)
{
//	c->world_up.x = 0;
//	c->world_up.y = 1;
//	c->world_up.z = 0;
//	c->dir = vec3_norm(vec3_sub(&c->dir, &c->pos));
//	c->right = vec3_norm(vec3_cross(&c->dir, &c->world_up));
//	c->up = vec3_norm(vec3_cross(&c->right, &c->dir));
	*ray_start = c->pos;
}

void	cam_rot_x(t_cam *c, float angle)
{
//	t_vec3 h_axis;
//
//	h_axis = vec3_norm(vec3_cross(&c->world_up, &c->dir));
//	c->dir = vec3_norm(vec3_rotate(angle, &h_axis));
//	c->up = vec3_norm(vec3_cross(&c->dir, &h_axis));
}

void	cam_rot_y(t_cam *c, float angle)
{
	t_quat	tmp;
	t_quat	old_dir;
	t_quat	old_right;
	t_quat	real;
	t_quat	inverse;
	t_quat	new_dir;
	t_quat	new_right;

	old_dir.x = c->dir.x;
	old_dir.y = c->dir.y;
	old_dir.z = c->dir.z;
	old_dir.w = 0;

	old_right.x = c->right.x;
	old_right.y = c->right.y;
	old_right.z = c->right.z;
	old_right.w = 0;

	c->right = vec3_norm(c->right);
	real = set_quat_v(c->right, angle);
	inverse = quat_conjugate(real);
	tmp = quat_mul(old_dir, real);
	new_dir = quat_mul(tmp, inverse);

	tmp = quat_mul(old_right, real);
	new_right = quat_mul(tmp, inverse);

	c->dir.x = new_dir.x;
	c->dir.y = new_dir.y;
	c->dir.z = new_dir.z;

	c->right.x = new_right.x;
	c->right.y = new_right.y;
	c->right.z = new_right.z;

//	c->up = vec3_norm(vec3_cross(&c->right, &c->dir));

	c->dir = vec3_norm(c->dir);
	c->up = vec3_norm(c->up);
	c->right = vec3_norm(c->right);
}

void	cam_move(t_cam *c, t_vec3 *axis, float amt)
{
	t_mat4	mvp;
//	t_vec3	move_to;

	c->t.translation = vec3_scale(amt, axis);
//	move_to = vec3_scale(amt, &c->dir);
	mvp = get_mvp(c);
//	c->pos = mat_mult_vec3d(mvp, vec3_add(&c->pos, &move_to));
//	c->right.x = mvp.mvp[0][0];
//	c->right.y = mvp.mvp[0][1];
//	c->right.z = mvp.mvp[0][2];
//	c->up.x = mvp.mvp[1][0];
//	c->up.y = mvp.mvp[1][1];
//	c->up.z = mvp.mvp[1][2];
//	c->dir.x = mvp.mvp[2][0];
//	c->dir.y = mvp.mvp[2][1];
//	c->dir.z = mvp.mvp[2][2];
	c->pos.x += mvp.m[0][3];
	c->pos.y += mvp.m[1][3];
	c->pos.z += mvp.m[2][3];
}

void	cam_rot(t_cam *c, t_vec3 *axis, float angle)
{
	t_mat4	mvp;
	c->t.rotation = quat_rotate_cam(c, axis, angle);
}

t_quat	quat_rotate_cam(t_cam *c, t_vec3 *axis, float angle)
{

}