#include "rt.h"

void    camera_rotation(t_rt *r)
{
	camera_vertical_rotation(r);
	camera_horizontal_rotation(r);
}

void    camera_vertical_rotation(t_rt *r)
{
	t_cam *cam;

	cam = &r->scene->cam;
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_UP])
	{
		if(handle_cam_y_pos_deg(&cam->t.angle, cam->rot_amt))
		{
			cam_rot_y(cam, -cam->rot_amt);
			cam_update(cam);
		}
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_DOWN])
	{
		if(handle_cam_y_neg_deg(&cam->t.angle, cam->rot_amt))
		{
			cam_rot_y(cam, cam->rot_amt);
			cam_update(cam);
		}
	}
}

void    camera_horizontal_rotation(t_rt *r)
{
	t_cam *cam;

	cam = &r->scene->cam;
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_LEFT])
	{
		handle_cam_x_neg_deg(&cam->t.angle, cam->rot_amt);
		cam_rot_x(cam, cam->rot_amt);
		cam_update(cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_RIGHT])
	{
		handle_cam_x_pos_deg(&cam->t.angle, cam->rot_amt);
		cam_rot_x(cam, -cam->rot_amt);
		cam_update(cam);
	}
}