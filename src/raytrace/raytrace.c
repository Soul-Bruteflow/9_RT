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

#include "rtv.h"
#include "utility/defines.h"

static t_rgba	set_pixel_color(t_rtv *rtv)
{
	t_rgba color;

	color.red = (unsigned char)MIN(rtv->calc->color.red * 255.0f, 255.0f);
	color.green = (unsigned char)MIN(rtv->calc->color.green * 255.0f, 255.0f);
	color.blue = (unsigned char)MIN(rtv->calc->color.blue * 255.0f, 255.0f);
	color.alpha = SDL_ALPHA_OPAQUE;
	return (color);
}

static void		set_raytrace(t_rtv *r, Uint16 x, Uint16 y)
{
	t_vec3d xcomp;
	t_vec3d ycomp;
	t_cam	*c;

	c = &r->scene->cam;
	r->calc->level = 1;
	r->calc->coef = 1.0;
	r->calc->color.red = 0;
	r->calc->color.green = 0;
	r->calc->color.blue = 0;
	xcomp = vec3_scale(((x * c->s.pixel_width) - c->s.half_width), &c->right);
	ycomp = vec3_scale(((y * c->s.pixel_height) - c->s.half_height), &c->up);
	r->scene->ray.dir = vec3_norm(vec3_add3(c->dir, xcomp, ycomp));
}

static void		calculate_ray(t_rtv *rtv)
{
	t_calc		*c;
	t_scene		*s;

	c = rtv->calc;
	s = rtv->scene;
	while ((c->coef > 0.01f) && (c->level++ < 15))
	{
		c->cur_obj = -1;
		if (object_intersect(rtv, &s->ray, &c->cur_obj, &c->new_start) == false)
			break ;
		if (normal_of_intersect(&c->intersect_normal,
			&c->new_start, s->objects, c->cur_obj) == false)
			break ;
		c->material_n = s->objects[c->cur_obj]->material;
		c->cur_mat = *s->materials[s->objects[c->cur_obj]->material];
		calculate_light(rtv);
		calculate_reflection(rtv);
	}
}

void			raytrace(t_rtv *rtv)
{
	Uint16 x;
	Uint16 y;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			set_raytrace(rtv, x, y);
			calculate_ray(rtv);
			rtv->calc->pixel_color = set_pixel_color(rtv);
			ft_draw_pixel(x, y, &rtv->calc->pixel_color, rtv->win->draw_buf);
		}
	}
}
