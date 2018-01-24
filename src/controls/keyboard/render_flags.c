#include "rt.h"

static void		ft_refl_refr(t_rt *rt)
{
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_MINUS])
	{
		if (rt->scene->max_level_reflection > 0)
			rt->scene->max_level_reflection--;
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_EQUALS])
	{
		if (rt->scene->max_level_reflection < 10)
			rt->scene->max_level_reflection++;
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_LEFTBRACKET])
	{
		if (rt->scene->max_level_transparent > 0)
			rt->scene->max_level_transparent--;
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_RIGHTBRACKET])
	{
		if (rt->scene->max_level_transparent < 10)
			rt->scene->max_level_transparent++;
	}
}

static void		ft_aa(t_rt *rt)
{
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_COMMA])
	{
		if (rt->scene->aa > 1)
			rt->scene->aa--;
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_PERIOD])
	{
		if (rt->scene->aa < 4)
			rt->scene->aa++;
	}
}

void			render_flags(t_rt *rt)
{
	ft_aa(rt);
	ft_refl_refr(rt);
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_SEMICOLON])
		rt->scene->status_shadow =
			(rt->scene->status_shadow == true) ? false : true;
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_APOSTROPHE])
		rt->scene->status_glossy =
			(rt->scene->status_glossy == true) ? false : true;
}