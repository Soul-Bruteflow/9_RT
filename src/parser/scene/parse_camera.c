/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:17:33 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "rt/defines.h"

t_bool	parse_camera(t_rtv *r)
{
	float n;

	if (!(check_line(r, "camera position:")))
		return (false);
	if (!(parse_vector(r, &r->scene->cam.pos, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "camera direction:")))
		return (false);
	if (!(parse_vector(r, &r->scene->cam.dir, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "fov:")))
		return (false);
	if (!(parse_number(r, &n, F_MIN, F_MAX)))
		return (false);
	r->scene->cam.fov = n;
	return (true);
}
