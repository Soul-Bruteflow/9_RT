/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:08:03 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool	running(SDL_Event *event, const Uint8 **key_state)
{
	SDL_Delay(1);
	SDL_PollEvent(event);
	if (event->type == SDL_QUIT)
		return (false);
	*key_state = SDL_GetKeyboardState(NULL);
	return (true);
}

static void	update_time(t_rtv *rtv)
{
	char	*tmp;

	rtv->delta.old_time = rtv->delta.time;
	rtv->delta.time = SDL_GetTicks();
	rtv->delta.frame_time = (rtv->delta.time - rtv->delta.old_time) / 1000.0f;
	rtv->scene->cam.mov_amt = rtv->delta.frame_time * 350.0f;
	rtv->scene->cam.rot_amt = rtv->delta.frame_time * 0.03f;
	if (rtv->delta.fps_counter % 10 == 0)
	{
		tmp = ft_itoa((int)(1.0 / rtv->delta.frame_time));
		rtv->delta.fps[0] = tmp[0];
		rtv->delta.fps[1] = tmp[1];
		rtv->delta.fps[2] = tmp[2];
		rtv->delta.fps[3] = '\0';
		free(tmp);
	}
	rtv->delta.fps_counter++;
}

void	rtv_loop(t_rtv *rtv)
{
	while ((running(&rtv->sdl->event, &rtv->sdl->key_state)))
	{
//		if (rtv->sdl->event.type == SDL_QUIT)
//		{
//			/* Quit the application */
//			exit(1);
//		}
//
//		/* If a button on the mouse is pressed. */
//		if (rtv->sdl->event.type == SDL_MOUSEBUTTONDOWN)
//		{
//			/* If the left button was pressed. */
//			if (rtv->sdl->event.button.button == SDL_BUTTON_LEFT)
//				/* Quit the application */
//				exit(1);
//		}
		update_time(rtv);
		keyboard_core(rtv);
//		clear_window(rtv);
//		raytrace(rtv);
//		render_present(rtv);
	}
}
