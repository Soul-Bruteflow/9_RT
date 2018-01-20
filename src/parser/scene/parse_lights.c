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

#include "rt.h"

static t_bool	parse_lights_type(t_rt *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->lits_n - 1)
	{
		if (check_line(r, "type:"))
		{
			if (!(parse_number(r, &r->scene->lights[i]->type, 0, 3)))
				return (false);
		}
		else
			return (false);
	}
	if (i != r->scene->lits_n)
		return (false);
	return (true);
}

static t_bool	parse_lights_position(t_rt *r)
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

static t_bool	parse_lights_direction(t_rt *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->lits_n - 1)
	{
		if (check_line(r, "direction:"))
		{
			if (!(parse_float_number(r, &r->scene->lights[i]->dir.x, -1.0f, 1.0f)))
				return (false);
			if (!(parse_float_number(r, &r->scene->lights[i]->dir.y, -1.0f, 1.0f)))
				return (false);
			if (!(parse_float_number(r, &r->scene->lights[i]->dir.z, -1.0f, 1.0f)))
				return (false);
		}
		else
			return (false);
	}
	if (i != r->scene->lits_n)
		return (false);
	return (true);
}

static t_bool	parse_lights_angle(t_rt *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->lits_n - 1)
	{
		if (check_line(r, "angle:"))
		{
			if (!(parse_number(r, &r->scene->lights[i]->angle, 0, 180)))
				return (false);
		}
		else
			return (false);
	}
	if (i != r->scene->lits_n)
		return (false);
	return (true);
}

static t_bool	parse_lights_power(t_rt *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->lits_n - 1)
	{
		if (check_line(r, "power:"))
		{
			if (!(parse_float_number(r, &r->scene->lights[i]->power, P_MIN, P_MAX)))
				return (false);
		}
		else
			return (false);
	}
	if (i != r->scene->lits_n)
		return (false);
	return (true);
}

static t_bool	parse_lights_color(t_rt *r)
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

t_bool			parse_lights(t_rt *r)
{
	if (!(parse_lights_type(r)))
		return (false);
	if (!(parse_lights_position(r)))
		return (false);
	if (!(parse_lights_direction(r)))
		return (false);
	if (!(parse_lights_angle(r)))
		return (false);
	if (!(parse_lights_power(r)))
		return (false);
	if (!(parse_lights_color(r)))
		return (false);
	return (true);
}
