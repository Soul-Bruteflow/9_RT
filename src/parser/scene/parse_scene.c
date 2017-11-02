/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:18:11 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "utility/defines.h"

t_bool	parse_scene(t_rtv *r)
{
	float n;

	if (!(check_line(r, "lights:")))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
		return (false);
	r->scene->lits_n = (Uint8)n;
	if (!(check_line(r, "materials:")))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
		return (false);
	r->scene->mats_n = (Uint8)n;
	if (!(check_line(r, "objects:")))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
		return (false);
	r->scene->objs_n = (Uint8)n;
	return (true);
}
