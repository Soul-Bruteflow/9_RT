#include "rt.h"

/*
** Tracks camera y+ degree.
*/
t_bool    handle_cam_y_pos_deg(t_vec2 *angle, float rot_amt)
{
	if (angle->y > 88.0f)
		return (false);
	else
		angle->y += rot_amt;
	return (true);
}

/*
** Tracks camera y- degree.
*/
t_bool    handle_cam_y_neg_deg(t_vec2 *angle, float rot_amt)
{
	if (angle->y < -88.0f)
		return (false);
	else
		angle->y -= rot_amt;
	return (true);
}