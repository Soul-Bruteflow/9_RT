/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:47:07 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	create_buffer(Uint8 **draw_buffer, Uint16 width, Uint16 height)
{
	if (*draw_buffer == NULL)
	{
		*draw_buffer = (Uint8*)malloc(sizeof(Uint8) * width * height * 4);
		if (*draw_buffer == NULL)
			rtv_error(malloc_error);
	}
}

static void	set_window_size(t_rt *rtv, Uint16 width, Uint16 height)
{
	rtv->win->width = width;
	rtv->win->height = height;
	create_buffer(&rtv->win->draw_buf, width, height);
}

void		create_window(t_rt *r, Uint16 wdth, Uint16 hght, const char *title)
{
	set_window_size(r, wdth, hght);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		rtv_error(sdl_init_error);
	r->sdl->window = SDL_CreateWindow(title,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			r->win->width, r->win->height, SDL_WINDOW_OPENGL);
	if (r->sdl->window == NULL)
		rtv_error(sdl_window_error);
	r->sdl->renderer = SDL_CreateRenderer(r->sdl->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (r->sdl->renderer == NULL)
		rtv_error(sdl_renderer_error);
	r->win->screen = SDL_CreateTexture(r->sdl->renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
			r->win->width, r->win->height);

	SDL_SetRelativeMouseMode(SDL_TRUE);
//	SDL_ShowCursor(0);
//	SDL_SetWindowGrab(r->sdl->window, SDL_TRUE);
}
