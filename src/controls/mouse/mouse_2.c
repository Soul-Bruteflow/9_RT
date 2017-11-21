#include "rt.h"

void	get_mouse_relative_position(t_mouse *m)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	SDL_GetRelativeMouseState(&x, &y);
	m->rpos.x = x;
	m->rpos.y = y;
}

void    clamp_mouse_rel_pos(t_mouse *m, float lower, float upper)
{
	m->rpos.y = ft_clamp_f(m->rpos.y, lower, upper);
	m->rpos.x = ft_clamp_f(m->rpos.x, lower, upper);
}