#include "rt.h"

void	info_togle(t_rt *r)
{
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_I])
	{
		if (r->togle_info == true)
			r->togle_info = false;
		else
			r->togle_info = true;
	}
}
