/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:48 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 15:16:14 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	info_togle(t_rt *r)
{
	if (r->sdl->key_state[SDL_SCANCODE_I])
	{
		if (r->togle_info == true)
			r->togle_info = false;
		else
			r->togle_info = true;
		rt_render(r);
	}
}
