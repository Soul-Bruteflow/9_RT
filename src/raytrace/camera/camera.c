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

	c->world_up.x = 0;
	c->world_up.y = 1;
	c->world_up.z = 0;
	c->p.fov = 25;
	c->p.near = 0.00001f;
	c->p.far = 30000;
	c->p.width = WIDTH;
	c->p.height = HEIGHT;

	c->t = init_transform();

	c->t.rotation = set_quat_f(0, 0, 0, 1);
	c->t.rotx = set_quat_f(0, 0, 0, 1);
	c->t.roty = set_quat_f(0, 0, 0, 1);
	c->t.rotz = set_quat_f(0, 0, 0, 1);
	c->t.angle = set_vector2(0, 0);

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

	c->t.rotation = quat_mul(c->t.roty, c->t.rotx);
//	c->t.rotation = quat_mul(c->t.rotation, c->t.rotz);
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

//	printf("%f\n", vec3_dot(c->forward, c->world_up));

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
//	printf("%f\n", c->t.angle.y);
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

void	cam_rot_x(t_cam *c, float angle)
{
	c->up = set_vector3(0, 1, 0);
	c->t.rotx = from_axis_angle(c->up, angle);
}

void	cam_rot_y(t_cam *c, float angle, int sign)
{
	c->right = vec3_norm(c->right);
	if (sign < 0)
		c->t.roty = from_axis_angle(c->right, -angle);
	if (sign >= 0)
		c->t.roty = from_axis_angle(c->right, angle);

}
