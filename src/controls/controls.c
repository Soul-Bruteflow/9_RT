/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:48 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 15:29:55 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_controls(t_rt *r)
{
	set_mouse_cam_sens(&r->sdl->mouse, H_C_SENS, V_C_SENS);
	set_mouse_sens(&r->sdl->mouse, H_SENS, V_SENS);
}
