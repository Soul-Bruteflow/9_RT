/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:08:03 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool		running(SDL_Event *event, const Uint8 **key_state, t_sdl *s)
{
	(void)s;
	SDL_Delay(1);
	SDL_PollEvent(event);
	if (event->type == SDL_QUIT)
		return (false);
	*key_state = SDL_GetKeyboardState(NULL);
	return (true);
}

static void	update_time(t_rt *r)
{
	r->delta.oldtime = r->delta.curtime;
	r->delta.curtime = SDL_GetTicks();
	r->delta.ftime = (r->delta.curtime - r->delta.oldtime) / 2.0f;
	r->scene->cam.mov_amt = (float)r->delta.ftime * 1.0f;
	r->scene->cam.rot_amt = (float)r->delta.ftime * 0.025f;
}

void		rt_loop(t_rt *r)
{
	unsigned i;

	i = 0;
	r->delta.curtime = SDL_GetTicks();
	r->delta.fps_counter = 0;
	while ((running(&r->sdl->event, &r->sdl->key_state, r->sdl)))
	{
		update_time(r);
		keyboard_core(r);
		mouse_core(r);
		if (i++ <= 0)
			rt_render(r);
	}
}
