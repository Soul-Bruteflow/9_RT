#include "rt.h"

t_bool valid_texture(t_rt *r, SDL_Surface *t, int min, int max)
{
	if (!get_str(r))
		return (false);
	t = IMG_Load(r->pars->line);
	if(!t || t->w < min || t->h < min || t->w > max || t->h > max)
	{
		//printf("Bad. IMG_Load: %s\n", IMG_GetError());
		return (false);
	}
	//printf("Good.\n");
	return (true);
}