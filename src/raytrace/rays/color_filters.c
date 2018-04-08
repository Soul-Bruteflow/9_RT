/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_filters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:29:30 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 22:02:30 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_carton(t_rgbap *color)
{
	color->red = ((int)(color->red * 10.0f)) / 10.0f;
	color->green = ((int)(color->green * 10.0f)) / 10.0f;
	color->blue = ((int)(color->blue * 10.0f)) / 10.0f;
}

static void	set_sepia(t_rgbap *color)
{
	float	sum;

	sum = (color->red + color->green + color->blue) / 3.0f;
	color->red = sum + 0.2f;
	color->green = sum + 0.1f;
	color->blue = sum;
}

static void	set_bw(t_rgbap *color)
{
	float	sum;

	sum = (color->red + color->green + color->blue) / 3.0f;
	color->red = sum;
	color->green = sum;
	color->blue = sum;
}

void		color_filters(t_rgbap *color, int status_color)
{
	if (status_color == 1)
		set_carton(color);
	else if (status_color == 2)
		set_sepia(color);
	else if (status_color == 3)
		set_bw(color);
}
