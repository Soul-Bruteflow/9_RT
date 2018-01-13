#include "rt.h"

void	camera_movement(t_rt *r)
{
	t_cam *cam;

	cam = &r->scene->cam;
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_W])
	{
		cam_move(cam, &cam->forward, cam->mov_amt);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_S])
	{
		cam_move(cam, &cam->forward, -cam->mov_amt);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_D])
	{
		cam_move(cam, &cam->right, cam->mov_amt);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_A])
	{
		cam_move(cam, &cam->right, -cam->mov_amt);
	}
}