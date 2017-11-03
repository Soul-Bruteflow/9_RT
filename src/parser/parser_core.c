/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:47:12 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:14:57 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool	parser_core(t_rtv *r)
{
	open_file(r);
	if (!(check_line(r, "scene:")))
		return (false);
	if (!(parse_scene(r)))
		return (false);
	create_scene(r);
	if (!(check_line(r, "camera:")))
		return (false);
	if (!(parse_camera(r)))
		return (false);
	if (!(check_line(r, "lights:")))
		return (false);
	if (!(parse_lights(r)))
		return (false);
	if (!(check_line(r, "materials:")))
		return (false);
	if (!(parse_materials(r)))
		return (false);
	if (!(check_line(r, "objects:")))
		return (false);
	if (!(parse_objects(r)))
		rtv_error(parse_error);
	gnl_error(r, r->pars->n);
	close_file(r);
	return (true);
}
