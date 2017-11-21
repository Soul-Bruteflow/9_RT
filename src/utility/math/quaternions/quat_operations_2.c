#include "rt.h"

//Unit-Norm Quaternion (Special Form)
t_quat	quat_normalize_s(t_quat q)
{
	float	angle;
	t_vec3	v;

	angle = ft_to_radians(q.w) * 0.5f;
	v.x = q.x;
	v.y = q.y;
	v.z = q.z;
	v = vec3_norm(v);
	q.w = cosf(angle);
	v = vec3_scale(sinf(angle), &v);
	q.x = v.x;
	q.y = v.y;
	q.z = v.z;
	return (q);
}

t_quat	set_quat_f(float x, float y, float z, float w)
{
	t_quat q;

	q.x = x;
	q.y = y;
	q.z = z;
	q.w = w;
	return (q);
}

t_quat	set_quat_v(t_vec3 v, float w)
{
	t_quat q;

	q.x = v.x;
	q.y = v.y;
	q.z = v.z;
	q.w = w;
	return (q);
}

t_quat		from_axis_angle(t_vec3 axis, float angle)
{
	float	sin_half_angle;
	float	cos_half_angle;
	t_quat	rotation;

	sin_half_angle = sinf(ft_to_radians(angle / 2));
	cos_half_angle = cosf(ft_to_radians(angle / 2));
	rotation.x = axis.x * sin_half_angle;
	rotation.y = axis.y * sin_half_angle;
	rotation.z = axis.z * sin_half_angle;
	rotation.w = cos_half_angle;
	rotation = quat_mul_vec3d(rotation, axis);
	return (rotation);
}