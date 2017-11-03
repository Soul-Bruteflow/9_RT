/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_quit.c                                         :+:      :+:    :+:   */
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

void	rtv_quit(t_rtv *rtv)
{
	SDL_DestroyTexture(rtv->win->screen);
	SDL_DestroyRenderer(rtv->sdl->renderer);
	SDL_DestroyWindow(rtv->sdl->window);
	SDL_Quit();
}
