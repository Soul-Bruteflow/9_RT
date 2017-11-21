#include "rt.h"

void	mouse_core(t_rt *rt)
{
	if (rt->sdl->event.type == SDL_MOUSEMOTION)
	{
	}
	if (rt->sdl->event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (rt->sdl->event.button.button == SDL_BUTTON_LEFT)
		{
		}
	}
}
