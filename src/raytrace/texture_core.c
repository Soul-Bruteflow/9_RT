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
	int   bpp;
	Uint8			*tex_buf;


	u = (1.0f + atan2f(r->scene->normal->z, r->scene->normal->x) / PI) * 0.5f * 1.0f;
	v = acosf(r->scene->normal->y) / PI * 1.0f;

	bpp = r->scene->objects[r->calc->cur_obj]->texture->format->BytesPerPixel;
	//bpp = 8;
	tex_buf = r->scene->objects[r->calc->cur_obj]->texture->pixels + 0 * r->scene->objects[r->calc->cur_obj]->texture->pitch + 0 * bpp;
	x = (int)((u * r->scene->objects[r->calc->cur_obj]->texture->w) + offset) % r->scene->objects[r->calc->cur_obj]->texture->w;
	y = (int)((v * r->scene->objects[r->calc->cur_obj]->texture->h) + offset) % r->scene->objects[r->calc->cur_obj]->texture->h;

	if (x >= 0 && x <= r->scene->objects[r->calc->cur_obj]->texture->w - 1 && y >= 0 && y <= r->scene->objects[r->calc->cur_obj]->texture->h - 1)
	{
		px_i = (unsigned int) ((r->scene->objects[r->calc->cur_obj]->texture->w * bpp * y) + x * bpp);
		tex_color.red = tex_buf[px_i + 2] / 255.0f;
		tex_color.green = tex_buf[px_i + 1] / 255.0f;
		tex_color.blue = tex_buf[px_i + 0] / 255.0f;
	}
	r->calc->color.red = tex_color.red;
	r->calc->color.green = tex_color.green;
	r->calc->color.blue = tex_color.blue;
}

void choose_color(t_rt *rt, float lambert)
{
	if (rt->scene->objects[rt->calc->cur_obj]->obj_type == sphere)
	{
		sphere_maping(rt);
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
