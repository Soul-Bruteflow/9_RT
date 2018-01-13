/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:11:47 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** 0 - blue, 1 - green, 2 - red, 3 - alpha;
*/

void	ft_draw_pixel(Uint16 x, Uint16 y, t_rgba *color, Uint8 *draw_buffer)
{
	Uint32	offset;

	if (x >= 0 && x <= WIDTH - 1 && y >= 0 && y <= HEIGHT - 1)
	{
		offset = (Uint32)((WIDTH * BITS * y) + x * BITS);
		draw_buffer[offset + 0] = color->blue;
		draw_buffer[offset + 1] = color->green;
		draw_buffer[offset + 2] = color->red;
		draw_buffer[offset + 3] = color->alpha;
	}
}
