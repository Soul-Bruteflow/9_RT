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
//	c->forward = set_vector(0, 0, 1);
	c->world_up.x = 0;
	c->world_up.y = 1;
	c->world_up.z = 0;
	c->p.fov = 25;
	c->p.near = 0.00001f;
	c->p.far = 30000;
	c->p.width = WIDTH;
	c->p.height = HEIGHT;
	c->horiz_angle = 0;
	c->verti_angle = 0;

	c->t = init_transform();

	c->t.rotation = set_quat_f(0, 0, 0, 1);
	c->t.rotx = set_quat_f(0, 0, 0, 1);
	c->t.roty = set_quat_f(0, 0, 0, 1);
	c->t.rotz = set_quat_f(0, 0, 0, 1);
	c->t.angle = set_vector(0, 0, 0);

	c->t.rotation = quat_mul(c->t.rotx, c->t.roty);
	c->t.rotation = quat_mul(c->t.rotation, c->t.rotz);

	c->forward = vec3_norm(vec3_sub(&c->eye, &c->pos));
	c->right = vec3_norm(vec3_cross(&c->forward, &c->world_up));
	c->up = vec3_norm(vec3_cross(&c->right, &c->forward));

//	printf("forward\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->forward.x,c->forward.y,c->forward.z);
//	printf("\nup\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->up.x,c->up.y,c->up.z);
//	printf("\nright\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->right.x,c->right.y,c->right.z);

//	c->horiz_angle = 3.14f;
//	c->verti_angle = 0;
//	c->mouse_speed = 0.000000000005f / 1000;

	fov_radians = PI * (c->p.fov / 2) / 180;
	height_width_ratio = (float)HEIGHT / (float)WIDTH;
	c->s.half_width = tanf(fov_radians);
	c->s.half_height = height_width_ratio * c->s.half_width;
	camerawidth = c->s.half_width * 2;
	cameraheight = c->s.half_height * 2;
	c->s.pixel_width = camerawidth / ((float)WIDTH - 1);
	c->s.pixel_height = cameraheight / ((float)HEIGHT - 1);
	r->scene->ray.start = c->pos;
//	c->world_up = vec3_cross(&c->forward, &c->right);
}

