#include "rt.h"

void	init_controls(t_rt *r)
{
	set_mouse_cam_sens(&r->sdl->mouse, H_C_SENS, V_C_SENS);
	set_mouse_sens(&r->sdl->mouse, H_SENS, V_SENS);
}