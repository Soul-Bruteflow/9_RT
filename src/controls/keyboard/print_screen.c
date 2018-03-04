/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruteflow <bruteflow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:56:30 by bruteflow         #+#    #+#             */
/*   Updated: 2018/03/04 19:59:43 by bruteflow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	screen_capture(SDL_Renderer *ren, const char *name, int wh[])
{
	SDL_Surface		*surf;
	int				st;
	Uint32			format;
	void			*pixels;

	format  = SDL_PIXELFORMAT_RGBA32;
	pixels = malloc(wh[0] * wh[1] * SDL_BYTESPERPIXEL(format));
	if (!pixels)
		rtv_error(print_screen_error);
	st = SDL_RenderReadPixels(ren, NULL,
	format, pixels, wh[0] * SDL_BYTESPERPIXEL(format));
	if (st != 0)
		rtv_error(print_screen_error);
	surf = SDL_CreateRGBSurfaceWithFormatFrom(pixels,
	wh[0], wh[1], SDL_BITSPERPIXEL(format),
	wh[0] * SDL_BYTESPERPIXEL(format), format);
	if (!surf)
		rtv_error(print_screen_error);
	st = IMG_SavePNG(surf, name);
	if (st != 0)
		rtv_error(print_screen_error);
	SDL_Log("Screen captured as PNG to \"%s\"\n", name);
}

void	print_screen(t_rt *r)
{
	int wh[2];

	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_P])
	{
		wh[0] = r->win->width;
		wh[1] = r->win->height;
		screen_capture(r->sdl->renderer, "image.png", wh);
	}
}