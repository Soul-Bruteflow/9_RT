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
	t_cam	*tm_cam;

	tm_cam = &r->scene->cam;
//	tm_cam->roll = 0;

//	if ()/


	tm_cam->world_up.x = 0;
	tm_cam->world_up.y = 1;
	tm_cam->world_up.z = 0;

	tm_cam->p.near = 0.00001f;
	tm_cam->p.far = 30000;
	tm_cam->p.width = WIDTH;
	tm_cam->p.height = HEIGHT;

	tm_cam->t = init_transform();

//	tm_cam->world_up.x = sinf(tm_cam->roll);
//	tm_cam->world_up.y = -cosf(tm_cam->roll);
//	tm_cam->world_up.z = 0;
//	tm_cam->world_up = vec3_norm(tm_cam->world_up);
	tm_cam->dir = vec3_norm(vec3_sub(&tm_cam->dir, &tm_cam->pos));
	tm_cam->right = vec3_norm(vec3_cross(&tm_cam->dir, &tm_cam->world_up));
	tm_cam->up = vec3_norm(vec3_cross(&tm_cam->right, &tm_cam->dir));

	fov_radians = PI * (tm_cam->p.fov / 2) / 180;
	height_width_ratio = (float)HEIGHT / (float)WIDTH;
	tm_cam->s.half_width = tanf(fov_radians);
	tm_cam->s.half_height = height_width_ratio * tm_cam->s.half_width;
	camerawidth = tm_cam->s.half_width * 2;
	cameraheight = tm_cam->s.half_height * 2;
	tm_cam->s.pixel_width = camerawidth / ((float)WIDTH - 1);
	tm_cam->s.pixel_height = cameraheight / ((float)HEIGHT - 1);
	r->scene->ray.start = tm_cam->pos;
//	tm_cam->world_up = vec3_cross(&tm_cam->dir, &tm_cam->right);
}

void	cam_update(t_cam *c, t_vec3d *ray_start)
{
//	c->world_up.x = 0;
//	c->world_up.y = 1;
//	c->world_up.z = 0;
//	c->dir = vec3_norm(vec3_sub(&c->dir, &c->pos));
	c->right = vec3_norm(vec3_cross(&c->dir, &c->world_up));
	c->up = vec3_norm(vec3_cross(&c->right, &c->dir));
	*ray_start = c->pos;
}

void	cam_rot_x(t_cam *c, float angle)
{
	t_vec3d h_axis;

	h_axis = vec3_norm(vec3_cross(&c->world_up, &c->dir));
	c->dir = vec3_norm(vec3_rotate(angle, &h_axis));
	c->up = vec3_norm(vec3_cross(&c->dir, &h_axis));
}

void	cam_rot_y(t_cam *c, float angle)
{
	t_vec3d h_axis;
	t_vec3d	tmp;

	h_axis = vec3_norm(vec3_cross(&c->world_up, &c->dir));
	tmp = vec3_norm(vec3_rotate(angle, &c->world_up));


	c->dir = vec3_add(&tmp, &c->dir);
	c->up = vec3_norm(vec3_cross(&c->dir, &h_axis));
}

void	cam_move(t_cam *c, t_vec3d *cam_pos, t_vec3d *dir, float amt)
{
	t_mat4	m;
	t_vec3d	move_to;

	c->t.translation = vec3_scale(amt, dir);
//	move_to = vec3_scale(amt, dir);
	m = get_proj_transformation(c);
//	*cam_pos = mat_mult_vec3d(m, vec3_add(cam_pos, &move_to));
	c->right.x = m.m[0][0];
	c->right.y = m.m[0][1];
	c->right.z = m.m[0][2];
	c->up.x = m.m[1][0];
	c->up.y = m.m[1][1];
	c->up.z = m.m[1][2];
	c->dir.x = m.m[2][0];
	c->dir.y = m.m[2][1];
	c->dir.z = m.m[2][2];
	c->pos.x += m.m[0][3];
	c->pos.y += m.m[1][3];
	c->pos.z += m.m[2][3];
}