void	cam_update(t_cam *c)
{
	t_quat	inverse;
	t_quat	new_dir;
	t_quat	new_right;
	t_quat	new_up;

//	c->t.rotation = set_quat_f(0, 0, 0, 1);
//	c->t.rotx = set_quat_f(0, 0, 0, 1);
//	c->t.roty = set_quat_f(0, 0, 0, 1);
//	c->t.rotz = set_quat_f(0, 0, 0, 1);
//
//	c->forward = set_vector(0, -100, 1);
//	c->right = vec3_norm(vec3_cross(&c->forward, &c->world_up));
//	c->up = vec3_norm(vec3_cross(&c->right, &c->forward));
//
////	c->up = vec3_norm(c->up);
//	c->t.rotx = from_axis_angle(&c->up, c->t.angle.y);
//
////	c->right = vec3_norm(c->right);
//	c->t.roty = from_axis_angle(&c->right, c->t.angle.x);
//
//	c->forward = vec3_norm(c->forward);
//	c->t.rotz = from_axis_angle(&c->forward, c->t.angle.z);

//	c->forward = vec3_norm(vec3_sub(&c->eye, &c->pos));
//	c->right = vec3_norm(vec3_cross(&c->forward, &c->world_up));
//	c->up = vec3_norm(vec3_cross(&c->right, &c->forward));
//	c->forward = vec3_norm(c->forward);
//	c->up = vec3_norm(c->up);
//	c->right = vec3_norm(c->right);
	//---------------------------
//	c->t.rotx = from_axis_angle(&c->up, c->t.angle.x);
//	c->t.roty = from_axis_angle(&c->right, c->t.angle.y);
//	c->t.rotz = from_axis_angle(&c->forward, c->t.angle.z);
////--------------------------------
//		printf("forward\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->forward.x,c->forward.y,c->forward.z);
//	printf("\nup\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->up.x,c->up.y,c->up.z);
//	printf("\nright\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->right.x,c->right.y,c->right.z);


//	c->t.rotation = set_quat_f(0, 0, 0, 1);
//	c->t.rotx = set_quat_f(0, 0, 0, 1);
//	c->t.roty = set_quat_f(0, 0, 0, 1);

	c->forward = vec3_norm(vec3_sub(&c->eye, &c->pos));
	c->right = vec3_norm(vec3_cross(&c->forward, &c->world_up));
	c->up = vec3_norm(vec3_cross(&c->right, &c->forward));

//	c->t.rotz = set_quat_f(0, 0, 0, 1);

	c->t.rotation = quat_mul(c->t.rotx, c->t.roty);
//	c->t.rotation = quat_mul(c->t.rotation, c->t.rotz);
	c->t.rotation = quat_normalize(c->t.rotation);

	inverse = quat_conjugate(c->t.rotation);

	new_dir = quat_mul(set_quat_v(c->forward, 0), c->t.rotation);
	new_dir = quat_mul(new_dir, inverse);
	c->forward = vec3_norm(set_vec3_q(new_dir));

	new_up = quat_mul(set_quat_v(c->up, 0), c->t.rotation);
	new_up = quat_mul(new_up, inverse);
	c->up = vec3_norm(set_vec3_q(new_up));

	new_right = quat_mul(set_quat_v(c->right, 0), c->t.rotation);
	new_right = quat_mul(new_right, inverse);
	c->right = vec3_norm(set_vec3_q(new_right));

	c->right = vec3_norm(vec3_cross(&c->forward, &c->up));
	c->up = vec3_norm(vec3_cross(&c->right, &c->forward));

//	printf("%f, %f, %f, %f\n", c->t.rotation.x, c->t.rotation.y, c->t.rotation.z, c->t.rotation.w);

	c->t.rotation = set_quat_f(0, 0, 0, 1);
	c->t.rotx = set_quat_f(0, 0, 0, 1);
	c->t.roty = set_quat_f(0, 0, 0, 1);
	c->t.rotz = set_quat_f(0, 0, 0, 1);

	//	printf("%f\n", vec3_dot(&c->forward, &c->world_up));
//	printf("forward\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->forward.x,c->forward.y,c->forward.z);
//	printf("\nup\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->up.x,c->up.y,c->up.z);
//	printf("\nright\n");
//	printf("x |%f|, y |%f|, z |%f|\n", c->right.x,c->right.y,c->right.z);
	printf("%f\n", c->t.angle.y);
}

void	cam_move(t_cam *c, t_vec3 *axis, float amt)
{
	t_mat4	mvp;
//	t_vec3	move_to;

	c->t.translation = vec3_scale(amt, axis);
//	move_to = vec3_scale(amt, &c->forward);
	mvp = get_mvp(c);
//	c->pos = mat_mult_vec3d(mvp, vec3_add(&c->pos, &move_to));
//	c->right.x = mvp.mvp[0][0];
//	c->right.y = mvp.mvp[0][1];
//	c->right.z = mvp.mvp[0][2];
//	c->up.x = mvp.mvp[1][0];
//	c->up.y = mvp.mvp[1][1];
//	c->up.z = mvp.mvp[1][2];
//	c->forward.x = mvp.mvp[2][0];
//	c->forward.y = mvp.mvp[2][1];
//	c->forward.z = mvp.mvp[2][2];
	c->pos.x += mvp.m[0][3];
	c->pos.y += mvp.m[1][3];
	c->pos.z += mvp.m[2][3];
}

