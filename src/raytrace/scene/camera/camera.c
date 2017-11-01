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

#include "rtv.h"
#include "rt/defines.h"

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

//	tm_cam->world_up.x = sinf(tm_cam->roll);
//	tm_cam->world_up.y = -cosf(tm_cam->roll);
//	tm_cam->world_up.z = 0;
//	tm_cam->world_up = vec3_norm(tm_cam->world_up);
	tm_cam->dir = vec3_norm(vec3_sub(&tm_cam->dir, &tm_cam->pos));
	tm_cam->right = vec3_norm(vec3_cross(&tm_cam->dir, &tm_cam->world_up));
	tm_cam->left = vec3_norm(vec3_cross(&tm_cam->world_up, &tm_cam->dir));
	tm_cam->up = vec3_norm(vec3_cross(&tm_cam->right, &tm_cam->dir));

	fov_radians = PI * (tm_cam->fov / 2) / 180;
	height_width_ratio = (float)HEIGHT / (float)WIDTH;
	tm_cam->half_width = tanf(fov_radians);
	tm_cam->half_height = height_width_ratio * tm_cam->half_width;
	camerawidth = tm_cam->half_width * 2;
	cameraheight = tm_cam->half_height * 2;
	tm_cam->pixel_width = camerawidth / ((float)WIDTH - 1);
	tm_cam->pixel_height = cameraheight / ((float)HEIGHT - 1);
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
	c->left = vec3_norm(vec3_cross(&c->world_up, &c->dir));
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

	h_axis = vec3_norm(vec3_cross(&c->world_up, &c->dir));
	c->dir = vec3_norm(vec3_rotate(angle, &c->world_up));
	c->up = vec3_norm(vec3_cross(&c->dir, &h_axis));
}

void	cam_move(t_vec3d *cam_pos, t_vec3d *dir, float amt)
{
	t_vec3d move_to;
	t_mat4	m;

	m = init_identiny();
	move_to = vec3_scale(amt, dir);
	*cam_pos = mat_mult_vec3d(m, vec3_add(cam_pos, &move_to));
}
