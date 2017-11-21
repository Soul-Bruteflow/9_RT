#include "rt.h"

/*
** Tracks camera y+ degree.
*/
t_bool    handle_cam_y_pos_deg(t_vec2 *angle, float rot_amt)
{
	if (angle->y > 87.0f)
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
	if (angle->y < -87.0f)
		return (false);
	else
		angle->y -= rot_amt;
	return (true);
}

/*
** Tracks camera x+ degree.
*/
void    handle_cam_x_pos_deg(t_vec2 *angle, float rot_amt)
{
	angle->x += rot_amt;
	angle->x = ft_clamp_wf(angle->x, -360, 360);
}

/*
** Tracks camera x- degree.
*/
void    handle_cam_x_neg_deg(t_vec2 *angle, float rot_amt)
{
	angle->x -= rot_amt;
	angle->x = ft_clamp_wf(angle->x, -360, 360);
}