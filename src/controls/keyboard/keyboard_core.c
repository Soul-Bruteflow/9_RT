/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/18 17:13:12 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	camera_movement(t_rt *r)
{
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_W])
	{
		cam_move(&r->scene->cam, &r->scene->cam.forward, r->scene->cam.mov_amt);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_S])
	{
		cam_move(&r->scene->cam, &r->scene->cam.forward, -r->scene->cam.mov_amt);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_D])
	{
		cam_move(&r->scene->cam, &r->scene->cam.right, r->scene->cam.mov_amt);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_A])
	{
		cam_move(&r->scene->cam, &r->scene->cam.right, -r->scene->cam.mov_amt);
	}
}

void    camera_vertical_rotation(t_rt *r)
{
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_UP])
	{
		if(handle_cam_y_pos_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt))
		{
			cam_rot_y(&r->scene->cam, -r->scene->cam.rot_amt);
			cam_update(&r->scene->cam);
		}
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_DOWN])
	{
		if(handle_cam_y_neg_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt))
		{
			cam_rot_y(&r->scene->cam, r->scene->cam.rot_amt);
			cam_update(&r->scene->cam);
		}
	}
}

void    camera_horizontal_rotation(t_rt *r)
{
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_LEFT])
	{
		handle_cam_x_neg_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt);
		cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_RIGHT])
	{
		handle_cam_x_pos_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt);
		cam_rot_x(&r->scene->cam, -r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
}

void    camera_vertical_freelook(t_rt *r)
{
	if (r->sdl->mouse.rpos.y > 0)
	{
		if (r->scene->cam.t.angle.y > 87.00f)
			return;
		r->scene->cam.t.angle.y += r->scene->cam.m_rot_amt.y;
		cam_rot_y(&r->scene->cam, r->scene->cam.m_rot_amt.y);
		cam_update(&r->scene->cam);
	}
	if (r->sdl->mouse.rpos.y < 0)
	{
		if (r->scene->cam.t.angle.y < -87.00f)
			return;
		r->scene->cam.t.angle.y += r->scene->cam.m_rot_amt.y;
		cam_rot_y(&r->scene->cam, r->scene->cam.m_rot_amt.y);
		cam_update(&r->scene->cam);
	}
}

void    camera_horizontal_freelook(t_rt *r)
{
	if (r->sdl->mouse.rpos.x > 0)
	{
		handle_cam_x_pos_deg(&r->scene->cam.t.angle, r->scene->cam.m_rot_amt.x * -1);
		cam_rot_x(&r->scene->cam, r->scene->cam.m_rot_amt.x);
		cam_update(&r->scene->cam);
	}
	if (r->sdl->mouse.rpos.x < 0)
	{
		handle_cam_x_neg_deg(&r->scene->cam.t.angle, r->scene->cam.m_rot_amt.x);
		cam_rot_x(&r->scene->cam, r->scene->cam.m_rot_amt.x);
		cam_update(&r->scene->cam);
	}
}

void	keyboard_core(t_rt *r)
{
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
	camera_movement(r);
	camera_vertical_rotation(r);
	camera_horizontal_rotation(r);

	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_SPACE])
	{
		int x;
		int y;

		y = 0;
		x = 0;
		SDL_GetRelativeMouseState(&x, &y);
		r->sdl->mouse.rpos.y = ft_clamp_f(y, -250, 250);
		r->sdl->mouse.rpos.x = ft_clamp_f(x, -250, 250) * -1.0f;
		r->scene->cam.m_rot_amt.y = r->sdl->mouse.rpos.y * r->scene->cam.rot_amt * r->sdl->mouse.cam_sens.y;
		r->scene->cam.m_rot_amt.x = r->sdl->mouse.rpos.x * r->scene->cam.rot_amt * r->sdl->mouse.cam_sens.x;
		camera_horizontal_freelook(r);
		camera_vertical_freelook(r);
	}
}
