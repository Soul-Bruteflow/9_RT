/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:19:23 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:12:11 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** b, g, r, a
*/

void	ft_noise(t_rt *rt)
{
	Uint16	i;
	Uint16	x;
	Uint16	y;
	Uint32	offset;

	i = 0;
	while (i < 1000)
	{
		x = (Uint16)(rand() % rt->win->width);
		y = (Uint16)(rand() % rt->win->height);
		offset = (Uint32)((rt->win->width * 4 * y) + x * 4);
		rt->win->draw_buf[offset + 0] = (Uint8)(rand() % 256);
		rt->win->draw_buf[offset + 1] = (Uint8)(rand() % 256);
		rt->win->draw_buf[offset + 2] = (Uint8)(rand() % 256);
		rt->win->draw_buf[offset + 3] = SDL_ALPHA_OPAQUE;
		i++;
	}
}
