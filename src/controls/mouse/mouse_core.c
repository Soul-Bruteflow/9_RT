#include "rt.h"

void	get_mouse_relative_position(t_vec2 *rpos)
{
	int x;
	int y;

	x = 0;
	y = 0;
	SDL_GetRelativeMouseState(&x, &y);
	rpos->x = x;
	rpos->y = y;
}

void	mouse_invert_x(t_vec2 *rpos)
{
	rpos->x *= -1.0f;
}

void	mouse_invert_y(t_vec2 *rpos)
{
	rpos->y *= -1.0f;
}

void	mouse_core(t_rt *rt)
{
	int x;
	int y;

	if (rt->sdl->event.type == SDL_MOUSEMOTION)
	{
		SDL_GetRelativeMouseState(&x,&y);
		rt->sdl->mouse_rpos.x = x;
		rt->sdl->mouse_rpos.y = y;
//		printf("%f, %f\n", rt->sdl->mouse_rpos.x, rt->sdl->mouse_rpos.y);


	}
//	printf("%f, %f\n", rt->sdl->mouse_rpos.x, rt->sdl->mouse_rpos.y);
	if (rt->sdl->event.type == SDL_MOUSEBUTTONDOWN)
	{
//		if (rt->sdl->is_mouse_cap)
		if (rt->sdl->event.button.button == SDL_BUTTON_LEFT)
		{
//			SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", rt->sdl->window);
//			printf("%f, %f\n", rt->sdl->mouse_rpos.x, rt->sdl->mouse_rpos.y);
//			rt->sdl->is_mouse_cap = (SDL_bool)0;
//			SDL_CaptureMouse(rt->sdl->is_mouse_cap);
		}
//		else
//		{
//			rt->sdl->is_mouse_cap = (SDL_bool)1;
//			SDL_CaptureMouse(rt->sdl->is_mouse_cap);
//		}
	}
}
