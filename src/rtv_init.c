/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:44:50 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:07:55 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** type *pointer = malloc(num_elems * sizeof(*pointer));
*/

t_rtv	*rtv_init(char **av)
{
	t_rtv *rtv_tmp;

	rtv_tmp = malloc(sizeof(*(rtv_tmp)));
	if (rtv_tmp == NULL)
		rtv_error(malloc_error);
	rtv_tmp->sdl = malloc(sizeof(*(rtv_tmp->sdl)));
	if (rtv_tmp->sdl == NULL)
		rtv_error(malloc_error);
	rtv_tmp->win = malloc(sizeof(*(rtv_tmp->win)));
	if (rtv_tmp->sdl == NULL)
		rtv_error(malloc_error);
	rtv_tmp->calc = malloc(sizeof(*(rtv_tmp->calc)));
	if (rtv_tmp->calc == NULL)
		rtv_error(malloc_error);
	rtv_tmp->scene = malloc(sizeof(*(rtv_tmp->scene)));
	if (rtv_tmp->scene == NULL)
		rtv_error(malloc_error);
	rtv_tmp->pars = malloc(sizeof(*(rtv_tmp->pars)));
	if (rtv_tmp->pars == NULL)
		rtv_error(malloc_error);
	rtv_tmp->pars->av = av;
	rtv_tmp->win->draw_buf = NULL;
	rtv_tmp->win->pitch = WIDTH * BITS;
	rtv_tmp->win->offset = 0;
	return (rtv_tmp);
}
