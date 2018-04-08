/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:34:26 by vholovin          #+#    #+#             */
/*   Updated: 2018/04/03 14:34:51 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

/*
** sens		- horizontal/vertical sensitivity (x - horizontal);
** rpos		- relative x/y position of the mouse (delta);
** cam_sens	- horizontal/vertical sensitivity of the camera (x - horizontal);
*/
typedef struct	s_mouse
{
	t_vec2		sens;
	t_vec2		rpos;
	t_vec2		cam_sens;
}				t_mouse;

void			set_mouse_sens(t_mouse *m, float x, float y);
void			set_mouse_cam_sens(t_mouse *m, float x, float y);
void			get_mouse_relative_position(t_mouse *m);
void			invert_mouse_x(t_mouse *m);
void			invert_mouse_y(t_mouse *m);
void			clamp_mouse_rel_pos(t_mouse *m, float lower, float upper);
void			calc_mouse_rot_amt(t_mouse *m, t_cam *c);

#endif
