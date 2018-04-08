/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:48 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 15:26:36 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_refl_refr(t_rt *rt)
{
	if (rt->sdl->key_state[SDL_SCANCODE_MINUS])
	{
		if (rt->scene->max_level_reflection > 0)
			rt->scene->max_level_reflection--;
		rt_render(rt);
	}
	if (rt->sdl->key_state[SDL_SCANCODE_EQUALS])
	{
		if (rt->scene->max_level_reflection < 10)
			rt->scene->max_level_reflection++;
		rt_render(rt);
	}
	if (rt->sdl->key_state[SDL_SCANCODE_LEFTBRACKET])
	{
		if (rt->scene->max_level_transparent > 0)
			rt->scene->max_level_transparent--;
		rt_render(rt);
	}
	if (rt->sdl->key_state[SDL_SCANCODE_RIGHTBRACKET])
	{
		if (rt->scene->max_level_transparent < 10)
			rt->scene->max_level_transparent++;
		rt_render(rt);
	}
}

static void		ft_aa(t_rt *rt)
{
	if (rt->sdl->key_state[SDL_SCANCODE_COMMA])
	{
		if (rt->scene->aa > 1)
			rt->scene->aa--;
		rt_render(rt);
	}
	if (rt->sdl->key_state[SDL_SCANCODE_PERIOD])
	{
		if (rt->scene->aa < 4)
			rt->scene->aa++;
		rt_render(rt);
	}
}

static void		ft_color(t_rt *rt)
{
	if (rt->sdl->key_state[SDL_SCANCODE_C])
	{
		rt->scene->status_color++;
		rt->scene->status_color =
			(rt->scene->status_color == 4) ? 0 : rt->scene->status_color;
		rt_render(rt);
	}
}

void			render_flags(t_rt *rt)
{
	ft_color(rt);
	ft_aa(rt);
	ft_refl_refr(rt);
	if (rt->sdl->key_state[SDL_SCANCODE_SEMICOLON])
		rt->scene->status_shadow =
			(rt->scene->status_shadow == true) ? false : true;
	if (rt->sdl->key_state[SDL_SCANCODE_APOSTROPHE])
		rt->scene->status_glossy =
			(rt->scene->status_glossy == true) ? false : true;
	if (rt->sdl->key_state[SDL_SCANCODE_T])
		rt->scene->status_texture =
			(rt->scene->status_texture == true) ? false : true;
	if (rt->sdl->key_state[SDL_SCANCODE_SEMICOLON]
			|| rt->sdl->key_state[SDL_SCANCODE_APOSTROPHE]
			|| rt->sdl->key_state[SDL_SCANCODE_T])
		rt_render(rt);
}
