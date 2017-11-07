/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:08:03 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool	running(SDL_Event *event, const Uint8 **key_state, t_rtv *r)
{
	SDL_Delay(1);
	SDL_PollEvent(event);

	if (event->type == SDL_QUIT)
		return (false);
	*key_state = SDL_GetKeyboardState(NULL);

	return (true);
}

static void	update_time(t_rtv *rtv)
{
	char	*tmp;

	rtv->delta.oldtime = rtv->delta.curtime;
	rtv->delta.curtime = SDL_GetTicks();
	rtv->delta.ftime = (rtv->delta.curtime - rtv->delta.oldtime) / 1000.0f;
	rtv->scene->cam.mov_amt = rtv->delta.ftime * 350.0f;
	rtv->scene->cam.rot_amt = rtv->delta.ftime * 0.1f;
	if (rtv->delta.fps_counter % 10 == 0)
	{
		tmp = ft_itoa((int)(1.0 / rtv->delta.ftime));
		rtv->delta.fps[0] = tmp[0];
		rtv->delta.fps[1] = tmp[1];
		rtv->delta.fps[2] = tmp[2];
		rtv->delta.fps[3] = '\0';
		free(tmp);
	}
	rtv->delta.fps_counter++;
}

void	rtv_loop(t_rtv *rtv)
{
	rtv->delta.curtime = SDL_GetTicks();
	while ((running(&rtv->sdl->event, &rtv->sdl->key_state, rtv)))
	{
//		if (rtv->sdl->event.type == SDL_QUIT)
//		{
//			/* Quit the application */
//			exit(1);
//		}
//
//		/* If a button on the mouse is pressed. */
//		if (rtv->sdl->event.type == SDL_MOUSEBUTTONDOWN)
//		{
//			/* If the left button was pressed. */
//			if (rtv->sdl->event.button.button == SDL_BUTTON_LEFT)
//				/* Quit the application */
//				exit(1);
//		}
		update_time(rtv);
		keyboard_core(rtv);

//		int x;
//		int y;
//		x = 0;
//		y = 0;
//		SDL_GetMouseState(&x, &y);
//		rtv->sdl->mouse_pos.x = x;
//		rtv->sdl->mouse_pos.y = y;
//		rtv->scene->cam.horiz_angle = 3.14f;
//		rtv->scene->cam.verti_angle = 0;

//		clear_window(rtv);
//		raytrace(rtv);
//		render_present(rtv);

//		rtv->scene->cam.horiz_angle += rtv->scene->cam.mouse_speed * rtv->delta.time * WIDTH / 2 - rtv->sdl->mouse_pos.x;
//		rtv->scene->cam.verti_angle += rtv->scene->cam.mouse_speed * rtv->delta.time * HEIGHT / 2 - rtv->sdl->mouse_pos.y;
//
//		rtv->scene->cam.dir.x = cosf(rtv->scene->cam.verti_angle) * sinf(rtv->scene->cam.horiz_angle);
//		rtv->scene->cam.dir.y = sinf(rtv->scene->cam.verti_angle);
//		rtv->scene->cam.dir.z = cosf(rtv->scene->cam.verti_angle) * cosf(rtv->scene->cam.verti_angle);
//		rtv->scene->cam.dir = vec3_norm(rtv->scene->cam.dir);
//
//		rtv->scene->cam.right.x = sinf(rtv->scene->cam.horiz_angle - 3.14f/2.0f);
//		rtv->scene->cam.right.y = 0;
//		rtv->scene->cam.right.z = cosf(rtv->scene->cam.horiz_angle - 3.14f/2.0f);
//		rtv->scene->cam.right = vec3_norm(rtv->scene->cam.right);
//
//		rtv->scene->cam.up = vec3_cross(&rtv->scene->cam.right, &rtv->scene->cam.dir);
//		rtv->scene->cam.up = vec3_norm(rtv->scene->cam.up);
//
//		printf("%f, %f, %f \n", rtv->scene->cam.dir.x, rtv->scene->cam.dir.y, rtv->scene->cam.dir.z);
//
//		SDL_WarpMouseInWindow(rtv->sdl->window, WIDTH / 2, HEIGHT / 2);
//		rtv->sdl->mouse_pos.x = WIDTH / 2;
//		rtv->sdl->mouse_pos.y = HEIGHT / 2;

//		printf("%f, %f \n", rtv->sdl->mouse_pos.x, rtv->sdl->mouse_pos.y);
	}
//	printf("%f, %f \n", rtv->sdl->mouse_pos.x, rtv->sdl->mouse_pos.y);
}
