/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:21:16 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:21:17 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_pixel_texture(t_rt *rt, int x, int y)
{
	Uint8		*tex_buf;
	Uint32		px_i;
	int			bpp;

	bpp = rt->calc->cur_mat.texture.map->format->BytesPerPixel;
	tex_buf = rt->calc->cur_mat.texture.map->pixels
		+ 0 * rt->calc->cur_mat.texture.map->pitch + 0 * bpp;
	if (x >= 0 && x <= rt->calc->cur_mat.texture.map->w - 1 && y >= 0
			&& y <= rt->calc->cur_mat.texture.map->h - 1)
	{
		px_i = (unsigned int)((rt->calc->cur_mat.texture.map->w * bpp * y)
			+ x * bpp);
		rt->calc->cur_mat.diffuse.alpha = tex_buf[px_i + 3] / 255.0f;
		rt->calc->cur_mat.diffuse.red = tex_buf[px_i + 2] / 255.0f;
		rt->calc->cur_mat.diffuse.green = tex_buf[px_i + 1] / 255.0f;
		rt->calc->cur_mat.diffuse.blue = tex_buf[px_i + 0] / 255.0f;
	}
}

void		calculate_texture(t_rt *rt)
{
	int x;
	int y;

	rt->calc->cur_mat = *rt->scene->materials[rt->scene->objects[
				rt->calc->cur_obj]->material];
	if (rt->scene->status_texture == true && rt->calc->cur_mat.texture.status)
	{
		if (rt->scene->objects[rt->calc->cur_obj]->obj_type == sphere)
			sphere_mapping(rt, &x, &y);
		if (rt->scene->objects[rt->calc->cur_obj]->obj_type == cylinder
		|| rt->scene->objects[rt->calc->cur_obj]->obj_type == cone
		|| rt->scene->objects[rt->calc->cur_obj]->obj_type == paraboloid)
			cylinder_mapping(rt, &x, &y);
		if (rt->scene->objects[rt->calc->cur_obj]->obj_type == plane
		|| rt->scene->objects[rt->calc->cur_obj]->obj_type == plane_limit
		|| rt->scene->objects[rt->calc->cur_obj]->obj_type == triangle
		|| rt->scene->objects[rt->calc->cur_obj]->obj_type == disc
		|| rt->scene->objects[rt->calc->cur_obj]->obj_type == ellipsoid
		|| rt->scene->objects[rt->calc->cur_obj]->obj_type == torus)
			planar_mapping(rt, &x, &y);
		set_pixel_texture(rt, x, y);
	}
}
