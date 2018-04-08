/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2018/03/31 15:19:09 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sdl_exit(t_rt *r)
{
	if (r->sdl->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
}

void	keyboard_core(t_rt *r)
{
	sdl_exit(r);
	camera_movement(r);
	camera_rotation(r);
	camera_freelook(r);
	render_flags(r);
	print_screen(r);
	info_togle(r);
}
