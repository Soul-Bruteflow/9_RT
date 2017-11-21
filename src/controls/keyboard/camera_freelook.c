#include "rt.h"

void    camera_freelook(t_rt *r)
{
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_SPACE])
	{
		get_mouse_relative_position(&r->sdl->mouse);
		clamp_mouse_rel_pos(&r->sdl->mouse, CL_REL_N, CL_REL_P);
		invert_mouse_x(&r->sdl->mouse);
		calc_mouse_rot_amt(&r->sdl->mouse, &r->scene->cam);
		camera_horizontal_freelook(r);
		camera_vertical_freelook(r);
	}
}

void    camera_vertical_freelook(t_rt *r)
{
	if (r->sdl->mouse.rpos.y > 0)
	{
		if (r->scene->cam.t.angle.y > 87.00f)
			return;
		r->scene->cam.t.angle.y += r->scene->cam.m_rot_amt.y;
		cam_rot_y(&r->scene->cam, r->scene->cam.m_rot_amt.y);
		cam_update(&r->scene->cam);
	}
	if (r->sdl->mouse.rpos.y < 0)
	{
		if (r->scene->cam.t.angle.y < -87.00f)
			return;
		r->scene->cam.t.angle.y += r->scene->cam.m_rot_amt.y;
		cam_rot_y(&r->scene->cam, r->scene->cam.m_rot_amt.y);
		cam_update(&r->scene->cam);
	}
}

void    camera_horizontal_freelook(t_rt *r)
{
	if (r->sdl->mouse.rpos.x > 0)
	{
		handle_cam_x_pos_deg(&r->scene->cam.t.angle, r->scene->cam.m_rot_amt.x * -1);
		cam_rot_x(&r->scene->cam, r->scene->cam.m_rot_amt.x);
		cam_update(&r->scene->cam);
	}
	if (r->sdl->mouse.rpos.x < 0)
	{
		handle_cam_x_neg_deg(&r->scene->cam.t.angle, r->scene->cam.m_rot_amt.x);
		cam_rot_x(&r->scene->cam, r->scene->cam.m_rot_amt.x);
		cam_update(&r->scene->cam);
	}
}