//void	cam_rot(t_cam *c)
//{
////	c->t.rotation = from_axis_angle(axis, angle);
//
////	c->t.rotation = quat_mul(c->t.rotx, c->t.roty);
////	update_cam_from_quat(c);
//	t_quat	xy;
//	t_quat	tmp;
//	t_quat	inverse;
//	t_quat	new_dir;
//	t_quat	new_right;
//	t_quat	new_up;
//
//	new_dir = set_quat_v(c->forward, 0);
//	new_right = set_quat_v(c->right, 0);
//	new_up = set_quat_v(c->up, 0);
//
//	c->t.rotx = from_axis_angle(&new_right, c->t.angle.x);
//	c->t.roty = from_axis_angle(&new_up, c->t.angle.y);
//	xy = quat_mul(c->t.rotx, c->t.roty);
//
//	tmp = quat_mul_vec3d(xy, new_dir);
//	c->forward.x = tmp.x;
//	c->forward.y = tmp.y;
//	c->forward.z = tmp.z;
//
//	c->t.rotz = from_axis_angle(&c->forward, c->t.angle.z);
//
//	c->t.rotation = quat_mul(c->t.rotz, xy);
//	inverse = quat_conjugate(c->t.rotation);
//
//	tmp = quat_mul_vec3d(c->t.rotation, unit_x);
//	tmp = quat_mul_vec3d(tmp, inverse);
//	c->right.x = tmp.x;
//	c->right.y = tmp.y;
//	c->right.z = tmp.z;
//
//	tmp = quat_mul_vec3d(c->t.rotation, unit_y);
//	c->up.x = tmp.x;
//	c->up.y = tmp.y;
//	c->up.z = tmp.z;
//
//
////	qPitch.FromAxisAngle(UNIT_X, pitchYawRoll.x);        // build pitch
////	qYaw.FromAxisAngle(UNIT_Y, pitchYawRoll.y);          // build yaw
////
////	quat qPitchYaw = qYaw * qPitch;
////	vec3 forward = qPitchYaw * UNIT_Z;    // create forward
////
////	quat qRoll;
////	qRoll.FromAxisAngle(forward, pitchYawRoll.z);    // roll about current forward
////
////	quat final = qRoll * qPitchYaw;
////
////
////
////// then if you want up and right
////
////	vec3 right = final * UNIT_X;
////
////	vec3 up = final * UNIT_Y;
//
//}

void	cam_rot_x(t_cam *c, float angle)
{
	c->up = set_vector(0, 1, 0);
//	c->up = vec3_norm(c->up);
	c->t.rotx = from_axis_angle(c->up, angle);
}

void	cam_rot_y(t_cam *c, float angle)
{
	c->right = set_vector(-1, 0, 0);
//	c->right = vec3_norm(c->right);
	c->t.roty = from_axis_angle(c->right, angle);
}

void	cam_rot_z(t_cam *c, float angle)
{
//	c->forward = set_vector(0, 0, 1);
	c->forward = vec3_norm(c->forward);
	c->t.rotz = from_axis_angle(c->forward, angle);
}

void	update_cam_from_quat(t_cam *c)
{
	t_quat	inverse;
	t_quat	new_dir;
	t_quat	new_right;
	t_quat	new_up;

	inverse = quat_conjugate(c->t.rotation);

	new_dir = quat_mul(set_quat_v(c->forward, 0), c->t.rotation);
	new_dir = quat_mul(new_dir, inverse);
	c->forward = vec3_norm(set_vec3_q(new_dir));

//	new_right = quat_mul(set_quat_v(c->right, 0), c->t.rotation);
//	new_right = quat_mul(new_right, inverse);
//	c->right = vec3_norm(set_vec3_q(new_right));

	new_up = quat_mul(set_quat_v(c->up, 0), c->t.rotation);
	new_up = quat_mul(new_up, inverse);
	c->up = vec3_norm(set_vec3_q(new_up));

	c->up = vec3_cross(&c->right, &c->forward);
	c->right = vec3_cross(&c->forward, &c->up);

//	printf("%f\n", vec3_dot(&c->forward, &c->world_up));
//	printf("forward ");
//	printf("x |%f|, y |%f|, z |%f|\n", c->forward.x,c->forward.y,c->forward.z);
//	printf("up ");
//	printf("x |%f|, y |%f|, z |%f|\n", c->up.x,c->up.y,c->up.z);
//	printf("right ");
//	printf("x |%f|, y |%f|, z |%f|\n", c->right.x,c->right.y,c->right.z);
}