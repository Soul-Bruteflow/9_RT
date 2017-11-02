/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:18:31 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "utility/defines.h"

static t_bool	parse_lights_position(t_rtv *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->lits_n - 1)
	{
		if (check_line(r, "position:"))
		{
			if (!(parse_vector(r, &r->scene->lights[i]->pos, V_MIN, V_MAX)))
				return (false);
		}
		else
			return (false);
	}
	if (i != r->scene->lits_n)
		return (false);
	return (true);
}

static t_bool	parse_lights_color(t_rtv *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->lits_n - 1)
	{
		if (check_line(r, "color:"))
		{
			if (!(parse_color(r, &r->scene->lights[i]->color, C_MIN, C_MAX)))
				return (false);
		}
		else
			return (false);
	}
	if (i != r->scene->lits_n)
		return (false);
	return (true);
}

t_bool			parse_lights(t_rtv *r)
{
	if (!(parse_lights_position(r)))
		return (false);
	if (!(parse_lights_color(r)))
		return (false);
	return (true);
}
