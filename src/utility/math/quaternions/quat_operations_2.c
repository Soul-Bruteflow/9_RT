#include "rt.h"

//Unit-Norm Quaternion (Special Form)
t_quat	quat_normalize_s(t_quat q)
{
	float	angle;
	t_vec3d	v;

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

t_quat	set_quat_v(t_vec3d v, float w)
{
	t_quat q;

	q.x = v.x;
	q.y = v.y;
	q.z = v.z;
	q.w = w;
	return (q);
}