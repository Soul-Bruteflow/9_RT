/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:07:08 by vholovin          #+#    #+#             */
/*   Updated: 2018/04/03 14:07:24 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool		parse_lights(t_rt *r)
{
	if (r->scene->lits_n == 0)
		return (true);
	if (!(parse_lights_type(r)))
		return (false);
	if (!(parse_lights_position(r)))
		return (false);
	if (!(parse_lights_direction(r)))
		return (false);
	if (!(parse_lights_angle(r)))
		return (false);
	if (!(parse_lights_len(r)))
		return (false);
	if (!(parse_lights_power(r)))
		return (false);
	if (!(parse_lights_color(r)))
		return (false);
	return (true);
}
