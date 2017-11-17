#ifndef _CONTROLS_H
#define _CONTROLS_H

/*
** sens	- horizontal/vertical sensitivity (x - horizontal);
** rpos	- relative x/y position (delta);
*/
typedef struct	s_mouse
{
	t_vec2		sens;
	t_vec2		rpos;
}				t_mouse;

#endif
