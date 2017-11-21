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
//		printf("%f\n", r->scene->cam.t.angle.y);
		if(handle_cam_y_pos_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt))
		{
			cam_rot_y(&r->scene->cam, -r->scene->cam.rot_amt);
			cam_update(&r->scene->cam);
		}
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_DOWN])
	{
//		printf("%f\n", r->scene->cam.t.angle.y);
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
//		printf("%f\n", r->scene->cam.t.angle.x);
		handle_cam_x_neg_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt);
		cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
	if (SDL_KEYDOWN && r->sdl->key_state[SDL_SCANCODE_RIGHT])
	{
//		printf("%f\n", r->scene->cam.t.angle.x);
		handle_cam_x_pos_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt);
		cam_rot_x(&r->scene->cam, -r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
}

void    camera_vertical_freelook(t_rt *r)
{
	get_mouse_relative_position(&r->sdl->mouse);
	invert_mouse_x(&r->sdl->mouse);
//	r->scene->cam.m_rot_amt = r->scene->cam.rot_amt * r->sdl->mouse.rpos.y * r->sdl->mouse.cam_sens.y;
	printf("%f\n", r->sdl->mouse.rpos.y);
	if (r->sdl->mouse.rpos.y > 0)
	{
		if(handle_cam_y_pos_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt))
		{
			cam_rot_y(&r->scene->cam, r->scene->cam.rot_amt);
			cam_update(&r->scene->cam);
		}
// 		printf("%f\n", r->sdl->mouse_rpos.x);
	}
	else if (r->sdl->mouse.rpos.y < 0)
	{
		if(handle_cam_y_pos_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt))
		{
			cam_rot_y(&r->scene->cam, -r->scene->cam.rot_amt);
			cam_update(&r->scene->cam);
		}
	}
}

void    camera_horizontal_freelook(t_rt *r)
{
	get_mouse_relative_position(&r->sdl->mouse);
	invert_mouse_x(&r->sdl->mouse);
//	r->scene->cam.m_rot_amt = r->scene->cam.rot_amt * r->sdl->mouse.rpos.x * r->sdl->mouse.cam_sens.x;
//	printf("%f\n", r->sdl->mouse.rpos.x);
	if (r->sdl->mouse.rpos.x > 0)
	{
//		printf("%f\n", r->sdl->mouse_rpos.x);
		handle_cam_x_pos_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt);
		cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt);
		cam_update(&r->scene->cam);
	}
	else if (r->sdl->mouse.rpos.x < 0)
	{
		handle_cam_x_pos_deg(&r->scene->cam.t.angle, -r->scene->cam.rot_amt);
		cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt);
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
		int x, y = 0;

		x = 0;
		y = 0;
		SDL_GetRelativeMouseState(&x, &y);
		y = (int)ft_clamp_f(y, -350, 350);
//		r->sdl->mouse.rpos.x = x * -1.0f;
//		r->sdl->mouse.rpos.y = y;
//		if (r->sdl->mouse.rpos.x > 0)
//		{
//			cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt * r->sdl->mouse.rpos.x * 0.008f);
//			cam_update(&r->scene->cam);
//		}
//		else if (r->sdl->mouse.rpos.x < 0)
//		{
//			cam_rot_x(&r->scene->cam, r->scene->cam.rot_amt * r->sdl->mouse.rpos.x * 0.008f);
//			cam_update(&r->scene->cam);
//		}
////------------------------------------------------------------------------////
//		printf("%d\n", y);
		printf("%f\n", r->scene->cam.t.angle.y);
		if (y > 5)
		{
			if (r->scene->cam.t.angle.y > 87.0f)
				return;
			r->scene->cam.t.angle.y += r->scene->cam.rot_amt * (float)y * 0.006f;
//			if (r->scene->cam.t.angle.y > 87)
//			{
//				r->scene->cam.t.angle.y = ft_clamp_f(r->scene->cam.t.angle.y, -89, 89);
//				return;
//			}
//			printf("%f\n", r->scene->cam.t.angle.y);
//			if(handle_cam_y_pos_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt))
////			{
////			ft_clamp_f(r->scene->cam.t.angle.y, -90, 90);
			cam_rot_y(&r->scene->cam, r->scene->cam.rot_amt * (float)y * 0.006f);
			cam_update(&r->scene->cam);
////			}
		}


//		printf("%d\n", y);
		printf("%f\n", r->scene->cam.t.angle.y);
		if (y < -5)
		{
			if (r->scene->cam.t.angle.y < -87.0f)
				return;
			r->scene->cam.t.angle.y += r->scene->cam.rot_amt * (float)y * 0.006f;
//			if (r->scene->cam.t.angle.y < -87)
//			{
//				r->scene->cam.t.angle.y = ft_clamp_f(r->scene->cam.t.angle.y, -89, 89);
//				return;
//			}
//			printf("%f\n", r->scene->cam.t.angle.y);
//			if(handle_cam_y_neg_deg(&r->scene->cam.t.angle, r->scene->cam.rot_amt))
//			{
//			ft_clamp_f(r->scene->cam.t.angle.y, -90, 90);
			cam_rot_y(&r->scene->cam, r->scene->cam.rot_amt * (float)y * 0.006f);
			cam_update(&r->scene->cam);

//			}
		}
	}
}
