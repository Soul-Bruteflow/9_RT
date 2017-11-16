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

void	keyboard_core(t_rt *r)
  {
  	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_ESCAPE])
  		exit(0);
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
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_UP])
	{
		r->scene->cam.t.angle.y += r->scene->cam.rot_amt;
		r->scene->cam.t.angle.y = ft_clamp_f(r->scene->cam.t.angle.y, -900, 900);
		cam_rot_y(&r->scene->cam, r->scene->cam.t.angle.y);
		cam_update(&r->scene->cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_DOWN])
	{
		r->scene->cam.t.angle.y -= r->scene->cam.rot_amt;
		r->scene->cam.t.angle.y = ft_clamp_f(r->scene->cam.t.angle.y, -900, 900);
		cam_rot_y(&r->scene->cam, r->scene->cam.t.angle.y);
		cam_update(&r->scene->cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_LEFT])
	{
		r->scene->cam.t.angle.x += r->scene->cam.rot_amt;

		cam_rot_x(&r->scene->cam, -r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_RIGHT])
	{
		r->scene->cam.t.angle.x -= r->scene->cam.rot_amt;

		cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_Q])
	{
//	r->scene->cam.t.angle.x -= r->scene->cam.rot_amt;
//	cam_rot(&r->scene->cam);
		cam_rot_z(&r->scene->cam, -r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_E])
	{
//	r->scene->cam.t.angle.x -= r->scene->cam.rot_amt;
//	cam_rot(&r->scene->cam);
		cam_rot_z(&r->scene->cam, r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_SPACE])
	{
		int x, y = 0;

		SDL_GetRelativeMouseState(&x, &y);
		r->sdl->mouse_rpos.x = x;
		r->sdl->mouse_rpos.y = y * -1.0f;
//		printf("%f\n", r->sdl->mouse_rpos.x);
		if (r->sdl->mouse_rpos.x > 0)
		{
//			float tmp = r->scene->cam.rot_amt * r->sdl->mouse_rpos.x * 0.005f;
//			printf("%f\n", r->sdl->mouse_rpos.x);

			cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt * r->sdl->mouse_rpos.x * 0.008f);
			cam_update(&r->scene->cam);
//			printf("%f\n", r->sdl->mouse_rpos.x);
		}
		else if (r->sdl->mouse_rpos.x < 0)
		{
			cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt * r->sdl->mouse_rpos.x * 0.008f);
			cam_update(&r->scene->cam);
		}

		if (r->sdl->mouse_rpos.y > 0)
		{
//			float tmp = r->scene->cam.rot_amt * r->sdl->mouse_rpos.x * 0.005f;
// 			printf("%f\n", r->sdl->mouse_rpos.x);

			cam_rot_y(&r->scene->cam, r->scene->cam.rot_amt * r->sdl->mouse_rpos.y * 0.006f);
			cam_update(&r->scene->cam);
//			printf("%f\n", r->sdl->mouse_rpos.x);
		}
		else if (r->sdl->mouse_rpos.y < 0)
		{
			cam_rot_y(&r->scene->cam, r->scene->cam.rot_amt * r->sdl->mouse_rpos.y * 0.006f);
			cam_update(&r->scene->cam);
		}
//		  }
//		  printf("%f\n", r->sdl->mouse_rpos.x);
//		  printf("%f\n", r->sdl->mouse_rpos.y);
	  }
}
