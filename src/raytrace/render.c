#include "rt.h"

/*
** Clears window, launches ray tracing routine and then renders it to the screen
*/
void	rt_render(t_rt *r)
{
	clear_window(r);
	pthreads(r);
	render_present(r);
}