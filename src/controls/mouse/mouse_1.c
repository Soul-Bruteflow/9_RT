#include "rt.h"

void	set_mouse_sens(t_mouse *m, float x, float y)
{
	m->sens.x = x;
	m->sens.y = y;
}

void	set_mouse_cam_sens(t_mouse *m, float x, float y)
{
	m->cam_sens.x = x;
	m->cam_sens.y = y;
}

void	get_mouse_relative_position(t_mouse *m)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	SDL_GetRelativeMouseState(&x, &y);
	m->rpos.x = x;
	m->rpos.y = y;
//	printf("%f, %f\n", m->rpos.x, m->rpos.y);
}

void	invert_mouse_x(t_mouse *m)
{
	m->rpos.x *= -1.0f;
}

void	invert_mouse_y(t_mouse *m)
{
	m->rpos.y *= -1.0f;
}