#include "rt.h"

void	sphere_maping(t_rt *r)
{
	float u;
	float v;
	Uint32  px_i;
	t_rgbap tex_color;
	float x;
	float y;
	int offset = 20;
	Uint8   bpp;

	u = (1.0f + atan2f(r->scene->normal->z, r->scene->normal->x) / PI) * 0.5f * 1.0f;
	v = acosf(r->scene->normal->y) / PI * 1.0f;

	bpp = r->calc->tmp_surface.format->BytesPerPixel;
	r->tex_buf = r->calc->tmp_surface.pixels + 0 * r->calc->tmp_surface.pitch + 0 * bpp;
	x = (int)((u * r->calc->tmp_surface.w) + offset) % r->calc->tmp_surface.w;
	y = (int)((v * r->calc->tmp_surface.h) + offset) % r->calc->tmp_surface.h;

	if (x >= 0 && x <= r->calc->tmp_surface.w - 1 && y >= 0 && y <= r->calc->tmp_surface.h - 1)
	{
		px_i = (unsigned int) ((r->calc->tmp_surface.w * bpp * y) + x * bpp);
		tex_color.red = r->tex_buf[px_i + 2] / 255.0f;
		tex_color.green = r->tex_buf[px_i + 1] / 255.0f;
		tex_color.blue = r->tex_buf[px_i + 0] / 255.0f;
	}
	r->calc->color.red = tex_color.red;
	r->calc->color.green = tex_color.green;
	r->calc->color.blue = tex_color.blue;
}

void choose_color(t_rt *rt, float lambert)
{
	if (rt->scene->objects[rt->calc->cur_obj]->obj_type == sphere)
	{
		sphere_maping(rt;
	}
	else
	{
		rt->calc->color.red += (rt->calc->cur_mat.diffuse.red
		* rt->calc->light.red * lambert * rt->calc->shadow.red);
		rt->calc->color.green += (rt->calc->cur_mat.diffuse.green
		* rt->calc->light.green * lambert * rt->calc->shadow.green);
		rt->calc->color.blue += (rt->calc->cur_mat.diffuse.blue
		* rt->calc->light.blue * lambert * rt->calc->shadow.blue);
	}

}
