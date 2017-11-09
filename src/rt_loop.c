/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_loop.c                                         :+:      :+:    :+:   */
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

static void	update_time(t_rt *rt)
{
	char	*tmp;

	rt->delta.oldtime = rt->delta.curtime;
	rt->delta.curtime = SDL_GetTicks();
	rt->delta.ftime = (rt->delta.curtime - rt->delta.oldtime) / 1000.0f;
	rt->scene->cam.mov_amt = (float)rt->delta.ftime * 350.0f;
	rt->scene->cam.rot_amt = (float)rt->delta.ftime * 0.1f;
	if (rt->delta.fps_counter % 10 == 0)
	{
		tmp = ft_itoa((int)(1.0 / rt->delta.ftime));
		rt->delta.fps[0] = tmp[0];
		rt->delta.fps[1] = tmp[1];
		rt->delta.fps[2] = tmp[2];
		rt->delta.fps[3] = '\0';
		free(tmp);
	}
	rt->delta.fps_counter++;
}

void	rt_loop(t_rt *rt)
{
	rt->delta.curtime = SDL_GetTicks();
	while ((running(&rt->sdl->event, &rt->sdl->key_state)))
	{
		update_time(rt);
		keyboard_core(rt);
		mouse_core(rt);

//		clear_window(rt);
//		raytrace(rt);
//		render_present(rt);
	}
}
