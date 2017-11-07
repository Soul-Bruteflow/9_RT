/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:47:10 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Clears screen.
** Sets render draw color to black and clears the window with it.
*/

void	clear_window(t_rt *rtv)
{
	SDL_SetRenderDrawColor(rtv->sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(rtv->sdl->renderer);
}

/*
** Renders to the window, everything that was drawn before in the back buffer.
*/

void	render_present(t_rt *rtv)
{
	SDL_UpdateTexture(rtv->win->screen, NULL, &rtv->win->draw_buf[0], WIDTH * 4);
	SDL_RenderCopy(rtv->sdl->renderer, rtv->win->screen, NULL, NULL);
	SDL_RenderPresent(rtv->sdl->renderer);
	bzero(rtv->win->draw_buf, WIDTH * HEIGHT * 4);
}
