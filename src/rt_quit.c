/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:04:47 by mvlad             #+#    #+#             */
/*   Updated: 2018/03/30 20:59:23 by vholovin         ###   ########.fr       */
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
