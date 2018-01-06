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

static void		set_raytrace(t_rt *r, Uint16 x, Uint16 y)
{
	t_vec3 xcomp;
	t_vec3 ycomp;
	t_cam	*c;

	c = &r->scene->cam;
	r->calc->level = 1;
	r->calc->coef = 1.0;
	r->calc->color.red = 0;
	r->calc->color.green = 0;
	r->calc->color.blue = 0;
	xcomp = vec3_scale(((x * c->s.pixel_width) - c->s.half_width), &c->right);
	ycomp = vec3_scale(((y * c->s.pixel_height) - c->s.half_height), &c->up);
	r->scene->ray.dir = vec3_norm(vec3_add3(c->forward, xcomp, ycomp));
	r->scene->ray.start = r->scene->cam.pos;
	r->calc->old_start = r->scene->ray.start;
}

static void		calculate_ray(t_rt *rt)
{
	t_calc		*c;
	t_scene		*s;

	c = rt->calc;
	s = rt->scene;

	while (rt->calc->coef > 0.001 && c->level++ <= 1)
	{
		c->cur_obj = -1;
		if (object_intersect(rt, &s->ray, &c->cur_obj, &c->new_start) == false)
			break ;
		if (normal_of_intersect(&c->intersect_normal, &c->new_start, c->cur_obj, s) == false)
			break ;

		c->material_n = s->objects[c->cur_obj]->material;
		c->cur_mat = *s->materials[s->objects[c->cur_obj]->material];

		calculate_light(rt);
		if (rt->scene->lits_n == 0)
			calculate_reflection(rt);
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
			set_raytrace(rt, x, y);
			calculate_ray(rt);
			rt->calc->pixel_color = set_pixel_color(rt);
			ft_draw_pixel(x, y, &rt->calc->pixel_color, rt->win->draw_buf);
		}
	}
}