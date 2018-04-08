/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:48 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 15:28:02 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_mouse_sens(t_mouse *m, float x, float y)
{
	m->sens.x = x;
	m->sens.y = y;
}

void	set_mouse_cam_sens(t_mouse *m, float x, float y)
{
	m->cam_sens.x = x;
	m->cam_sens.y = y;
}

void	invert_mouse_x(t_mouse *m)
{
	m->rpos.x *= -1.0f;
}

void	invert_mouse_y(t_mouse *m)
{
	m->rpos.y *= -1.0f;
}
