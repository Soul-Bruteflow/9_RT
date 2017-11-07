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

void	init_camera(t_rtv *r)
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

void	cam_update(t_cam *c, t_vec3d *ray_start)
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
//	t_vec3d h_axis;
//
//	h_axis = vec3_norm(vec3_cross(&c->world_up, &c->dir));
//	c->dir = vec3_norm(vec3_rotate(angle, &h_axis));
//	c->up = vec3_norm(vec3_cross(&c->dir, &h_axis));
}

void	cam_rot_y(t_cam *c, float angle)
{
//	t_vec3d h_axis;
//	t_quat	q;
//	t_mat4	rotation;
//	t_mat4	translation;
//	t_mat4	scale;
//	t_mat4	m;
//	t_mat4	transformation;
//	t_mat4	projection;
//	t_vec3d	tmp;

	t_quat	pure;
	t_quat	real;
	t_quat	inverse;
	t_quat	result;
	t_quat	result2;
	t_quat	pure2;

	pure.x = c->dir.x;
	pure.y = c->dir.y;
	pure.z = c->dir.z;
	pure.w = 0;

	pure2.x = c->up.x;
	pure2.y = c->up.y;
	pure2.z = c->up.z;
	pure2.w = 0;

	c->up = vec3_norm(c->up);
	real = set_quat_v(c->up, angle);
	inverse = quat_conjugate(real);
	result = quat_mul(pure, real);
	result = quat_mul(result, inverse);

	result2 = quat_mul(pure2, real);
	result2 = quat_mul(result2, inverse);

	c->dir.x = result.x;
	c->dir.y = result.y;
	c->dir.z = result.z;

	c->up.x = result2.x;
	c->up.y = result2.y;
	c->up.z = result2.z;

	c->right = vec3_norm(vec3_cross(&c->dir, &c->up));

//	c->dir = vec3_norm(c->dir);



////	c->t.rotation.y += c->rot_amt;
//
////	h_axis = vec3_norm(vec3_cross(&c->world_up, &c->dir));
//	q = quat_norm(vec3_rotate(angle, &c->world_up));
//	rotation = quat_to_mat(q);
//	translation = init_translation(c->t.translation);
//	scale = init_scale(c->t.scale);
//
//	transformation = mat_mult(&scale, &rotation);
//	transformation = mat_mult(&transformation, &translation);
//
//	projection = init_cam_projection(c->p);
////	rotation = init_cam_mat(c->dir, c->up);
////	translation = init_translation(c->pos);
////	m = mat_mult(&transformation, &rotation);
////	m = mat_mult(&rotation, &m);
////	m = mat_mult(&projection, &m);
//	m = mat_mult(&transformation, &projection);

//	t_quat q = quat_norm(vec3_rotate(angle, &c->world_up));
//	t_mat4 m = quat_to_mat(q);

//	t_mat4 model = init_identiny();
//	t_mat4 view = init_cam_mat(c->dir, c->up);
//	t_mat4 projection = init_cam_projection(c->p);
//	t_mat4 m = mat_mult(&model, &view);
//	m = mat_mult(&m, &projection);

//	c->right.x = m.m[0][0];
//	c->right.y = m.m[0][1];
//	c->right.z = m.m[0][2];
//	c->up.x = m.m[1][0];
//	c->up.y = m.m[1][1];
//	c->up.z = m.m[1][2];
//	c->dir.x = m.m[2][0];
//	c->dir.y += angle;
//	c->dir.z = m.m[2][2];

//	c->dir = vec3_norm(c->dir);
//	c->right = vec3_norm(c->right);
//	c->up = vec3_norm(c->up);
//	c->dir = vec3_add(&tmp, &c->dir);
//	c->up = vec3_norm(vec3_cross(&c->dir, &h_axis));
}

void	cam_move(t_cam *c, t_vec3d *cam_pos, t_vec3d *dir, float amt)
{
	t_mat4	m;
	t_vec3d	move_to;

	c->t.translation = vec3_scale(amt, dir);
//	move_to = vec3_scale(amt, dir);
	m = get_proj_transformation(c);
//	*cam_pos = mat_mult_vec3d(m, vec3_add(cam_pos, &move_to));
//	c->right.x = m.m[0][0];
//	c->right.y = m.m[0][1];
//	c->right.z = m.m[0][2];
//	c->up.x = m.m[1][0];
//	c->up.y = m.m[1][1];
//	c->up.z = m.m[1][2];
//	c->dir.x = m.m[2][0];
//	c->dir.y = m.m[2][1];
//	c->dir.z = m.m[2][2];
	c->pos.x += m.m[0][3];
	c->pos.y += m.m[1][3];
	c->pos.z += m.m[2][3];
}
