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

void	keyboard_core(t_rt *rt)
  {
  	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_ESCAPE])
  		exit(0);
 	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_W])
 	{
		cam_move(&rt->scene->cam, &rt->scene->cam.dir, rt->scene->cam.mov_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		clear_window(rt);
//		raytrace(rt);
//		render_present(rt);
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_S])
	{
		cam_move(&rt->scene->cam, &rt->scene->cam.dir, -rt->scene->cam.mov_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		clear_window(rt);
//		raytrace(rt);
//		render_present(rt);
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_D])
	{
		cam_move(&rt->scene->cam, &rt->scene->cam.right, rt->scene->cam.mov_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		clear_window(rt);
//		raytrace(rt);
//		render_present(rt);
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_A])
	{
		cam_move(&rt->scene->cam, &rt->scene->cam.right, -rt->scene->cam.mov_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		clear_window(rt);
//		raytrace(rt);
//		render_present(rt);
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_UP])
	{
//		t_vec3 tmp;
//
//		tmp = set_vector(1, 0, 0);
		cam_rot_y(&rt->scene->cam, rt->scene->cam.rot_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		clear_window(rt);
//		raytrace(rt);
//		render_present(rt);
	}
	  if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_DOWN])
	  {
//		  t_vec3 tmp;
//
//		  tmp = set_vector(1, 0, 0);
		  cam_rot_y(&rt->scene->cam, -rt->scene->cam.rot_amt);
		  cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		  clear_window(rt);
//		  raytrace(rt);
//		  render_present(rt);
	  }
	  if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_LEFT])
	  {
//		  t_vec3 tmp;
//
//		  tmp = set_vector(0, 1, 0);
		  cam_rot_x(&rt->scene->cam, -rt->scene->cam.rot_amt);
		  cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		  clear_window(rt);
//		  raytrace(rt);
//		  render_present(rt);
	  }
	  if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_RIGHT])
	  {
//		  t_vec3 tmp;
//
//		  tmp = set_vector(0, 1, 0);
		  cam_rot_x(&rt->scene->cam, rt->scene->cam.rot_amt);
		  cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		  clear_window(rt);
//		  raytrace(rt);
//		  render_present(rt);
	  }
	  if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_Q])
	  {
//		  t_vec3 tmp;
//
//		  tmp = set_vector(0, 0, 1);
		  cam_rot_z(&rt->scene->cam, -rt->scene->cam.rot_amt);
		  cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		  clear_window(rt);
//		  raytrace(rt);
//		  render_present(rt);
	  }
	  if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_E])
	  {
//		  t_vec3 tmp;
//
//		  tmp = set_vector(0, 0, 1);
		  cam_rot_z(&rt->scene->cam, rt->scene->cam.rot_amt);
		  cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		  clear_window(rt);
//		  raytrace(rt);
//		  render_present(rt);
	  }
}
