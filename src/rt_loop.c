/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:08:03 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool	running(SDL_Event *event, const Uint8 **key_state)
{
	SDL_Delay(1);
	SDL_PollEvent(event);

	if (event->type == SDL_QUIT)
		return (false);
	*key_state = SDL_GetKeyboardState(NULL);

	return (true);
}

static void	update_time(t_rt *rt)
{
	char	*tmp;

	rt->delta.oldtime = rt->delta.curtime;
	rt->delta.curtime = SDL_GetTicks();
	rt->delta.ftime = (rt->delta.curtime - rt->delta.oldtime) / 1000.0f;
	rt->scene->cam.mov_amt = (float)rt->delta.ftime * 350.0f;
	rt->scene->cam.rot_amt = (float)rt->delta.ftime * 0.1f;
	if (rt->delta.fps_counter % 10 == 0)
	{
		tmp = ft_itoa((int)(1.0 / rt->delta.ftime));
		rt->delta.fps[0] = tmp[0];
		rt->delta.fps[1] = tmp[1];
		rt->delta.fps[2] = tmp[2];
		rt->delta.fps[3] = '\0';
		free(tmp);
	}
	rt->delta.fps_counter++;
}

void	rt_loop(t_rt *rt)
{
	rt->delta.curtime = SDL_GetTicks();
	while ((running(&rt->sdl->event, &rt->sdl->key_state)))
	{
//		if (rt->sdl->event.type == SDL_QUIT)
//		{
//			/* Quit the application */
//			exit(1);
//		}
//
//		/* If a button on the mouse is pressed. */
//		if (rt->sdl->event.type == SDL_MOUSEBUTTONDOWN)
//		{
//			/* If the left button was pressed. */
//			if (rt->sdl->event.button.button == SDL_BUTTON_LEFT)
//				/* Quit the application */
//				exit(1);
//		}
//		SDL_WarpMouseInWindow(rt->sdl->window, WIDTH / 2, HEIGHT / 2);
		if ((rt->sdl->mouse_rel_pos.x && rt->sdl->mouse_rel_pos.y != 0) &&
		(rt->sdl->mouse_rel_pos.x && rt->sdl->mouse_rel_pos.y != 1))
		{
			printf("%f, %f\n", rt->sdl->mouse_rel_pos.x, rt->sdl->mouse_rel_pos.y);
		}
		update_time(rt);
		keyboard_core(rt);
		mouse_core(rt);

//		int x;
//		int y;
//		x = 0;
//		y = 0;
//		SDL_GetMouseState(&x, &y);
//		rt->sdl->mouse_rel_pos.x = x;
//		rt->sdl->mouse_rel_pos.y = y;
//		rt->scene->cam.horiz_angle = 3.14f;
//		rt->scene->cam.verti_angle = 0;

//		clear_window(rt);
//		raytrace(rt);
//		render_present(rt);

//		rt->scene->cam.horiz_angle += rt->scene->cam.mouse_speed * rt->delta.time * WIDTH / 2 - rt->sdl->mouse_rel_pos.x;
//		rt->scene->cam.verti_angle += rt->scene->cam.mouse_speed * rt->delta.time * HEIGHT / 2 - rt->sdl->mouse_rel_pos.y;
//
//		rt->scene->cam.dir.x = cosf(rt->scene->cam.verti_angle) * sinf(rt->scene->cam.horiz_angle);
//		rt->scene->cam.dir.y = sinf(rt->scene->cam.verti_angle);
//		rt->scene->cam.dir.z = cosf(rt->scene->cam.verti_angle) * cosf(rt->scene->cam.verti_angle);
//		rt->scene->cam.dir = vec3_norm(rt->scene->cam.dir);
//
//		rt->scene->cam.right.x = sinf(rt->scene->cam.horiz_angle - 3.14f/2.0f);
//		rt->scene->cam.right.y = 0;
//		rt->scene->cam.right.z = cosf(rt->scene->cam.horiz_angle - 3.14f/2.0f);
//		rt->scene->cam.right = vec3_norm(rt->scene->cam.right);
//
//		rt->scene->cam.up = vec3_cross(&rt->scene->cam.right, &rt->scene->cam.dir);
//		rt->scene->cam.up = vec3_norm(rt->scene->cam.up);
//
//		printf("%f, %f, %f \n", rt->scene->cam.dir.x, rt->scene->cam.dir.y, rt->scene->cam.dir.z);
//
//		SDL_WarpMouseInWindow(rt->sdl->window, WIDTH / 2, HEIGHT / 2);
//		rt->sdl->mouse_rel_pos.x = WIDTH / 2;
//		rt->sdl->mouse_rel_pos.y = HEIGHT / 2;

//		printf("%f, %f \n", rt->sdl->mouse_rel_pos.x, rt->sdl->mouse_rel_pos.y);
	}
//	printf("%f, %f \n", rt->sdl->mouse_rel_pos.x, rt->sdl->mouse_rel_pos.y);
}
