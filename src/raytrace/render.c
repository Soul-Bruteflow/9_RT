/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:20:40 by vholovin          #+#    #+#             */
/*   Updated: 2018/03/30 21:20:43 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
