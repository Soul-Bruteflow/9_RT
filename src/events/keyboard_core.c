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

#include "rtv.h"

void	keyboard_core(t_rtv *rtv)
  {
  	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_ESCAPE])
  		exit(0);
	if (rtv->sdl->event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (rtv->sdl->is_mouse_cap)
		{
//			SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", rtv->sdl->window);
			printf("123\n");
			rtv->sdl->is_mouse_cap = (SDL_bool)0;
			SDL_CaptureMouse(rtv->sdl->is_mouse_cap);
		}
		else
		{
			rtv->sdl->is_mouse_cap = (SDL_bool)1;
			SDL_CaptureMouse(rtv->sdl->is_mouse_cap);
		}
	}
 	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_W])
 	{
//		t_cylinder *c;
//		c = rtv->scene->objects[0]->type;
//		c->a.x += 50;
//		c->b.x += 50;

//		float t = vec3_dot(&rtv->scene->cam.eye, &rtv->scene->cam.d);

//		t_vec3d tmp = vec3_scale(10, &rtv->scene->cam.d);
//		rtv->scene->cam.eye = vec3_add(&rtv->scene->cam.eye, &tmp);
//		rtv->scene->cam.d = vec3_norm(rtv->scene->cam.eye);
//		rtv->scene->cam.eye.z += 0.04;

//		position += direction * speed
//		rtv->scene->cam.d.z

//		t_vec3d tmp = vec3_scale(rtv->scene->cam.mov_amt, &rtv->scene->cam.d);
//		rtv->scene->cam.eye = vec3_add(&rtv->scene->cam.eye, &tmp);

//		rtv->scene->cam.o.z += rtv->scene->cam.mov_amt;

		cam_move(&rtv->scene->cam.o, &rtv->scene->cam.eye, rtv->scene->cam.mov_amt);
		cam_update(&rtv->scene->cam, &rtv->scene->ray.start);

//		rtv->scene->cam.d.z += rtv->scene->cam.mov_amt;
//		init_camera(rtv);
		printf("%f\n", rtv->scene->cam.o.z);

		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_S])
	{
//		t_cylinder *c;
//		c = rtv->scene->objects[0]->type;
//		c->a.x -= 50;
//		c->b.x -= 50;
		cam_move(&rtv->scene->cam.o, &rtv->scene->cam.eye, -rtv->scene->cam.mov_amt);
		cam_update(&rtv->scene->cam, &rtv->scene->ray.start);
//		rtv->scene->cam.d = vec3_norm(rtv->scene->cam.eye);
//		rtv->scene->cam.eye.z -= 0.04;

		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_D])
	{
//		t_plane *p = rtv->scene->objects[0]->type;
//		p->normal.x += 50;

		rtv->scene->cam.eye.x -= rtv->scene->cam.rot_amt;
		vec3_norm(rtv->scene->cam.eye);
		cam_update(&rtv->scene->cam, &rtv->scene->ray.start);

		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_A])
	{
		rtv->scene->cam.eye.x += rtv->scene->cam.rot_amt;
		vec3_norm(rtv->scene->cam.eye);
		cam_update(&rtv->scene->cam, &rtv->scene->ray.start);
//		t_plane *p = rtv->scene->objects[0]->type;
//		p->normal.x -= 50;

		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_UP])
	{
		cam_rot_y(&rtv->scene->cam, rtv->scene->cam.rot_amt);
//		rtv->scene->cam.eye = vec3_rotate(rtv->scene->cam.rot_amt, &rtv->scene->cam.eye);
//		rtv->scene->cam.eye.x += rtv->scene->cam.rot_amt;
//		vec3_norm(rtv->scene->cam.eye);
		cam_update(&rtv->scene->cam, &rtv->scene->ray.start);

		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
}
