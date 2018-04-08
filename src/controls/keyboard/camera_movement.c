/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:48 by vvlasenk          #+#    #+#             */
/*   Updated: 2018/03/31 15:18:16 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	camera_movement(t_rt *r)
{
	t_cam *cam;

	cam = &r->scene->cam;
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_W])
	{
		cam_move(cam, &cam->forward, cam->mov_amt);
		rt_render(r);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_S])
	{
		cam_move(cam, &cam->forward, -cam->mov_amt);
		rt_render(r);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_D])
	{
		cam_move(cam, &cam->right, cam->mov_amt);
		rt_render(r);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_A])
	{
		cam_move(cam, &cam->right, -cam->mov_amt);
		rt_render(r);
	}
}
