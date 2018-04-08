/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:48 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 15:31:03 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	create_info_text(t_rt *r)
{
	TTF_Init();
	r->font = TTF_OpenFont("./info/Fontin-Regular.ttf", 15);
	r->fcolor.r = 255;
	r->fcolor.g = 255;
	r->fcolor.b = 255;
	r->message_rect.x = 25;
	r->message_rect.y = (HEIGHT - r->h) + 5;
}

static void	create_background(t_rt *r)
{
	r->img = IMG_LoadTexture(r->sdl->renderer,
		"./info/backgound_info.png");
	SDL_QueryTexture(r->img, NULL, NULL, &r->w, &r->h);
	r->texr.x = 0;
	r->texr.y = (HEIGHT - r->h);
	r->texr.w = r->w * 1;
	r->texr.h = r->h * 1;
}

void		init_gui(t_rt *r)
{
	r->togle_info = false;
	create_background(r);
	create_info_text(r);
}
