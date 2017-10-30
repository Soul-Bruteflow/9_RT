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
#include "rtv_defines.h"

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


	tm_cam->up.x = 0;
	tm_cam->up.y = 1;
	tm_cam->up.z = 0;

//	tm_cam->up.x = sinf(tm_cam->roll);
//	tm_cam->up.y = -cosf(tm_cam->roll);
//	tm_cam->up.z = 0;
//	tm_cam->up = vec3_norm(tm_cam->up);
	tm_cam->eye = vec3_norm(vec3_sub(&tm_cam->d, &tm_cam->o));
	tm_cam->vp_right = vec3_norm(vec3_cross(&tm_cam->eye, &tm_cam->up));
	tm_cam->vp_left = vec3_norm(vec3_cross(&tm_cam->up, &tm_cam->eye));
	tm_cam->vp_up = vec3_norm(vec3_cross(&tm_cam->vp_right, &tm_cam->eye));

	fov_radians = PI * (tm_cam->fov / 2) / 180;
	height_width_ratio = (float)HEIGHT / (float)WIDTH;
	tm_cam->half_width = tanf(fov_radians);
	tm_cam->half_height = height_width_ratio * tm_cam->half_width;
	camerawidth = tm_cam->half_width * 2;
	cameraheight = tm_cam->half_height * 2;
	tm_cam->pixel_width = camerawidth / ((float)WIDTH - 1);
	tm_cam->pixel_height = cameraheight / ((float)HEIGHT - 1);
	r->scene->ray.start = tm_cam->o;
//	tm_cam->up = vec3_cross(&tm_cam->d, &tm_cam->vp_right);
}

void	cam_update(t_cam *c, t_vec3d *ray_start)
{
//	c->up.x = 0;
//	c->up.y = 1;
//	c->up.z = 0;
//	c->eye = vec3_norm(vec3_sub(&c->d, &c->o));
	c->vp_right = vec3_norm(vec3_cross(&c->eye, &c->up));
	c->vp_left = vec3_norm(vec3_cross(&c->up, &c->eye));
	c->vp_up = vec3_norm(vec3_cross(&c->vp_right, &c->eye));
	*ray_start = c->o;
}

void	cam_rot_x(t_cam *c, float angle)
{
	t_vec3d h_axis;

	h_axis = vec3_norm(vec3_cross(&c->up, &c->eye));
	h_axis = vec3_norm(vec3_rotate(angle, &h_axis));
	c->vp_up = vec3_norm(vec3_cross(&c->eye, &h_axis));
}

void	cam_rot_y(t_cam *c, float angle)
{
	t_vec3d h_axis;

	h_axis = vec3_norm(vec3_cross(&c->up, &c->eye));
	c->eye = vec3_norm(vec3_rotate(angle, &c->up));
	c->vp_up = vec3_norm(vec3_cross(&c->eye, &h_axis));
}

void	cam_move(t_vec3d *cam_pos, t_vec3d *dir, float amt)
{
	t_vec3d move_to;
	t_mat4	m;

	m = init_identiny();
	move_to = vec3_scale(amt, dir);
	*cam_pos = mat_mult_vec3d(m, vec3_add(cam_pos, &move_to));
}
