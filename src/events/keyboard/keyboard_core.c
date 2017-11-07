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
//		t_cylinder *c;
//		c = rt->scene->objects[0]->type;
//		c->a.x += 50;
//		c->b.x += 50;

//		float t = vec3_dot(&rt->scene->cam.dir, &rt->scene->cam.d);

//		t_vec3 tmp = vec3_scale(10, &rt->scene->cam.d);
//		rt->scene->cam.dir = vec3_add(&rt->scene->cam.dir, &tmp);
//		rt->scene->cam.d = vec3_norm(rt->scene->cam.dir);
//		rt->scene->cam.dir.z += 0.04;

//		position += direction * speed
//		rt->scene->cam.d.z

//		t_vec3 tmp = vec3_scale(rt->scene->cam.mov_amt, &rt->scene->cam.d);
//		rt->scene->cam.dir = vec3_add(&rt->scene->cam.dir, &tmp);

//		rt->scene->cam.pos.z += rt->scene->cam.mov_amt;

		cam_move(&rt->scene->cam, &rt->scene->cam.pos, &rt->scene->cam.dir, rt->scene->cam.mov_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		rt->scene->cam.d.z += rt->scene->cam.mov_amt;
//		init_camera(rt);
		printf("%f\n", rt->scene->cam.mov_amt);
//		printf("%f\n", rt->scene->cam.pos.y);
//		printf("%f\n", rt->scene->cam.pos.z);

		clear_window(rt);
		raytrace(rt);
		render_present(rt);
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_S])
	{
//		t_cylinder *c;
//		c = rt->scene->objects[0]->type;
//		c->a.x -= 50;
//		c->b.x -= 50;
		cam_move(&rt->scene->cam, &rt->scene->cam.pos, &rt->scene->cam.dir, -rt->scene->cam.mov_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);
//		rt->scene->cam.d = vec3_norm(rt->scene->cam.dir);
//		rt->scene->cam.dir.z -= 0.04;

		clear_window(rt);
		raytrace(rt);
		render_present(rt);
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_D])
	{
//		t_plane *p = rt->scene->objects[0]->type;
//		p->normal.x += 50;

		cam_move(&rt->scene->cam, &rt->scene->cam.pos, &rt->scene->cam.right, rt->scene->cam.mov_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		rt->scene->cam.dir.x -= rt->scene->cam.rot_amt;
//		vec3_norm(rt->scene->cam.dir);
//		cam_update(&rt->scene->cam, &rt->scene->ray.start);

		clear_window(rt);
		raytrace(rt);
		render_present(rt);
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_A])
	{
		cam_move(&rt->scene->cam, &rt->scene->cam.pos, &rt->scene->cam.right, -rt->scene->cam.mov_amt);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);

//		rt->scene->cam.dir.x += rt->scene->cam.rot_amt;
//		vec3_norm(rt->scene->cam.dir);
//		cam_update(&rt->scene->cam, &rt->scene->ray.start);
//		t_plane *p = rt->scene->objects[0]->type;
//		p->normal.x -= 50;

		clear_window(rt);
		raytrace(rt);
		render_present(rt);
	}
	if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_UP])
	{
//		printf("%f, %f, %f\n", rt->scene->cam.dir.x, rt->scene->cam.dir.y, rt->scene->cam.dir.z);
		cam_rot_y(&rt->scene->cam, rt->scene->cam.rot_amt);
//		printf("%f, %f, %f\n", rt->scene->cam.dir.x, rt->scene->cam.dir.y, rt->scene->cam.dir.z);

//		rt->scene->cam.dir = vec3_rotate(rt->scene->cam.rot_amt, &rt->scene->cam.dir);
//		rt->scene->cam.dir.x += rt->scene->cam.rot_amt;
//		vec3_norm(rt->scene->cam.dir);
		cam_update(&rt->scene->cam, &rt->scene->ray.start);
//		printf("%f, %f, %f\n", rt->scene->cam.dir.x, rt->scene->cam.dir.y, rt->scene->cam.dir.z);

		clear_window(rt);
		raytrace(rt);
		render_present(rt);
	}
	  if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_DOWN])
	  {
		  cam_rot_y(&rt->scene->cam, -rt->scene->cam.rot_amt);
//		rt->scene->cam.dir = vec3_rotate(rt->scene->cam.rot_amt, &rt->scene->cam.dir);
//		rt->scene->cam.dir.x += rt->scene->cam.rot_amt;
//		vec3_norm(rt->scene->cam.dir);
		  cam_update(&rt->scene->cam, &rt->scene->ray.start);

		  clear_window(rt);
		  raytrace(rt);
		  render_present(rt);
	  }
	  if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_LEFT])
	  {
		  cam_rot_x(&rt->scene->cam, -10);
//		rt->scene->cam.dir = vec3_rotate(rt->scene->cam.rot_amt, &rt->scene->cam.dir);
//		rt->scene->cam.dir.x += rt->scene->cam.rot_amt;
//		vec3_norm(rt->scene->cam.dir);
		  cam_update(&rt->scene->cam, &rt->scene->ray.start);

		  clear_window(rt);
		  raytrace(rt);
		  render_present(rt);
	  }
	  if (SDL_KEYDOWN && rt->sdl->key_state[SDL_SCANCODE_RIGHT])
	  {
		  cam_rot_x(&rt->scene->cam, -10);
//		rt->scene->cam.dir = vec3_rotate(rt->scene->cam.rot_amt, &rt->scene->cam.dir);
//		rt->scene->cam.dir.x += rt->scene->cam.rot_amt;
//		vec3_norm(rt->scene->cam.dir);
		  cam_update(&rt->scene->cam, &rt->scene->ray.start);

		  clear_window(rt);
		  raytrace(rt);
		  render_present(rt);
	  }
}
