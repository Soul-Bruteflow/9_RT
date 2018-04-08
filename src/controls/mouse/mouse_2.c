/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:48 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 15:29:10 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_mouse_relative_position(t_mouse *m)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	SDL_GetRelativeMouseState(&x, &y);
	m->rpos.x = x;
	m->rpos.y = y;
}

void	clamp_mouse_rel_pos(t_mouse *m, float lower, float upper)
{
	m->rpos.y = ft_clamp_f(m->rpos.y, lower, upper);
	m->rpos.x = ft_clamp_f(m->rpos.x, lower, upper);
}

void	calc_mouse_rot_amt(t_mouse *m, t_cam *c)
{
	c->m_rot_amt.y = m->rpos.y * c->rot_amt * m->cam_sens.y;
	c->m_rot_amt.x = m->rpos.x * c->rot_amt * m->cam_sens.x;
}
