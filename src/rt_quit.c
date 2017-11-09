/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:04:47 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:08:16 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Release resources and quit.
*/

void	rt_quit(t_rt *rt)
{
	SDL_DestroyTexture(rt->win->screen);
	SDL_DestroyRenderer(rt->sdl->renderer);
	SDL_DestroyWindow(rt->sdl->window);
	SDL_Quit();
}
