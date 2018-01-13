/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:27:59 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_rgba	set_pixel_color(t_rt *rt)
{
	t_rgba color;

	color.red = (unsigned char)MIN(rt->calc->color.red * 255.0f, 255.0f);
	color.green = (unsigned char)MIN(rt->calc->color.green * 255.0f, 255.0f);
	color.blue = (unsigned char)MIN(rt->calc->color.blue * 255.0f, 255.0f);
	color.alpha = SDL_ALPHA_OPAQUE;
	return (color);
}

static void		set_ray(t_rt *rt, Uint16 x, Uint16 y)
{
	t_vec3	xcomp;
	t_vec3	ycomp;
	t_cam	*c;

	c = &rt->scene->cam;
	rt->calc->cur_power_ray = 1.0;
	rt->calc->level_reflection = 0;
	rt->calc->level_transparent = 0;

	//to add to keyboard for flag
	rt->calc->max_level_reflection = 10;
	rt->calc->max_level_transparent = 10;
	
	rt->calc->last_status_refract = false;

	xcomp = vec3_scale(((x * c->s.pixel_width) - c->s.half_width), &c->right);
	ycomp = vec3_scale(((y * c->s.pixel_height) - c->s.half_height), &c->up);
	rt->scene->ray.dir = vec3_norm(vec3_add3(c->forward, xcomp, ycomp));
	rt->scene->ray.pos = rt->scene->cam.pos;
}

void			calculate_ray(t_rt *rt)
{
	rt->calc->color.red = 0;
	rt->calc->color.green = 0;
	rt->calc->color.blue = 0;

	rt->calc->cur_obj = -1;

	if (rt->calc->cur_power_ray > 0.01f ||
		(rt->calc->level_reflection == rt->calc->max_level_reflection && rt->calc->level_transparent == rt->calc->max_level_transparent))
	{

		if (object_intersect(rt) == true && normal_of_intersect(rt, &rt->calc->intersect_normal) == true)
		{
			rt->calc->material_n = rt->scene->objects[rt->calc->cur_obj]->material;
			rt->calc->cur_mat = *rt->scene->materials[rt->scene->objects[rt->calc->cur_obj]->material];

			calculate_light(rt);
		
			if (rt->scene->lits_n != 0)
				calculate_reflect_refract(rt);				
		}
	}
}

void			raytrace(t_rt *rt)
{
	Uint16 x;
	Uint16 y;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			set_ray(rt, x, y);
			calculate_ray(rt);
			rt->calc->pixel_color = set_pixel_color(rt);
			ft_draw_pixel(x, y, &rt->calc->pixel_color, rt->win->draw_buf);
		}
	}
}