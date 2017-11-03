#include "rt.h"

t_mat4	init_cam_mat(t_vec3d dir, t_vec3d up)
{
	t_mat4	m;
	t_vec3d	d;
	t_vec3d	u;
	t_vec3d	r;

	d = vec3_norm(dir);
	r = vec3_norm(vec3_cross(&dir, &up));
	u = vec3_cross(&r, &d);
	m.m[0][0] = r.x;
	m.m[0][1] = r.y;
	m.m[0][2] = r.z;
	m.m[0][3] = 0;

	m.m[1][0] = u.x;
	m.m[1][1] = u.y;
	m.m[1][2] = u.z;
	m.m[1][3] = 0;

	m.m[2][0] = d.x;
	m.m[2][1] = d.y;
	m.m[2][2] = d.z;
	m.m[2][3] = 0;

	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_mat4	init_translation(t_vec3d v)
{
	t_mat4	m;

	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = v.x;

	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[1][3] = v.y;

	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = v.z;

	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_mat4	init_rotation(t_vec3d v)
{
	t_mat4		rx;
	t_mat4		ry;
	t_mat4		rz;
	t_mat4		m;

	v.x = ft_to_radians(v.x);
	v.y = ft_to_radians(v.y);
	v.z = ft_to_radians(v.z);
	rx = init_rotation_x(v.z);
	ry = init_rotation_y(v.x);
	rz = init_rotation_z(v.y);
	m = mat_mult(&rx, &ry);
	m = mat_mult(&m, &rz);
	return (m);
}

t_mat4	init_scale(t_vec3d v)
{
	t_mat4	m;

	m.m[0][0] = v.x;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;

	m.m[1][0] = 0;
	m.m[1][1] = v.y;
	m.m[1][2] = 0;
	m.m[1][3] = 0;

	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = v.z;
	m.m[2][3] = 0;

	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_mat4	init_cam_projection(t_persp p)
{
	t_mat4	m;
	float	ar;
	float	tan_half_fov;
	float 	range;

	range = p.near - p.far;
	ar = p.width / p.height;
	tan_half_fov = tanf(ft_to_radians(p.fov / 2));
	m.m[0][0] = 1.0f / (tan_half_fov * ar);
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 1.0f / tan_half_fov;
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = (-p.near - p.far) / range;
	m.m[2][3] = 2 * p.far * p.near / range;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 1;
	m.m[3][3] = 0;
	return (m);
}